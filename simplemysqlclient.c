#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <mysql.h>

int main(void)
{
  if (mysql_library_init(0, NULL, NULL))
    {
      fprintf(stderr, "could not initialize MySQL client library\n");
      exit(1);
    }
  else
    fprintf(stdout, "MySQL client library initialized!\n");

  MYSQL mysql_hdl;
  mysql_init(&mysql_hdl);
  if (!mysql_real_connect(&mysql_hdl,
                          "localhost", /* host */
                          "root", "",  /* user & pwd */
                          "dst",       /* database */
                          0,           /* port */
                          NULL,        /* unix socket */
                          0            /* client flag */
                          ))
    {
      fprintf(stderr,
              "Failed to connect to database: Error: %s\n",
              mysql_error(&mysql_hdl));
    }
  else
    fprintf(stdout, "Connection successful!\n");

  /*
   * First statement: count rows in customer table
   */
  MYSQL_STMT *stmt = mysql_stmt_init(&mysql_hdl);
  MYSQL_BIND bind;
  unsigned long rows;
  my_bool error;

  char* stmtstr = "select COUNT(*) from customer";
  mysql_stmt_prepare(stmt, stmtstr, strlen(stmtstr));
  mysql_stmt_execute(stmt);

  memset(&bind, 0, sizeof(bind));
  bind.buffer_type = MYSQL_TYPE_LONG;
  bind.buffer = (unsigned long*)&rows;
  bind.error = &error; 
  
  mysql_stmt_bind_result(stmt, &bind);
  
  mysql_stmt_fetch(stmt);
  
  fprintf(stdout, "Number of lines in customer table = %ld\n", rows);

  mysql_stmt_close(stmt);

  /*
   * Second statement: select a customer with zipcode 85600
   */
  MYSQL_STMT *stmt2 = mysql_stmt_init(&mysql_hdl);
  MYSQL_BIND bind2[5];
  struct customer_st {
    char lastname[100];
    char firstname[100];
    char city[100];
    unsigned long zipcode;
    unsigned int active;    
  } customer;

  char* stmt2str = "SELECT lastname, firstname, city, zipcode, active FROM customer WHERE zipcode = 85600";
  mysql_stmt_prepare(stmt2, stmt2str, strlen(stmt2str));
  mysql_stmt_execute(stmt2);

  MYSQL_RES* prepare_meta_result = mysql_stmt_result_metadata(stmt2);
  if (!prepare_meta_result)
    {
      fprintf(stderr,
              " mysql_stmt_result_metadata(), returned no meta information\n");
      fprintf(stderr, " %s\n", mysql_stmt_error(stmt2));
      exit(0);
    }

  /* Get total columns in the query */
  int column_count = mysql_num_fields(prepare_meta_result);
  fprintf(stdout,
          " total columns in SELECT statement: %d\n",
          column_count);
  
  if (column_count != 5) /* validate column count */
    {
      fprintf(stderr, " invalid column count returned by MySQL\n");
      exit(0);
    }
  
  memset(&bind2, 0, sizeof(bind2));

  bind2[0].buffer_type = MYSQL_TYPE_STRING;
  bind2[0].buffer = &customer.lastname;
  bind2[0].error = &error;

  bind2[1].buffer_type = MYSQL_TYPE_STRING;
  bind2[1].buffer = &customer.firstname;
  bind2[1].error = &error;

  bind2[2].buffer_type = MYSQL_TYPE_STRING;
  bind2[2].buffer = &customer.city;
  bind2[2].error = &error;

  bind2[3].buffer_type = MYSQL_TYPE_LONG;
  bind2[3].buffer = &customer.zipcode;
  bind2[3].error = &error;

  bind2[4].buffer_type = MYSQL_TYPE_SHORT;
  bind2[4].buffer = &customer.active;
  bind2[4].error = &error;

  mysql_stmt_bind_result(stmt2, bind2);
  
  mysql_stmt_fetch(stmt2);

  fprintf(stdout, "Customer = %s, %s, %s, %ld, %u\n", customer.firstname, customer.lastname, customer.city, customer.zipcode, customer.active);

  mysql_stmt_close(stmt2);

  /*
   * Disconnect & terminate
   */
  mysql_close(&mysql_hdl);
  mysql_library_end();

  return EXIT_SUCCESS;
}

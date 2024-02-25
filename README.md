# simplemysqlclient

Add user in mysql:
```bash
 $ sudo mysql
Server version: 10.6.16-MariaDB-0ubuntu0.22.04.1 Ubuntu 22.04

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> CREATE USER 'rcoscali'@'localhost' IDENTIFIED BY 'password';
Query OK, 0 rows affected (0,260 sec)

MariaDB [(none)]> GRANT ALL PRIVILEGES ON *.* TO 'rcoscali'@'localhost' WITH GRANT OPTION;
Query OK, 0 rows affected (0,084 sec)

MariaDB [(none)]> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0,001 sec)

MariaDB [(none)]> ^DBye
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ 
```

Then:
```bash
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ mysql -u rcoscali -p dst
Enter password: 
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 77
Server version: 10.6.16-MariaDB-0ubuntu0.22.04.1 Ubuntu 22.04

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [dst]> ^DBye
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ 
```

Build and run simple client
```bash
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ make
gcc -o simplemysqlclient `pkg-config --cflags mysqlclient` simplemysqlclient.c `pkg-config --libs mysqlclient`
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ ./simplemysqlclient 
MySQL client library initialized!
Connection successful!
Number of lines in customer table = 6919
total columns in SELECT statement: 5
+===============================+================================+==============+==========+
| SELECT lastname, firstname, city, zipcode, active FROM customer WHERE firstname='Lisa' ORDER BY zipcode
+===============================+================================+==============+==========+
|name:Lisa  DAL MORO    	|city:LA NEUVILLE BOSMONT        |zipcode: 2250	|active:YES|
|name:Lisa  JEANNINGROS 	|city:COINGT                     |zipcode: 2360	|active:YES|
|name:Lisa  LAPOILE     	|city:LAPRUGNE                   |zipcode: 3250	|active:YES|
|name:Lisa  DUCOS       	|city:CLAVY WARBY                |zipcode: 8460	|active:YES|
|name:Lisa  CHIRON      	|city:ST MICHEL                  |zipcode: 9100	|active:YES|
|name:Lisa  FONCY       	|city:BOUAN                      |zipcode: 9310	|active:YES|
|name:Lisa  DESECURES   	|city:ESTISSAC                   |zipcode:10190	|active:YES|
|name:Lisa  GIRAUDON    	|city:COURSEULLES SUR MER        |zipcode:14470	|active:YES|
|name:Lisa  GINISTY     	|city:NERONDES                   |zipcode:18350	|active:YES|
|name:Lisa  SAINT MARTIN	|city:ST PARDOUX L ORTIGIER      |zipcode:19270	|active:YES|
|name:Lisa  LECUYER     	|city:GRISELLES                  |zipcode:21330	|active:YES|
|name:Lisa  LE TIEC     	|city:BASSILLAC ET AUBEROCHE     |zipcode:24640	|active:YES|
|name:Lisa  GUIBERT     	|city:BESANCON                   |zipcode:25000	|active:YES|
|name:Lisa  PINEAU      	|city:PIERREFONTAINE LES BLAMONT |zipcode:25310	|active:YES|
|name:Lisa  NACCACHE    	|city:GONSANS                    |zipcode:25360	|active:YES|
|name:Lisa  SOBIERAJ    	|city:URTIERE                    |zipcode:25470	|active:YES|
|name:Lisa  TAVET       	|city:FLOURENS                   |zipcode:31130	|active:YES|
|name:Lisa  LAFFORGUE   	|city:SORBETS                    |zipcode:32110	|active:YES|
|name:Lisa  VASSEUR     	|city:VAL DE VIRVEE              |zipcode:33240	|active:YES|
|name:Lisa  BARBARY     	|city:MONTROND                   |zipcode:39300	|active:YES|
|name:Lisa  PONT        	|city:MACORNAY                   |zipcode:39570	|active:YES|
|name:Lisa  CHAPEL      	|city:AZUR                       |zipcode:40140	|active:YES|
|name:Lisa  HOFFNER     	|city:FORCEY                     |zipcode:52700	|active:YES|
|name:Lisa  TOUZALIN    	|city:ROZELIEURES                |zipcode:54290	|active:YES|
|name:Lisa  MOTTARD     	|city:NOSTANG                    |zipcode:56690	|active:YES|
|name:Lisa  BARIOU      	|city:LOMMERANGE                 |zipcode:57650	|active:YES|
|name:Lisa  COQUISART   	|city:TINTURY                    |zipcode:58110	|active:YES|
|name:Lisa  BOURDON     	|city:LA VILLENEUVE SOUS THURY   |zipcode:60890	|active:YES|
|name:Lisa  DELPY       	|city:BEAUVALLON                 |zipcode:69700	|active:YES|
|name:Lisa  DALLEAU     	|city:BRETTE LES PINS            |zipcode:72250	|active:YES|
|name:Lisa  HENRY       	|city:USINENS                    |zipcode:74910	|active:YES|
|name:Lisa  MARQUAND    	|city:MOTTEVILLE                 |zipcode:76970	|active:YES|
|name:Lisa  LAHEY       	|city:CHEY                       |zipcode:79120	|active:YES|
|name:Lisa  ENAUX       	|city:BIOULE                     |zipcode:82800	|active:YES|
|name:Lisa  RIERA       	|city:BELEP                      |zipcode:98811	|active:YES|
+===============================+================================+==============+==========+
Connection closed!
Library terminated!
rcoscali@Ubuntu-22:~/Sources/simplemysqlclient$ 
```


PROG = simplemysqlclient
SRC = simplemysqlclient.c

.PHONY: clean

$(PROG): $(SRC)
	gcc -o $@ `pkg-config --cflags mysqlclient` $< `pkg-config --libs mysqlclient`

clean:
	rm -f $(PROG) *.o *~ 

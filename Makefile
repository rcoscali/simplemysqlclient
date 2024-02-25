PROG = simpleclient
SRC = simpleclient.c

.PHONY: clean

$(PROG): $(SRC)
	gcc -o simpleclient `pkg-config --cflags mysqlclient` simpleclient.c `pkg-config --libs mysqlclient`

clean:
	rm -f $(PROG) *.o *~ 

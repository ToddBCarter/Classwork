# Makefile for Assignment 3
#
# Todd Carter - CS270
# cart7982@vandals.uidaho.edu
# 11-14-2023
#
# For practice, this makefile will produce object files before compiling,
# instead of just linking immediately.


#Server build
testserver: testserver.o
	@gcc testserver.o -o testserver
	@echo "Server compiled."

testserver.o: testserver.c
	@gcc -c testserver.c


#Client build
testclient: testclient.o
	@gcc testclient.o -o testclient
	@echo "Client compiled."

testclient.o: testclient.c
	@gcc -c testclient.c

clean:
	@rm testclient.o testserver.o
	@echo "Object files removed."

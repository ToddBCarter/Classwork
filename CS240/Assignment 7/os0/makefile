CC = gcc 
CFLAGS = 

OBJECTS = os0main.o os0.o hardware0.o 

os0run : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lm -o os0run

$(OBJECTS) : os0main.h hardware0.h

os0main.o: os0main.c
	$(CC) -c os0main.c

os0.o: os0.c
	$(CC) -c os0.c

hardware0.o: hardware0.c
	$(CC) -c hardware0.c

clean :
	/bin/rm -f $(OBJECTS) os0run core 

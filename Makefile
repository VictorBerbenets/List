CC = g++

CFLAGS =-c -g -Wall -Wextra 

all : List

List : list_functions.o  main.o 
	$(CC) list_functions.o main.o  -o List

list_functions.o : list_functions.cpp
	$(CC) $(CFLAGS) $^
	
main.o : main.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o List

rebuild: clean all
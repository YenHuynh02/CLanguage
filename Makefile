CF = gcc
CC = -g -ansi -pedantic -Wall

assign2: main.o students.o
	$(CF) $(CC)	$^ -o $@

main.o: main.c students.h
	$(CF) $(CC) -c $< -o $@

students.o: students.c students.h
	$(CF) $(CC) -c $< -o $@

clean:
	rm -f *.o assign2

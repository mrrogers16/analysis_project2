CC = gcc
CFLAGS = -Wall

OBJ = main.o generate_data.o sorting_algorithms.o

all: project2

project2: $(OBJ)
	$(CC) $(CFLAGS) -o project2 $(OBJ)

main.o: main.c sorting.h
	$(CC) $(CFLAGS) -c main.c 

generate_data.o: generate_data.c sorting.h
	$(CC) $(CFLAGS) -c generate_data.c

sorting_algorithms.o: sorting_algorithms.c sorting.h
	$(CC) $(CFLAGS) -c sorting_algorithms.c 

clean:
	rm -f *.o project2
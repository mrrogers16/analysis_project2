CC = gcc
CFLAGS = -Wall -std=c99

OBJ = main.o generate_data.o sorting.o

all: project2

project2: $(OBJ)
	$(CC) $(CFLAGS) -o project2 $(OBJ)

main.o: main.c sorting.h
	$(CC) $(CFLAGS) -c main.c 

generate_data.o: generate_data.c sorting.h
	$(CC) $(CFLAGS) -c generate_data.c

sorting.o: sorting.c sorting.h
	$(CC) $(CFLAGS) -c sorting.c 

clean:
	rm -f *.o project2
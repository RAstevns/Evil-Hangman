CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS= main.o my_string.o
TESTS= unit_test.o test_def.o my_string.o


unit_test: $(TESTS)
	$(CC) $(CFLAGS) -o unit_test $(TESTS) 
string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
my_string.o: my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o	
clean:
	rm string_driver $(OBJECTS) unit_test $(TESTS)

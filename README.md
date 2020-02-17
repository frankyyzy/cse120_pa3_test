# cse120_pa3_test

add the following to Make file:
test:	pa3d test.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o test test.c mycode3.o

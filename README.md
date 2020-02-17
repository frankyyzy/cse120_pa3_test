# cse120_pa3_test

This repository contains 2 files: test.c and runforever.sh.

**test.c** is a compilation of test from discussion and piazza that I personally think are worth sharing. It also includes the expected behavior. Some tricky test cases in my opinion are **test 8** and **test 5** which requires special handling of the edge cases in my implementation.

**runforever.sh** runs all the test in test.c repeatly until a counter count is reached. It also repeatly checks for allocation of CPU on ieng6 by grepping from the balance and breaks if the allocation is below a certain threshold. Use with caution. 

To run the test:

1. add the following to Make file:
```
test:	pa3d test.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o test test.c mycode3.o
```
2. edit runforever.sh to your desired count number and threshold
3. ./runforever.sh  
   1. you may redirect the output to a different file and grep for keywords like "kernal panic" or crash.

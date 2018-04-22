/*
 * vaddr.c
 *
 *  Created on: Apr 22, 2018
 *      Author: Daniel Waters
 *      CSUID : 692
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isDecimal(char*[]);

int main(int argc, char* argv[]) {

	// check if given 3 arguments (1 being the name of the program ./vaddr)
	// also checks if the arguments are digits
	if (argc != 3 || !isDecimal(argv)) {
		fprintf(stderr, "Expecting 2 arguments: Page Size and Virtual Address arguments (in decimal format).\nPlease try again.\n");
		exit(1);
	}

	// calculate the page size by multiplying N-KB page size
	// by 1024 (1KB = 1024 bytes)
	int pageSize = atoi(argv[1]) * 1024;

	// convert the String to an int value
	int virtualAddress = atoi(argv[2]);

	// get the page number by just dividing the VA by page size
	// in bytes, since we are given virtual address in bytes
	int pageNumber = virtualAddress / pageSize;

	// get the offset by virtualAddress mod pageSize (in byes);
	int offset = virtualAddress % pageSize;

	// print out calculated values
	printf("\nVirtual address translation by Daniel Waters 692\n");
	printf("Page size = %d, virtual address %d => page number = %d, offset = %d\n\n", pageSize, virtualAddress, pageNumber, offset);
}

// step through the char array and verify that
// each character is a digit
// isdigit() returns 0 if the value is not a digit
// 0 is considered false in C, so need to do !
int isDecimal(char* arguments[]) {
	for (int i = 0; i < strlen(arguments[1]); i++) {
		if (!isdigit(arguments[1][i])) {
			return 0;
		}
	}

	for (int i = 0; i < strlen(arguments[2]); i++) {
		if (!isdigit(arguments[2][i])) {
			return 0;
		}
	}
	return 1;
}

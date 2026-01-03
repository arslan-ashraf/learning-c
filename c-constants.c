#include <stdio.h>

int main(){


	// if the varible is constant, then const in needed in front of the pointer
	const int constant_variable = 4;
	const int *ptr_constant_variable = &constant_variable;

	printf("pointer derefenced: %d\n", *ptr_constant_variable);

	// when const is to the very left of the pointer, the constant is the value
	// that the pointer is pointing to (read right to left), so this won't compile:
	// *ptr_constant_variable = 1;

	// but the pointer itself is not constant, so it can point to a different variable
	int y = 9;
	ptr_constant_variable = &y;
	
	printf("pointer derefenced: %d\n", *ptr_constant_variable);
	
	return 0;
}
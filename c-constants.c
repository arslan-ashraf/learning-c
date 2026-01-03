#include <stdio.h>
#include <string.h>

int main(){

	////////////////////////////////////////////////////////////////////////////
	////////////////////////// Start - Constant Value //////////////////////////
	////////////////////////////////////////////////////////////////////////////

	// if the varible is constant, then const in needed in front of the pointer
	// pointers should be read right to left, so the pointer declared below is:
	// pointer of type int pointing to a constant value

	const int constant_variable = 4;
	const int *ptr_constant_variable = &constant_variable;

	printf("constant value, pointer derefenced: %d\n", *ptr_constant_variable);

	// when const is to the very left of the pointer, the constant is the value
	// that the pointer is pointing to, so this won't compile:
	// *ptr_constant_variable = 1;

	// but the pointer itself is not constant, so it can point to a different variable
	int nine = 9;
	ptr_constant_variable = &nine;

	printf("constant value, pointer derefenced: %d\n", *ptr_constant_variable);

	// this also throws a compiler error, even though nine is not constant
	// the pointer says that it should be
	// *ptr_constant_variable = 1;

	////////////////////////////////////////////////////////////////////////////
	/////////////////////////// End - Constant Value ///////////////////////////
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	///////////////////////// Start - Constant Pointer /////////////////////////
	////////////////////////////////////////////////////////////////////////////

	// reading right to left, pointer constant (or constant pointer) of type int
	int number = 5;
	int const *constant_pointer = &number;

	printf("constant pointer, pointer derefenced: %d\n", *constant_pointer);

	// this throws a compiler error, because the constant is the pointer
	// the pointer cannot point to anything other than its initial address
	// int x = 0;
	// *constant_pointer = &x;

	// however, we can change the original variable
	number = 10;
	printf("constant pointer, pointer derefenced: %d\n", *constant_pointer);

	// directly changing the underlying value also throws an error
	// *constant_pointer = 0;

	////////////////////////////////////////////////////////////////////////////
	////////////////////////// End - Constant Pointer //////////////////////////
	////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////
	///////////////////////// Start - Constant Structs /////////////////////////
	////////////////////////////////////////////////////////////////////////////


	typedef struct student_t {
		char name[10];
		float gpa;
		const char subject[]; // flexible array must be at the end of struct
		// const char *subject; // also valid and can be any where in the struct
	} student_t;

	student_t *s;
	strcpy(s->name, "Arslan");
	s->gpa = 4.0;
	// strcpy(s->subject, "maths");
	printf("%s\n", s->subject);

	////////////////////////////////////////////////////////////////////////////
	////////////////////////// End - Constant Structs //////////////////////////
	////////////////////////////////////////////////////////////////////////////
	
	return 0;
}
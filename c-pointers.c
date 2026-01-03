#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_function(int x, int y){
	int c = x + y;
	return c;
}

int callback_test(int x){
	printf("value of x before being incremented, printed inside callback_test() function: %d\n", x);
	x += 1;
	return x;
}

void some_function(int (*pointer_callback_test)(int), int a){
	int b = pointer_callback_test(a);
	printf("value of x (now called b) after it is incremented, printed inside some_function(): %d\n", b);
}

typedef struct student_t {
	char name[10];
	float gpa;
} student_t;

student_t *modify_student(student_t *s){
	s->gpa = 4.1;
	return s;
}

// the input argument can also be written as (int *arr)
void print_one_d_array(int arr[]){
	printf("reading 1-D array: ");
	for (int i = 0; i < 3; i++){
		// printf("%d ", *(arr + i));  // same as line below
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]){


	printf("////////////////////////// Start - 1-D Array //////////////////////////\n");
	
	int one_d_array[] = { 1, 6, 0 };

	// multiple ways of an address of 1-d array
	printf("address of 1-d array %d = %d\n", one_d_array, &one_d_array[0]);
	print_one_d_array(one_d_array);

	// above print statements print the following:
	// address of 1-d array 1627389244 = 1627389244
	// reading 1-D array: 1 6 0

	printf("/////////////////////////// End - 1-D Array ///////////////////////////\n\n");

	

	///////////////////////////////////////////////////////////////////////
	////////////////////////// Start - 2-D Array //////////////////////////
	///////////////////////////////////////////////////////////////////////

	printf("////////////////////////// Start - 2-D Array //////////////////////////\n");

	int two_d_array[][3] = { 
		{ 6, 3, 8 }, 
		{ 3, 9, 7 } 
	};

	// correct way of assigning a pointer to 2-d array
	int (*p_2d)[3] = two_d_array;
	// now p_2d and two_d_array can be used interchangeably

	// the syntax "int (*p_2d)[3]" means that the pointer p_2d is still only one variable, 
	// of typical size (8 bytes), but the unit jump of this pointer variable p_2d is 
	// sizeof(int) * num_in_straight_brackets
	// sizeof(int) = 4, num_in_straight_brackets = 3, so unit jump of p_2d = 12 = 4 * 3
	// the value of p_2d is an address, if p_2d = 6, then after a unit jump of p_2d is (p_2d + 1) = 18
	// notice that while p_2d, p_2d[0], and *p_2d all print the same address
	// these variables are not the same, p_2d has a unit jump of sizeof(int) * num_in_straight_brackets
	// while p_2d[0] and *p_2d are the same and have a jump of sizeof(int)
	printf("p_2d: address of first subarray using pointer  -> %d = %d = %d\n", p_2d, p_2d[0], *p_2d);
	// below printed address should be 12 more than above printed address
	printf("p_2d: address of second subarray using pointer -> %d = %d\n", (p_2d + 1), p_2d[1]);
	printf("p_2d: element at two_d_array[1][0] using pointer   -> %d = %d = %d\n", *(*(p_2d + 1) + 0), *p_2d[1], p_2d[1][0]);
	
	// multiple ways of an address of 2-d array
	// the name of a 2-d array returns a pointer to an array of pointers 
	// of the second dimension, here two_d_array -> int (*p)[3]
	printf("address of 2-d array using 2-D array name %d = %d = %d = %d = %d = %d = %d = %d\n", 
		   two_d_array,						// -> int (*p_2d)[3]
		   *two_d_array,					// -> p_2d[0] which is address of first element
		   two_d_array[0], 					// -> p_2d[0] same as above
		   &two_d_array[0],					// -> base address of first inner array
		   &two_d_array[0][0],				// -> addres of first element in 2-d array
		   (two_d_array + 0),				// -> pointer arithmetic, same as two_d_array[0]
		   *(two_d_array + 0),				// -> same as line above
		   (*(two_d_array + 0)) + 0);		// -> same as line above

	// the addresses below should be 12 more than above line
	// if the base address of 2-d array is x, then address below should be
	// x + (sizeof(int) * num_elements_in_second_dim) = x + (4 * 3) = x + 12
	printf("address of second subarray of a 2-d array %d = %d (+ 4) = %d -> %d\n", 
		   (two_d_array + 1),				// -> pointer arithmetic, base_address + (sizeof(int) * num_elements_in_second_dim)
		   *(two_d_array + 1),				// -> same as line above and p_2d[1]
		   (*(two_d_array + 1)) + 1,		// -> address of arr[1][1]
		   *(  *(two_d_array + 1)   + 1));	// -> element at arr[1][1]

	// *(*(two_d_array + i) + j) == *(two_d_array[i] + j) == two_d_array[i][j]
	// two_d_array returns a pointer whose unit jump is sizeof(int) * num_in_straight_bracks
	// the number i = sizeof(int) * num_in_straight_bracks
	// *(two_d_array + i), dereferencing once returns a pointer of type int *p
	// and it returns a pointer whose unit jump is sizeof(int) because the pointer if int *p
	// in the expression *(two_d_array + i) + j, the number j = sizeof(int)
	// dereferencing twice *(*(two_d_array + i) + j) returns element at two_d_array[i][j]

	// above print statements print the following:
	// p_2d: address of first subarray using pointer  -> 1627389216 = 1627389216 = 1627389216
	// p_2d: address of second subarray using pointer -> 1627389228 = 1627389228
	// p_2d: element at two_d_array[1][0] using pointer   -> 3 = 3 = 3
	// address of 2-d array using 2-D array name 1627389216 = 1627389216 = 1627389216 = 1627389216 = 1627389216 = 1627389216 = 1627389216 = 1627389216
	// address of second subarray of a 2-d array 1627389228 = 1627389228 (+ 4) = 1627389232 -> 9

	printf("/////////////////////////// End - 2-D Array ///////////////////////////\n\n");

	///////////////////////////////////////////////////////////////////////
	/////////////////////////// End - 2-D Array ///////////////////////////
	///////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////
	////////////////////////// Start - 3-D Array //////////////////////////
	///////////////////////////////////////////////////////////////////////

	printf("////////////////////////// Start - 3-D Array //////////////////////////\n");

	// tensor of dimensions 2 x 3 x 4
	int three_d_array[][3][4] = { 
		{ { 6, 3, 8, 1 }, 
		  { 3, 9, 7, 0 },
		  { 1, 3, 6, 9 }  }, 

		{ { 1, 4, 0, 6 }, 
		  { 2, 5, 3, 9 },
		  { 1, 2, 3, 4 }  }
	};

	// correct way of assigning a pointer to 3-d array
	int (*p_3d)[3][4] = three_d_array;
	// now p_3d and three_d_array can be used interchangeably

	// the syntax "int (*p_3d)[3][4]" means that the pointer p_3d is still only
	// one variable, but the unit jump of that variable is 
	// sizeof(int) * first_num_in_straight_brackets * second_num_in_straight_brackets
	// sizeof(int) = 4, first_num_in_straight_brackets = 3, second_num_in_straight_brackets = 4
	// so size of p_3d = 4 * (3 * 4) = 48
	// the value of p_2d is an address, if p_3d = 6, then a unit jump of p_3d is (p_3d + 1) = 54
	printf("p_3d: address of first  submatrix using pointer -> %d = %d = %d = %d\n", p_3d, p_3d[0], *p_3d, **p_3d);
	// below printed address should be 48 more than above printed address
	printf("p_3d: address of second submatrix using pointer -> %d = %d = %d = %d\n", (p_3d + 1), *(p_3d + 1), p_3d[1], *p_3d[1]);
	// more ways to get the address but these ways are not all the same
	printf("p_3d: address of second submatrix using pointer -> %d = %d = %d = %d\n", *(p_3d + 1) + 0, *(*(p_3d + 1) + 0), *p_3d[1], p_3d[1][0]);
	// note that (p_3d + 1), *(p_3d + 1), p_3d[1], *p_3d[1], *(p_3d + 1) + 0, 
	// *(*(p_3d + 1) + 0), *p_3d[1], p_3d[1][0] may all be giving the same address,
	// they are all not the same, dereferencing with * or with [i], [i][j]
	// is changing the unit jump size of the pointer p_3d

	// however, if pointer p_3d is dereferenced once like: *(p_3d + i), its next 
	// unit jump is sizeof(int) * second_num_in_straight_brackets = 4 * 4 = 16
	// with syntax (*(p_3d + 1) + 2), should add 32 to the address of second submatrix
	// and it should add 80 = 48 + 32 to the address of the first submatrix
	// since p_3d's value is an address, say x, if p_3d = x, then (p_3d + 1) = x + 48
	// dereferencing *(p_3d + 1) changes the pointer's unit jump size to 
	// sizeof(int) * second_num_instraight_brackets, *(p_3d + 1) + 2 = x + 48 + 32 = x + 80
	// dereferencing again *(*(p_3d + 1) + 2) doesn't change the address but it does
	// change the pointer's unit jump size to sizeof(int)
	printf("p_3d: address of third subarray of the second submatrix using pointer -> %d = %d = %d = %d\n", 
		 (*(p_3d + 1) + 2),
		*(*(p_3d + 1) + 2),
		*(p_3d[1] + 2),
		p_3d[1][2]
	);

	//     *(three_d_array + i) 		  ==     three_d_array[i]
	//   *(*(three_d_array + i) + j) 	  ==   *(three_d_array[i] + j) 		==   three_d_array[i][j]
	// *(*(*(three_d_array + i) + j) + k) == *(*(three_d_array[i] + j) + k) == *(three_d_array[i][j] + k) == three_d_array[i][j][k]

	printf("/////////////////////////// End - 3-D Array ///////////////////////////\n\n");

	// above print statements print the following:
	// p_3d: address of first  submatrix using pointer -> 1627389120 = 1627389120 = 1627389120 = 1627389120
	// p_3d: address of second submatrix using pointer -> 1627389168 = 1627389168 = 1627389168 = 1627389168
	// p_3d: address of second submatrix using pointer -> 1627389168 = 1627389168 = 1627389168 = 1627389168
	// p_3d: address of third subarray of the second submatrix using pointer -> 1627389200 = 1627389200 = 1627389200 = 162738920

	///////////////////////////////////////////////////////////////////////
	/////////////////////////// End - 3-D Array ///////////////////////////
	///////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////
	///////////// Start - Callbacks and Pointers to Functions /////////////
	///////////////////////////////////////////////////////////////////////

	printf("///////////// Start - Callbacks and Pointers to Functions /////////////\n");

	// int add_function(int x, int y){ ... } is an ordinary function
	// there are two ways to reference a function
	// first way, the function name itself returns the function's first instruction address
	int (*p)(int, int) = add_function;
	// another way of referencing a pointer to the function's first instruction using &
	// int (*p)(int, int) = &add_function;

	// also two ways to dereference pointer to function
	// int z = p(3, 4);
	int z = (*p)(3, 4);
	printf("value of z: %d\n", z);


	// passing in a callback function pointer to another function called some_function
	int (*pointer_to_function)(int) = callback_test;
	// int (*pointer_to_function)(int) = &callback_test; // another way

	some_function(pointer_to_function, 5);

	printf("////////////// End - Callbacks and Pointers to Functions //////////////\n\n");

	// above print statements print the following:
	// value of z: 7
	// value of x before being incremented, printed inside callback_test() function: 5
	// value of x (now called b) after it is incremented, printed inside some_function(): 6

	///////////////////////////////////////////////////////////////////////
	////////////// End - Callbacks and Pointers to Functions //////////////
	///////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////
	///////////////////// Start - Pointers to Structs /////////////////////
	///////////////////////////////////////////////////////////////////////

	printf("///////////////////// Start - Pointers to Structs /////////////////////\n");

	// note: the size of a struct is not simply the sum of its members, this is 
	// due to padding for efficiency of storage (e.g., 14 bytes rounded up to 16 bytes)
	// the size of the struct may also be different depending on the compiler and computer architecture
	printf("size (in bytes) of student_t: %d\n", sizeof(student_t));
	student_t *s = (student_t *)malloc(sizeof(student_t));
	strcpy(s->name, "Arslan");
	s->gpa = 4.0;

	printf("before modification: student name: %s\n", s->name);
	printf("before modification: student  gpa: %f\n", s->gpa);

	student_t *s1 = modify_student(s);
	// s and s1 both point to the same memory location
	printf("address of  s->name: %d\n", &s->name);
	printf("address of s1->name: %d\n", &s1->name);

	// two ways to access a local pointer
	printf("after modification:  student name: %s\n", (*s1).name);
	printf("after modification:  student  gpa: %f\n", s1->gpa);

	s1->gpa = 4.11;
	printf("student s  gpa: %f\n", s->gpa);
	printf("student s1 gpa: %f\n", s1->gpa);

	free(s);

	printf("////////////////////// End - Pointers to Structs //////////////////////\n\n");

	// above print statements print the following:
	// size (in bytes) of student_t: 16
	// before modification: student name: Arslan
	// before modification: student  gpa: 4.000000
	// address of  s->name: 1715338816
	// address of s1->name: 1715338816
	// after modification:  student name: Arslan
	// after modification:  student  gpa: 4.100000
	// student s  gpa: 4.110000
	// student s1 gpa: 4.110000

	///////////////////////////////////////////////////////////////////////
	////////////////////// End - Pointers to Structs //////////////////////
	///////////////////////////////////////////////////////////////////////

	return 0;
}
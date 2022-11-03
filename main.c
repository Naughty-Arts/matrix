#include <stdio.h>

#include "matrix.h"

int main()
{
	printf("------------------- Matrix -------------------\n\n");

	Matrix* base1 = matrix_create_identity_44();
	printf("Base: \n%s\n", matrix_string(base1));
	Matrix* translation = matrix_create_translation(-2, 0, 0);
	printf("Translation: \n%s\n", matrix_string(translation));
	Matrix* result1 = matrix_times(base1, translation);
	printf("Result: \n%s\n", matrix_string(result1));

	Matrix* inv = matrix_create_inverse(result1);
	printf("Inverse: \n%s\n", matrix_string(inv));

	return 0;
}
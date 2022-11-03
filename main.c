#include <stdio.h>

#include "matrix.h"

int main()
{
	printf("------------------- Matrix -------------------\n\n");

	Matrix* scale = matrix_create_scale(0.5, 0.5, 0.5);
	printf("Scale: \n%s\n", matrix_string(scale));
	Matrix* base = matrix_create_identity_44();
	Matrix* transform = matrix_times(base, scale);
	printf("Transform: \n%s\n", matrix_string(transform));
	Matrix* inverse = matrix_create_inverse(transform);
	printf("Inverse: \n%s\n", matrix_string(inverse));

	return 0;
}
#include <stdio.h>

#include "matrix.h"

int main()
{
	printf("------------------- Matrix -------------------\n\n");

	Matrix* matrix = matrix_create_44(
		1, 2, 3, 4,
		2, 3, 4, 5,
		3, 4, 5, 6,
		4, 5, 6, 7
		);

	printf("Matrix:\n%s\n", matrix_string(matrix));

	return 0;
}
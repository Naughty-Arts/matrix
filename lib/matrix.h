#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector.h>

typedef struct
{
	int rows;
	int columns;

	// first index is the row
	// second index is the column
	// data[2][3] - element at 3rd row and 4th column
	float** data;
} Matrix;

Matrix* matrix_create_44(
    float _00, float _01, float _02, float _03,
    float _10, float _11, float _12, float _13,
    float _20, float _21, float _22, float _23,
    float _30, float _31, float _32, float _33
);
Matrix* matrix_create_33(
    float _00, float _01, float _02,
    float _10, float _11, float _12,
    float _20, float _21, float _22
);
Matrix* matrix_create_22(
    float _00, float _01,
    float _10, float _11
);
Matrix* matrix_create(int rows, int columns);
void matrix_free(Matrix * matrix);
Matrix* matrix_create_sub(Matrix* from, int delete_row, int delete_column);
float matrix_minor(Matrix *matrix, int row, int column);
float matrix_cofactor(Matrix* matrix, int row, int column);
Matrix* matrix_create_cofactor(Matrix* matrix);
float matrix_determinant(Matrix* matrix);
Matrix* matrix_create_transposed(Matrix * matrix);
Matrix* matrix_create_inverse(Matrix *matrix);
Matrix* matrix_times(Matrix* m1, Matrix* m2);
Vector matrix_times_vector(Matrix* matrix, Vector v);
_Bool matrix_equals(Matrix* m1, Matrix* m2);
char *matrix_string(Matrix* matrix);
Matrix* matrix_create_translation(float x, float y, float z);
Matrix* matrix_create_scale(float x, float y, float z);
Matrix* matrix_create_rotation_x(float r);
Matrix* matrix_create_rotation_y(float r);
Matrix* matrix_create_rotation_z(float r);
Matrix* matrix_create_shearing(
		float xy,
		float xz,
		float yx,
		float yz,
		float zx,
		float zy
	);
Matrix* matrix_create_view(Vector from, Vector to, Vector up);
Matrix* matrix_create_identity_44();

#endif

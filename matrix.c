#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#ifndef EPSILON
#define EPSILON 0.00001
#endif

#ifndef EQ
#define EQ(F1, F2) abs((F1) - (F2)) < EPSILON
#endif

Matrix* matrix_create_44(
    float _00, float _01, float _02, float _03,
    float _10, float _11, float _12, float _13,
    float _20, float _21, float _22, float _23,
    float _30, float _31, float _32, float _33
) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = 4;
    matrix->columns = 4;
    matrix->data = malloc(sizeof(float*) * 4);
    matrix->data[0] = malloc(sizeof(float) * 4);
    matrix->data[1] = malloc(sizeof(float) * 4);
    matrix->data[2] = malloc(sizeof(float) * 4);
    matrix->data[3] = malloc(sizeof(float) * 4);

    matrix->data[0][0] = _00;
    matrix->data[0][1] = _01;
    matrix->data[0][2] = _02;
    matrix->data[0][3] = _03;

    matrix->data[1][0] = _10;
    matrix->data[1][1] = _11;
    matrix->data[1][2] = _12;
    matrix->data[1][3] = _13;

    matrix->data[2][0] = _20;
    matrix->data[2][1] = _21;
    matrix->data[2][2] = _22;
    matrix->data[2][3] = _23;

    matrix->data[3][0] = _30;
    matrix->data[3][1] = _31;
    matrix->data[3][2] = _32;
    matrix->data[3][3] = _33;

    return matrix;
}

Matrix* matrix_create_33(
    float _00, float _01, float _02,
    float _10, float _11, float _12,
    float _20, float _21, float _22
) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = 3;
    matrix->columns = 3;
    matrix->data = malloc(sizeof(float*) * 3);
    matrix->data[0] = malloc(sizeof(float) * 3);
    matrix->data[1] = malloc(sizeof(float) * 3);
    matrix->data[2] = malloc(sizeof(float) * 3);

    matrix->data[0][0] = _00;
    matrix->data[0][1] = _01;
    matrix->data[0][2] = _02;

    matrix->data[1][0] = _10;
    matrix->data[1][1] = _11;
    matrix->data[1][2] = _12;

    matrix->data[2][0] = _20;
    matrix->data[2][1] = _21;
    matrix->data[2][2] = _22;

    return matrix;
}

Matrix* matrix_create_22(
    float _00, float _01,
    float _10, float _11
) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = 2;
    matrix->columns = 2;
    matrix->data = malloc(sizeof(float*) * 2);
    matrix->data[0] = malloc(sizeof(float) * 2);
    matrix->data[1] = malloc(sizeof(float) * 2);

    matrix->data[0][0] = _00;
    matrix->data[0][1] = _01;

    matrix->data[1][0] = _10;
    matrix->data[1][1] = _11;

    return matrix;
}

Matrix* matrix_create(int rows, int columns)
{
	Matrix* matrix = malloc(sizeof(Matrix));
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->data = malloc(sizeof(float*) * rows);
	for (int i = 0; i < rows; ++i)
	{
		matrix->data[i] = malloc(sizeof(float) * columns);
		for (int j = 0; j < columns; ++j)
		{
			matrix->data[i][j] = 0;
		}
	}
	return matrix;
}

void matrix_free(Matrix * matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		free(matrix->data[i]);
	}
	free(matrix->data);
	free(matrix);
}

Matrix* matrix_create_sub(Matrix* from, int delete_row, int delete_column)
{
	Matrix* result = matrix_create(from->rows - 1, from->columns - 1);
	int row_offset = 0;
	int column_offset = 0;
	for (int r = 0; r < from->rows; ++r)
	{
		column_offset = 0;
		if (r == delete_row)
		{
			++row_offset;
			continue;
		}
		for (int c = 0; c < from->columns; ++c)
		{
			if (c == delete_column)
			{
				++column_offset;
				continue;
			}
			result->data[r - row_offset][c - column_offset] = from->data[r][c];
		}
	}
	return result;
}


float matrix_minor(Matrix *matrix, int row, int column)
{
	Matrix* sub = matrix_create_sub(matrix, row, column);
	float determinant = matrix_determinant(sub);
	matrix_free(sub);
	return determinant;
}

float matrix_cofactor(Matrix* matrix, int row, int column)
{
	if ((row + column) % 2 == 0)
	{
		return matrix_minor(matrix, row, column);
	}
	else
	{
		return -matrix_minor(matrix, row, column);
	}
}

Matrix* matrix_create_cofactor(Matrix* matrix)
{
	Matrix* result = matrix_create(matrix->rows, matrix->columns);
	for (int r = 0; r < matrix->rows; ++r)
	{
		for (int c = 0; c < matrix->columns; ++c)
		{
			result->data[r][c] = matrix_cofactor(matrix, r, c);
		}
	}
	return result;
}

float matrix_determinant(Matrix* matrix)
{
	if (matrix->rows == 2 && matrix->columns == 2)
	{
		return matrix->data[0][0] * matrix->data[1][1] - matrix->data[0][1] * matrix->data[1][0];
	}
	float sum = 0;
	for (int c = 0; c < matrix->columns; ++c)
	{
		sum += matrix->data[0][c] * matrix_cofactor(matrix, 0, c);
	}
	return sum;
}

Matrix* matrix_create_transposed(Matrix * matrix)
{
	assert(matrix->rows == matrix->columns);
	Matrix* result = matrix_create(4, 4);
	for (int r = 0; r < matrix->rows; ++r)
	{
		for (int c = 0; c < matrix->columns; ++c)
		{
			result->data[c][r] = matrix->data[r][c];
		}
	}
	return result;
}

Matrix* matrix_create_inverse(Matrix *matrix)
{
	float d = matrix_determinant(matrix);
	if (EQ(d, 0)) return NULL;
	Matrix* result = matrix_create(matrix->rows, matrix->columns);
	for (int r = 0; r < matrix->rows; ++r)
	{
		for (int c = 0; c < matrix->columns; ++c)
		{
			float cofactor = matrix_cofactor(matrix, r, c);
			result->data[c][r] = cofactor / d;
		}
	}
	return result;
}

Matrix* matrix_times(Matrix* m1, Matrix* m2)
{
	assert(m1->rows == 4 && m1->columns == 4 && m2->rows == 4 && m2->columns == 4);
	Matrix* result = matrix_create(4, 4);
	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; ++c)
		{
			float sum = 0;
			for (int i = 0; i < 4; ++i)
			{
				sum += m1->data[r][i] * m2->data[i][c];
			}
			result->data[r][c] = sum;
		}
	}
	return result;
}

Vector matrix_times_vector(Matrix* matrix, Vector v)
{
	assert(matrix->rows == 4 && matrix->columns == 4);
	Vector result = { 0, 0, 0, 0 };
	
	float sum = 0;
	sum += matrix->data[0][0] * v.x;
	sum += matrix->data[0][1] * v.y;
	sum += matrix->data[0][2] * v.z;
	sum += matrix->data[0][3] * v.w;
	result.x = sum;

	sum = 0;
	sum += matrix->data[1][0] * v.x;
	sum += matrix->data[1][1] * v.y;
	sum += matrix->data[1][2] * v.z;
	sum += matrix->data[1][3] * v.w;
	result.y = sum;
	
	sum = 0;
	sum += matrix->data[2][0] * v.x;
	sum += matrix->data[2][1] * v.y;
	sum += matrix->data[2][2] * v.z;
	sum += matrix->data[2][3] * v.w;
	result.z = sum;
	
	sum = 0;
	sum += matrix->data[3][0] * v.x;
	sum += matrix->data[3][1] * v.y;
	sum += matrix->data[3][2] * v.z;
	sum += matrix->data[3][3] * v.w;
	result.w = sum;

	return result;
}

_Bool matrix_equals(Matrix* m1, Matrix* m2)
{
	if (m1->rows != m2->rows) return 0;
	if (m1->columns != m2->columns) return 0;
	for (int r = 0; r < m1->rows; ++r)
	{
		for (int c = 0; c < m1->columns; ++c)
		{
			if (!EQ(m1->data[r][c], m2->data[r][c])) return 0;
		}
	}
	return 1;
}

char *matrix_string(Matrix* matrix)
{
	char* buffer = malloc(sizeof(char) * 1024);
	char *p = buffer;
	for (int r = 0; r < matrix->rows; ++r)
	{
		for (int c = 0; c < matrix->columns; ++c)
		{
			p += sprintf(p, "%5.5f ", matrix->data[r][c]);
		}
		p += sprintf(p, "\n");
	}
	return buffer;
}

Matrix* matrix_create_translation(float x, float y, float z)
{
	return matrix_create_44(
			1, 0, 0, x,
			0, 1, 0, y,
			0, 0, 1, z,
			0, 0, 0, 0
		);
}

Matrix* matrix_create_scale(float x, float y, float z)
{
	return matrix_create_44(
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1
		);
}

Matrix* matrix_create_rotation_x(float r)
{
	float c = cos(r);
	float s = sin(r);
	return matrix_create_44(
			1, 0, 0, 0,
			0, c, -s, 0,
			0, s, c, 0,
			0, 0, 0, 1
		);
}

Matrix* matrix_create_rotation_y(float r)
{
	float c = cos(r);
	float s = cos(r);
	return matrix_create_44(
			c, 0, s, 0,
			0, 1, 0, 0,
			-s, 0, c, 0,
			0, 0, 0, 1
		);
}

Matrix* matrix_create_rotation_z(float r)
{
	float c = cos(r);
	float s = sin(r);
	return matrix_create_44(
			c, -s, 0, 0,
			s, c, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
}

Matrix* matrix_create_shearing(
		float xy,
		float xz,
		float yx,
		float yz,
		float zx,
		float zy
	)
{
	return matrix_create_44(
			1, xy, xz, 0,
			yx, 1, yz, 0,
			zx, zy, 1, 0,
			0, 0, 0, 1
		);
}

Matrix* matrix_create_view(Vector from, Vector to, Vector up)
{
	Vector forward = vector_normal(vector_subtract(to, from));
	Vector up_normal = vector_normal(up);
	Vector left = vector_cross(forward, up_normal);
	Vector true_up = vector_cross(left, forward);
	Matrix* orientation = matrix_create_44(
			left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1
		);
	Matrix* translation = matrix_create_translation(-from.x, -from.y, -from.z);
	Matrix* result = matrix_times(orientation, translation);
	matrix_free(orientation);
	matrix_free(translation);
	return result;
}

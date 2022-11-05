#include <stdio.h>

#include "matrix.h"

int main()
{
	printf("------------------- Matrix -------------------\n\n");

	/*
				Matrix* translation = matrix_create_translation(sphere_position.x, sphere_position.y, sphere_position.z);
				Matrix* scale = matrix_create_scale(sphere_scale.x, sphere_scale.y, sphere_scale.z);
				Matrix* rotation_x = matrix_create_rotation_x(sphere_rotation.x* 0.0174533);
				Matrix* rotation_y = matrix_create_rotation_y(sphere_rotation.y* 0.0174533);
				Matrix* rotation_z = matrix_create_rotation_z(sphere_rotation.z* 0.0174533);

				printf("Building sphere: %s | %s | %s\n", vector_string(sphere_position), vector_string(sphere_rotation), vector_string(sphere_scale));
				
				Matrix* base = matrix_create_identity_44();
				Matrix* m1 = matrix_times(scale, base);
				Matrix* m2 = matrix_times(rotation_z, m1);
				Matrix* m3 = matrix_times(rotation_y, m2);
				Matrix* m4 = matrix_times(rotation_z, m3);
				Matrix* m5 = matrix_times(translation, m4);

				processing_sphere->transform = m5;
				matrix_free(translation);
				matrix_free(scale);
				matrix_free(rotation_x);
				matrix_free(rotation_y);
				matrix_free(rotation_z);
				matrix_free(base);
				matrix_free(m1);
				matrix_free(m2);
				matrix_free(m3);
				matrix_free(m4);
				world_add_object(world, processing_sphere);

				printf("Sphere transform: \n%s\n", matrix_string(processing_sphere->transform));
	*/

	Matrix* base = matrix_create_identity_44();
	matrix_print("Base", base);
	Matrix* translation = matrix_create_translation(0, 0, 0);
	matrix_print("Translation", translation);
	Matrix* scale = matrix_create_scale(1, 1, 1);
	matrix_print("Scale", scale);
	Matrix* rotation_z = matrix_create_rotation_z(0);
	matrix_print("Rotation Z", rotation_z);
	Matrix* rotation_y = matrix_create_rotation_y(0);
	matrix_print("Rotation Y", rotation_y);

	Matrix* m1 = matrix_times(scale, base);
	Matrix* m2 = matrix_times(rotation_z, m1);
	Matrix* m3 = matrix_times(rotation_y, m2);
	Matrix* m4 = matrix_times(translation, m3);
	matrix_print("Result", m4);

	return 0;
}
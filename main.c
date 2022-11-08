#include <stdio.h>

#include "matrix.h"

int main()
{
	printf("------------------- Matrix -------------------\n\n");

	m4 translation = tr(1, 2, 3);
	m4 scale = scl(1, 2, 3);
	m4 transform = m4times(translation, scale);
	m4 inv = m4inv(transform);

	m4prnt("translation", translation);
	m4prnt("scale", scale);
	m4prnt("transform", transform);
	m4prnt("inverse", inv);

	return 0;
}
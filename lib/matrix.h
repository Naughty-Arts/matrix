#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector.h>
#include <math.h>
#include <stdlib.h>

#ifndef EPSILON
#define EPSILON 0.00001
#endif

#ifndef EQ
#define EQ(F1, F2) fabs((F1) - (F2)) < EPSILON
#endif

typedef struct
{
	float _00; float _01;
	float _10; float _11;
} m2;

#define m2det(m) m._00 * m._11 - m._01 * m._10

#define m2z { 0, 0, 0, 0 }
#define m2eq(m1, m2) EQ(m1._00, m2._00) && EQ(m1._01, m2._01) && EQ(m1._10, m2._10) && EQ(m1._11, m2._11)
#define m2prnt(l, m) printf("%s:\n%4.4f %4.4f\n%4.4f %4.4f\n", l,\
			m._00, m._01,\
			m._10, m._11\
			)

typedef struct
{
	float _00; float _01; float _02;
	float _10; float _11; float _12;
	float _20; float _21; float _22;
} m3;

#define m3sub00(m) {\
		m._11, m._12,\
		m._21, m._22,\
	}

#define m3sub01(m) {\
		m._10, m._12,\
		m._20, m._22,\
	}

#define m3sub02(m) {\
		m._10, m._11,\
		m._20, m._21,\
	}

#define m3sub10(m) {\
		m._01, m._02,\
		m._21, m._22,\
	}

#define m3sub11(m) {\
		m._00, m._02,\
		m._20, m._22,\
	}

#define m3sub12(m) {\
		m._00, m._01,\
		m._20, m._21,\
	}

#define m3sub30(m) {\
		m._01, m._02,\
		m._11, m._12,\
	}

#define m3sub31(m) {\
		m._00, m._02,\
		m._10, m._12,\
	}

#define m3sub32(m) {\
		m._00, m._01,\
		m._10, m._11,\
	}

#define m3min00(m) ({ float r; m2 _m2 = m3sub00(m); r = m2det(_m2); r; })
#define m3min01(m) ({ float r; m2 _m2 = m3sub01(m); r = m2det(_m2); r; })
#define m3min02(m) ({ float r; m2 _m2 = m3sub02(m); r = m2det(_m2); r; })
#define m3min10(m) ({ float r; m2 _m2 = m3sub10(m); r = m2det(_m2); r; })
#define m3min11(m) ({ float r; m2 _m2 = m3sub11(m); r = m2det(_m2); r; })
#define m3min12(m) ({ float r; m2 _m2 = m3sub12(m); r = m2det(_m2); r; })
#define m3min20(m) ({ float r; m2 _m2 = m3sub20(m); r = m2det(_m2); r; })
#define m3min21(m) ({ float r; m2 _m2 = m3sub21(m); r = m2det(_m2); r; })
#define m3min22(m) ({ float r; m2 _m2 = m3sub22(m); r = m2det(_m2); r; })

#define m3cof00(m) m3min00(m)
#define m3cof01(m) -m3min01(m)
#define m3cof02(m) m3min02(m)
#define m3cof10(m) -m3min10(m)
#define m3cof11(m) m3min11(m)
#define m3cof12(m) -m3min12(m)
#define m3cof20(m) m3min20(m)
#define m3cof21(m) -m3min21(m)
#define m3cof22(m) m3min22(m)

#define m3det(m) m._00 * m3cof00(m) + m._01 * m3cof01(m) + m._02 * m3cof02(m)

#define m3z { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define m3eq(m1, m2) EQ(m1._00, m2._00) && EQ(m1._01, m2._01) && EQ(m1._02, m2._02) \
			&& EQ(m1._10, m2._10) && EQ(m1._11, m2._11) && EQ(m1._12, m2._12) \
			&& EQ(m1._20, m2._20) && EQ(m1._21, m2._21) && EQ(m1._22, m2._22)
#define m3prnt(l, m) printf("%s:\n%4.4f %4.4f %4.4f\n%4.4f %4.4f %4.4f\n%4.4f %4.4f %4.4f\n", l, \
			m._00, m._01, m._02,\
			m._10, m._11, m._12,\
			m._20, m._21, m._22\
			)

typedef struct
{
	float _00; float _01; float _02; float _03;
	float _10; float _11; float _12; float _13;
	float _20; float _21; float _22; float _23;
	float _30; float _31; float _32; float _33;
} m4;

#define m4sub00(m) {\
		m._11, m._12, m._13,\
		m._21, m._22, m._23,\
		m._31, m._32, m._33,\
	}

#define m4sub01(m) {\
		m._10, m._12, m._13,\
		m._20, m._22, m._23,\
		m._30, m._32, m._33,\
	}

#define m4sub02(m) {\
		m._10, m._11, m._13,\
		m._20, m._21, m._23,\
		m._30, m._31, m._33,\
	}

#define m4sub03(m) {\
		m._10, m._11, m._12,\
		m._20, m._21, m._22,\
		m._30, m._31, m._32,\
	}

#define m4sub10(m) {\
		m._01, m._02, m._03,\
		m._21, m._22, m._23,\
		m._31, m._32, m._33,\
	}

#define m4sub11(m) {\
		m._00, m._02, m._03,\
		m._20, m._22, m._23,\
		m._30, m._32, m._33,\
	}

#define m4sub12(m) {\
		m._00, m._01, m._03,\
		m._20, m._21, m._23,\
		m._30, m._31, m._33,\
	}

#define m4sub13(m) {\
		m._00, m._01, m._02,\
		m._20, m._21, m._22,\
		m._30, m._31, m._32,\
	}

#define m4sub20(m) {\
		m._01, m._02, m._03,\
		m._11, m._12, m._13,\
		m._31, m._32, m._33,\
	}

#define m4sub21(m) {\
		m._00, m._02, m._03,\
		m._10, m._12, m._13,\
		m._30, m._32, m._33,\
	}

#define m4sub22(m) {\
		m._00, m._01, m._03,\
		m._10, m._11, m._13,\
		m._30, m._31, m._33,\
	}

#define m4sub23(m) {\
		m._00, m._01, m._02,\
		m._10, m._11, m._12,\
		m._30, m._31, m._32,\
	}

#define m4sub30(m) {\
		m._01, m._02, m._03,\
		m._11, m._12, m._13,\
		m._21, m._22, m._23\
	}

#define m4sub31(m) {\
		m._00, m._02, m._03,\
		m._10, m._12, m._13,\
		m._20, m._22, m._23,\
	}

#define m4sub32(m) {\
		m._00, m._01, m._03,\
		m._10, m._11, m._13,\
		m._20, m._21, m._23,\
	}

#define m4sub33(m) {\
		m._00, m._01, m._02,\
		m._10, m._11, m._12,\
		m._20, m._21, m._22,\
	}

#define m4z { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define m4eq(m1, m2) EQ(m1._00, m2._00) && EQ(m1._01, m2._01) && EQ(m1._02, m2._02) && EQ(m1._03, m2._03)\
			&& EQ(m1._10, m2._10) && EQ(m1._11, m2._11) && EQ(m1._12, m2._12) && EQ(m1._13, m2._13)\
			&& EQ(m1._20, m2._20) && EQ(m1._21, m2._21) && EQ(m1._22, m2._22) && EQ(m1._23, m2._23)\
			&& EQ(m1._30, m2._30) && EQ(m1._31, m2._31) && EQ(m1._32, m2._32) && EQ(m1._33, m2._33)
#define m4i {\
				1, 0, 0, 0,\
				0, 1, 0, 0,\
				0, 0, 1, 0,\
				0, 0, 0, 1\
			}
#define m4tr(m) {\
			m._00, m._10, m._20, m._30,\
			m._01, m._11, m._21, m._31,\
			m._02, m._12, m._22, m._32,\
			m._03, m._13, m._23, m._33\
		}
#define m4prnt(l, m) printf("%s:\n%4.4f %4.4f %4.4f %4.4f\n%4.4f %4.4f %4.4f %4.4f\n%4.4f %4.4f %4.4f %4.4f\n%4.4f %4.4f %4.4f %4.4f\n", l, \
			m._00, m._01, m._02, m._03,\
			m._10, m._11, m._12, m._13,\
			m._20, m._21, m._22, m._23,\
			m._30, m._31, m._32, m._33\
			)

#define tr(x, y, z) {\
			1, 0, 0, x,\
			0, 1, 0, y,\
			0, 0, 1, z,\
			0, 0, 0, 1\
			}

#define rx(N, r) {\
			float c = cos(r);\
			float s = sin(r);\
			N =\
			{\
				1, 0, 0, 0,\
				0, c, -s, 0,\
				0, s, c, 0,\
				0, 0, 0, 1\
			};\
		}

#define ry(N, r) {\
		float c = cos(r);\
		float s = sin(r);\
		N =\
		{\
			c, 0, s, 0,\
			0, 1, 0, 0,\
			-s, 0, c, 0,\
			0, 0, 0, 1\
		};\
	}

#define rz(N, r) {\
	float c = cos(r);\
	float s = sin(r);\
	N = \
	{\
		c, -s, 0, 0,\
		s, c, 0, 0,\
		0, 0, 1, 0,\
		0, 0, 0, 1\
	}\
}

#define scl(x, y, z) {\
			x, 0, 0, 0,\
			0, y, 0, 0,\
			0, 0, z, 0,\
			0, 0, 0, 1,\
		}

#define shear(xy, xz, yx, yz, zx, zy) {\
		1, xy, xz, 0,\
		yx, 1, yz, 0,\
		zx, zy, 1, 0,\
		0, 0, 0, 1\
	}

#define view(N, from, to, up) ({\
		v tofrom = vminus(to, from);\
		v forward = vnorm(tofrom);\
		v upnorm = vnorm(up);\
		v left = vcross(forward, upnorm);\
		v trueup = vcross(left, forward);\
		m4 orientation =\
		{\
			left.x, left.y, left.z, 0,\
			trueup.x, trueup.y, trueup.z, 0,\
			-forward.x, -forward.y, -forward.z, 0,\
			0, 0, 0, 1\
		};\
		m4 translation = tr(-from.x, -from.y, -from.z);\
		m4 result = m4times(orientation, tranlsation);\
		result;\
	})

#define m4timesv(m, v) ({\
			v result = { 0, 0, 0, 0 };\
\
			float sum = 0;\
			sum += m._00 * v.x;\
			sum += m._01 * v.y;\
			sum += m._02 * v.z;\
			sum += m._03 * v.w;\
			result.x = sum;\
\
			sum = 0;\
			sum += m._10 * v.x;\
			sum += m._11 * v.y;\
			sum += m._12 * v.z;\
			sum += m._13 * v.w;\
			result.y = sum;\
\
			sum = 0;\
			sum += m._20 * v.x;\
			sum += m._21 * v.y;\
			sum += m._22 * v.z;\
			sum += m._23 * v.w;\
			result.z = sum;\
\
			sum = 0;\
			sum += m._30 * v.x;\
			sum += m._31 * v.y;\
			sum += m._32 * v.z;\
			sum += m._33 * v.w;\
			result.w = sum;\
\
			result;\
		})

#define m4times(m1, m2) ({\
			m4 result = m4z;\
\
			float sum = 0;\
			sum += m1._00 * m2._00;\
			sum += m1._01 * m2._10;\
			sum += m1._02 * m2._20;\
			sum += m1._03 * m2._30;\
			result._00 = sum;\
\
			sum = 0;\
			sum += m1._00 * m2._01;\
			sum += m1._01 * m2._11;\
			sum += m1._02 * m2._21;\
			sum += m1._03 * m2._31;\
			result._01 = sum;\
\
			sum = 0;\
			sum += m1._00 * m2._02;\
			sum += m1._01 * m2._12;\
			sum += m1._02 * m2._22;\
			sum += m1._03 * m2._32;\
			result._02 = sum;\
\
			sum = 0;\
			sum += m1._00 * m2._03;\
			sum += m1._01 * m2._13;\
			sum += m1._02 * m2._23;\
			sum += m1._03 * m2._33;\
			result._03 = sum;\
\
			sum = 0;\
			sum += m1._10 * m2._00;\
			sum += m1._11 * m2._10;\
			sum += m1._12 * m2._20;\
			sum += m1._13 * m2._30;\
			result._10 = sum;\
\
			sum = 0;\
			sum += m1._10 * m2._01;\
			sum += m1._11 * m2._11;\
			sum += m1._12 * m2._21;\
			sum += m1._13 * m2._31;\
			result._11 = sum;\
\
			sum = 0;\
			sum += m1._10 * m2._02;\
			sum += m1._11 * m2._12;\
			sum += m1._12 * m2._22;\
			sum += m1._13 * m2._32;\
			result._12 = sum;\
\
			sum = 0;\
			sum += m1._10 * m2._03;\
			sum += m1._11 * m2._13;\
			sum += m1._12 * m2._23;\
			sum += m1._13 * m2._33;\
			result._13 = sum;\
\
			sum = 0;\
			sum += m1._20 * m2._00;\
			sum += m1._21 * m2._10;\
			sum += m1._22 * m2._20;\
			sum += m1._23 * m2._30;\
			result._20 = sum;\
\
			sum = 0;\
			sum += m1._20 * m2._01;\
			sum += m1._21 * m2._11;\
			sum += m1._22 * m2._21;\
			sum += m1._23 * m2._31;\
			result._21 = sum;\
\
			sum = 0;\
			sum += m1._20 * m2._02;\
			sum += m1._21 * m2._12;\
			sum += m1._22 * m2._22;\
			sum += m1._23 * m2._32;\
			result._22 = sum;\
\
			sum = 0;\
			sum += m1._20 * m2._03;\
			sum += m1._21 * m2._13;\
			sum += m1._22 * m2._23;\
			sum += m1._23 * m2._33;\
			result._23 = sum;\
\
			sum = 0;\
			sum += m1._30 * m2._00;\
			sum += m1._31 * m2._10;\
			sum += m1._32 * m2._20;\
			sum += m1._33 * m2._30;\
			result._30 = sum;\
\
			sum = 0;\
			sum += m1._30 * m2._01;\
			sum += m1._31 * m2._11;\
			sum += m1._32 * m2._21;\
			sum += m1._33 * m2._31;\
			result._31 = sum;\
\
			sum = 0;\
			sum += m1._30 * m2._02;\
			sum += m1._31 * m2._12;\
			sum += m1._32 * m2._22;\
			sum += m1._33 * m2._32;\
			result._32 = sum;\
\
			sum = 0;\
			sum += m1._30 * m2._03;\
			sum += m1._31 * m2._13;\
			sum += m1._32 * m2._23;\
			sum += m1._33 * m2._33;\
			result._33 = sum;\
\
			result;\
		})

#define m4min00(m) ({ float r; m3 _m3 = m4sub00(m); r = m3det(_m3); r; })
#define m4min01(m) ({ float r; m3 _m3 = m4sub01(m); r = m3det(_m3); r; })
#define m4min02(m) ({ float r; m3 _m3 = m4sub02(m); r = m3det(_m3); r; })
#define m4min03(m) ({ float r; m3 _m3 = m4sub03(m); r = m3det(_m3); r; })
#define m4min10(m) ({ float r; m3 _m3 = m4sub10(m); r = m3det(_m3); r; })
#define m4min11(m) ({ float r; m3 _m3 = m4sub11(m); r = m3det(_m3); r; })
#define m4min12(m) ({ float r; m3 _m3 = m4sub12(m); r = m3det(_m3); r; })
#define m4min13(m) ({ float r; m3 _m3 = m4sub13(m); r = m3det(_m3); r; })
#define m4min20(m) ({ float r; m3 _m3 = m4sub20(m); r = m3det(_m3); r; })
#define m4min21(m) ({ float r; m3 _m3 = m4sub21(m); r = m3det(_m3); r; })
#define m4min22(m) ({ float r; m3 _m3 = m4sub22(m); r = m3det(_m3); r; })
#define m4min23(m) ({ float r; m3 _m3 = m4sub23(m); r = m3det(_m3); r; })
#define m4min30(m) ({ float r; m3 _m3 = m4sub30(m); r = m3det(_m3); r; })
#define m4min31(m) ({ float r; m3 _m3 = m4sub31(m); r = m3det(_m3); r; })
#define m4min32(m) ({ float r; m3 _m3 = m4sub32(m); r = m3det(_m3); r; })
#define m4min33(m) ({ float r; m3 _m3 = m4sub33(m); r = m3det(_m3); r; })

#define m4cof00(m) m4min00(m)
#define m4cof01(m) -m4min01(m)
#define m4cof02(m) m4min02(m)
#define m4cof03(m) -m4min03(m)
#define m4cof10(m) -m4min10(m)
#define m4cof11(m) m4min11(m)
#define m4cof12(m) -m4min12(m)
#define m4cof13(m) m4min13(m)
#define m4cof20(m) m4min20(m)
#define m4cof21(m) -m4min21(m)
#define m4cof22(m) m4min22(m)
#define m4cof23(m) -m4min23(m)
#define m4cof30(m) -m4min30(m)
#define m4cof31(m) m4min31(m)
#define m4cof32(m) -m4min32(m)
#define m4cof33(m) m4min33(m)

#define m4det(m) m._00 * m4cof00(m) + m._01 * m4cof01(m) + m._02 * m4cof02(m) + m._03 * m4cof03(m)

#define m4inv(m) ({\
		float d = m4det(m);\
		if (EQ(d, 0))\
		{\
			fprintf(stderr, "matrix is not reversable\n");\
			exit(EXIT_FAILURE);\
		}\
		m4 result =\
		{\
			m4cof00(m) / d, m4cof10(m) / d, m4cof20(m) / d, m4cof30(m) / d,\
			m4cof01(m) / d, m4cof11(m) / d, m4cof21(m) / d, m4cof31(m) / d,\
			m4cof02(m) / d, m4cof12(m) / d, m4cof22(m) / d, m4cof32(m) / d,\
			m4cof03(m) / d, m4cof13(m) / d, m4cof23(m) / d, m4cof33(m) / d,\
		};\
		result;\
	})

#endif
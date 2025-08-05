#include <stdio.h>
#include <complex.h>

#define MAX_BUF_LEN 256

char *cfmt(double complex z)
{
	static char buf[MAX_BUF_LEN] = { 0 };
	double real;
	double imag;
	int write_size;

	real = creal(z);
	imag = cimag(z);
	write_size = 0;
	if (real != 0) {
		write_size = sprintf(buf, "%.1f", real);
		if (imag != 0)
			write_size += sprintf(buf + write_size, " + ");
	}
	if (imag != 0)
		sprintf(buf + write_size, "%.1fi", imag);
	return buf;
}

int main(int argc, char **argv)
{
	double complex z1;
	double complex z2;

	z1 = 5 + 3 * I;
	z2 = 3 - 5 * I;
	printf("z = %s\n", cfmt(z1));
	printf("z_r = %.1f\n", creal(z1));
	printf("z_i = %.1f\n", cimag(z1));
	printf("z1 + z2 = %s\n", cfmt(z1 + z2));
	printf("z1 * z2 = %s\n", cfmt(z1 * z2));
	printf("cabs(z1) = %.1f\n", cabs(z1));
	printf("csin(z1) = %s\n", cfmt(csin(z1)));
	printf("ccos(z1) = %s\n", cfmt(ccos(z1)));
	printf("i = %s\n", cfmt(I));
	printf("i ^ 2 = %s\n", cfmt(cpow(I, 2)));
	printf("i ^ 3 = %s\n", cfmt(cpow(I, 3)));
	printf("i ^ 4 = %s\n", cfmt(cpow(I, 4)));
	return 0;
}

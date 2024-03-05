#include <stdio.h>
int main()
{
	union b
	{
		int k;
		char c[2];
	} a;
	a.k = -7;
	printf("%d %d\n", a.c[0], a.c[1]);
	return 0;
}
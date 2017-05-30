#include <stdio.h>
#include <stdlib.h>

//#define SWAP(x,y) (x = y + x - (y = x))
void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void shellsort(int a[], int n) {
	int k = n / 2, i = 0,j,m;
	while (k >= 1) {
		if (k > 1) {
			for (i = 0; i < n; i++) {
				for (j = i + k; j < n; j += k) {
					m = j;
					while (a[m] < a[m - k] && m >= k) {
						swap(&a[m], &a[m - k]);
						m -= k;
					}
				}
			}
		}
		/*if (k == 1) {
			for (j = 1; j < n; j += k) {
				m = j;
				while (a[m] < a[m - k] && m >= k) {
					swap(&a[m], &a[m - k]);
					m -= k;
				}
			}
		}*/
		k /= 2;
	}
}

void main01() {
	int a[] = { 49, 38, 65, 76, 97, 13, 27 ,80,9}, i,n = sizeof(a)/sizeof(int );

	shellsort(a, n);
	for (i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
	system("pause");
	return;
}

#include <setjmp.h>
jmp_buf envbuf;
void bfunc()
{
	printf("I am func b\n");
	longjmp(envbuf, 5);
	return;
}

void afunc()
{
	printf("I am func a\n");
	bfunc();
	printf("b func finish\n");
	return;
}

int main()
{
	//记录当前程序执行的上下文
	int ret;
	//jmp_buf envbuf;
	ret = setjmp(envbuf);
	if (0 == ret)
	{
		afunc();
	}
	printf("ret=%d\n", ret);
	system("pause");
	return 0;
}

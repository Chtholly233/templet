#include <cstdio>

#define p 11

int A[105],B[105],inv[105];

void init()
{
	int i;
	A[0]=1;
	for(i=1;i<=10;i++)
		A[i]=A[i-1]*i%p;
	
	inv[0]=1;
	inv[1]=1;
	for(i=2;i<=10;i++)
		inv[i]=(p-p/i)*inv[p%i]%p,
		printf("inv[%d] = %d\n",i,inv[i]);
	
	B[1]=1;
	for(i=2;i<=10;i++)
		B[i]=B[i-1]*inv[i]%p,
		printf("B[%d]=%d\n",i,B[i]);
}

int C(int n,int m)
{
	return A[n]*B[m]%p*B[n-m]%p;
}

int main(void)
{
	init();
	printf("C(8,4)=%d\n",C(8,4));
	return 0;
}

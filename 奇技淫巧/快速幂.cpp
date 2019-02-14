#include <cstdio>

#define MOD 11 

int qpow(int x,int p)
{
	if(p==1) return x%MOD;
	if(p==0) return 1;
	
	int a=qpow(x,p/2);
	if(p%2==0) return a*a%MOD;
	return a*a%MOD*x%MOD; 
}

int getinv(int x)
{
	return qpow(x,MOD-2);
}

int main(void)
{
	printf("%d\n",getinv(4));
	printf("%d\n",getinv(3));
	printf("%d\n",getinv(2));
	
} 

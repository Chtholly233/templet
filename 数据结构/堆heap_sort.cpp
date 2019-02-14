#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret;
}

#define M 100005
#define lson(x) (x*2)
#define rson(x) (x*2+1)

int n,a[M];

void update(int x,int m)
{
	int t=lson(x);
	if(t>m)return ;
	if(t<m&&a[t+1]>a[t])t++;
	if(a[t]>a[x])swap(a[x],a[t]);
	update(t,m);
}

void heap_sort()
{
	for(int i=n;i>=1;i--)update(i,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(a[i+1],a[1]);
		update(1,i);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	heap_sort();
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a[10010],st[10010][21],n;//st的第二维取到log2(10010)即可 

void init(){
	for(int i=0;i<=n;i++)
		st[i][0]=i;
	for(int k=1;(1<<k)<=n;k++)
		for(int i=1;i+(1<<k)-1<=n;i++)
			st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
			
}

int ask(int l,int r){
	int len=r-l+1;
	int p=(int)log((double)(len))/log(2.0);//满足2^p<=r-l+1的最大p
	return max(st[l][p],st[r-(1<<p)+1][p]); 
}

//以最大值为例 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	init();
	while(1){
		int l,r;
		scanf("%d",&l);
		if(l==-1)exit(0);
		scanf("%d",&r);
		int ans=ask(l,r);
		printf("%d\n",ans);
	}
	return 0;
} 

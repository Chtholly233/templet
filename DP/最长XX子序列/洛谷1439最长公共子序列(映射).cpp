#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100010;

int n,a[MAXN],b[MAXN];
int c[MAXN];
int stack[MAXN];
int ans=1;
int qwq[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		qwq[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		c[i]=qwq[b[i]];
	}
	stack[1]=c[1];
	for(int i=2;i<=n;i++){
		if(stack[ans]<c[i]){
			stack[++ans]=c[i];
		}else{
			stack[lower_bound(stack+1,stack+ans+1,c[i])-stack]=c[i];
		}
	}
	printf("%d",ans);
	return 0;
}

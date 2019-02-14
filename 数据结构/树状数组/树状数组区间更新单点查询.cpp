#include<cstdio>
#define lowbit(x) (x&(-x)) 
using namespace std;
const int MAXN=10010;

int a[MAXN],n,m,c[MAXN];

void change(int x,int num){
	for(int i=x;i>0;i-=lowbit(i)){
		c[i]+=num;
	}
}

int ask(int x){
	int rxz=0;
	for(int i=x;i<=n;i+=lowbit(i)){
		rxz+=c[i];
	}
	return rxz+a[x];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int ques;
		scanf("%d",&ques);
		if(ques){
			int left,right,num;
			scanf("%d%d%d",&left,&right,&num);
			change(right,num);
			change(left-1,-num);
		} 
		else{
			int x;
			scanf("%d",&x);
			printf("%d\n",ask(x));
		}
	}
	return 0; 
} 

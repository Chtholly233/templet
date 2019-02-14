#include<cstdio>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAXN=500000;

int c[MAXN],n,m;

void change(int x,int num){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=num;
	}
}

int ask(int x){
	if(x==0)return 0;//这个不最好加上
	int s=0;
	for(int i=x;i>0;i-=lowbit(i)){
		s+=c[i];
	}
	return s;
}

int main(){
	scanf("%d%d",&n,&m);
	int temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		change(i,temp);
	}
	for(int i=1;i<=m;i++){
		int ques;
		scanf("%d",&ques);
		if(ques==1){
			int x,num;
			scanf("%d%d",&x,&num);
			change(x,num);
		}
		else{
			int left,right;
			scanf("%d%d",&left,&right);
			int s1=ask(right),s2=ask(left-1);
			printf("%d\n",s1-s2);
		}
	}
	return 0;
} 

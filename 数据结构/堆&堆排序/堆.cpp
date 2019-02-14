#include<cstdio>
#include<algorithm>
using namespace std;
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1) 
#define fat(x) (x>>1)

int tot=0,a[100010];

void swap(int &a,int &b){
	if(&a==&b)return;
	a^=b^=a^=b;
}

void putdown(int x,int m){//下沉的点的下标&最大下沉下标 
	int l=lson(x),r=rson(x),tag;
	if(l>m)return;
	if(r<=m&&a[r]>a[l])tag=r;
	else tag=l;           //找到左右儿子中最[大]的来替换
	if(a[x]<a[tag])swap(a[x],a[tag]);
	putdown(tag,m);//继续下沉
}

void putup(int x){
	int fa=fat(x);
	if(fa<1)return;
	if(a[x]>a[fa])swap(a[x],a[fa]);
	putup(fa);
}

void push(int num){
	a[++tot]=num;
	putup(tot);
}

void pop(){
	swap(a[1],a[tot]);
	printf("你刚刚干掉了堆顶，他的值为%d\n",a[tot]);
	--tot;
	putdown(1,tot);
}

//大根堆 
int t;
int main(){
	scanf("%d",&t);
	printf("input “1”for push,or input “0” for pop。");
	for(int i=1;i<=t;i++){
		int ques;
		scanf("%d",&ques);
		if(ques){
			int kkk;
			scanf("%d",&kkk);
			push(kkk);
		}else
			pop();
	}
	return 0;
} 

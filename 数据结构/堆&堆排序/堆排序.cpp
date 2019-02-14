#include<cstdio>
#include<algorithm>
using namespace std;
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1) 

int n,a[100010];

void swap(int &a,int &b){
	a^=b^=a^=b;
}

void update(int x,int m){//下沉的点的下标&最大下沉下标 
	int l=lson(x),r=rson(x),tag;
	if(l>m)return;
	if(r<=m&&a[r]>a[l])tag=r;
	else tag=l;           //找到左右儿子中最[大]的来替换
	if(a[x]<a[tag])swap(a[x],a[tag]);
	update(tag,m);//继续下沉
}

void heap_sort(){
	for(int i=n;i>=1;i--)update(i,n);//建堆 
	for(int i=n-1;i>=1;i--){
		swap(a[i+1],a[1]);//交换对顶和最后一个节点，相当于pop
		update(1,i);//注意这里最大下沉到i（防止堆顶不再浮上来） 
	}
}

//大根堆 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heap_sort();
	for(int i=n;i>=1;i--)//反着输出 
		printf("%d ",a[i]);	
	return 0;
} 

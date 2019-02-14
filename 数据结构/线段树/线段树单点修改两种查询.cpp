#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=10010; 

int n;//n个元素，m个操作 

struct node{
	int l,r,v;
}tree[4*MAXN+1];//其实最少开到4*MAXN就行 

void build(int l,int r,int k){//当前节点存储的线段的左右端点&这个节点的编号 
	tree[k].l=l;tree[k].r=r;
	if(l==r){
		scanf("%d",&tree[k].v);//叶子节点的值可在这里读入！ 
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,k*2);
	build(mid+1,r,k*2+1);
	tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

//单点查询（叶子节点） 
int askpoint(int x,int k){//目标点在原序列中的下标    k为当前树中的位置下标 
	if(tree[k].l==tree[k].r){
		return tree[k].v;
	}
	int mid=(tree[k].r+tree[k].l)/2;//错点1 //
	if(x<=mid)return askpoint(x,k*2);
	else return askpoint(x,k*2+1);
}

//单点修改 
void changepoint(int x,int num,int k){//要在序列中的第x个数中加上num   k为当前树中的下标 
	if(tree[k].l==tree[k].r){
		tree[k].v+=num;
		return;
	}
	int mid=(tree[k].r+tree[k].l)/2;//错点1 //
	if(x<=mid)changepoint(x,num,k*2);
	else changepoint(x,num,k*2+1);
	tree[k].v=tree[k*2].v+tree[k*2+1].v;//重新整合区间和 
}

//区间查询 
int sum=0;
void asksec(int tl,int tr,int l,int r,int k){
	if(l>=tl&&r<=tr){
		sum+=tree[k].v;
		return;
	}
	int mid=(tree[k].l=tree[k].r)/2;
	if(tl<=mid)asksec(tl,tr,l,mid,k*2);
	if(tr>mid)asksec(tl,tr,mid+1,r,k*2+1);//错点2 不是else// 
}

int main(){
	cout<<"点数"<<endl;//这个程序里不用问题数 
	scanf("%d",&n);
	cout<<"build tree"<<endl; 
	build(1,n,1);
	cout<<"change point"<<endl; 
	int x,num;
	scanf("%d%d",&x,&num);
	changepoint(x,num,1);
	cout<<"ask point"<<endl;
	scanf("%d",&x);
	printf("%d\n",askpoint(x,1));
	cout<<"ask section"<<endl;
	int tl,tr;
	scanf("%d%d",&tl,&tr);
	asksec(tl,tr,1,n,1);
	printf("%d\n",sum);
	return 0;
} 

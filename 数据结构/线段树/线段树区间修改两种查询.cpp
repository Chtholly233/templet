#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=10010; 

int n;//n个元素，m个操作 

struct node{
	int l,r,v,lazy;
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

//下放lazy标记函数
void putdown(int k){
	tree[k*2].lazy+=tree[k].lazy;
	tree[k*2+1].lazy+=tree[k].lazy;
	tree[k*2].v+=tree[k].lazy*(tree[k*2].r-tree[k*2].l+1);//坑点：1.要用父节点k的lazy  2.区间长度记得要+1//
	tree[k*2+1].v+=tree[k].lazy*(tree[k*2+1].r-tree[k*2+1].l+1);//坑点：同上//
	tree[k].lazy=0;//坑点：父节点的lazy要清0！！！！！// 
} 

//单点查询（叶子节点） 
int askpoint(int x,int k){
	if(tree[k].l==tree[k].r){
		return tree[k].v;
	}
	if(tree[k].lazy)putdown(k);//防止重复下放 
	int mid=(tree[k].l+tree[k].r)/2;
	if(x<=mid)return askpoint(x,k*2);
	else return askpoint(x,k*2+1);
}

//区间修改 
void changesection(int tl,int tr,int num,int k){
	if(tl<=tree[k].l&&tr>=tree[k].r){//对查询有用 
		tree[k].v+=num*(tree[k].r-tree[k].l+1);//坑点// 
		tree[k].lazy+=num; 
		return;
	}
	if(tree[k].lazy)putdown(k);//防止重复下放 
	int mid=(tree[k].r+tree[k].l)/2;//错点 //
	if(tl<=mid)changesection(tl,tr,num,k*2);
	if(tr>mid)changesection(tl,tr,num,k*2+1);
	tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

//区间查询 
int sum=0;
void asksec(int tl,int tr,int l,int r,int k){
	if(l>=tl&&r<=tr){
		sum+=tree[k].v;
		return;
	}
	if(tree[k].lazy)putdown(k);//防止重复下放 
	int mid=(tree[k].r+tree[k].l)/2;
	if(tl<=mid)asksec(tl,tr,l,mid,k*2);
	if(tr>mid)asksec(tl,tr,mid+1,r,k*2+1);
}

int main(){
	//freopen("in.in","r",stdin);
	cout<<"点数"<<endl;
	scanf("%d",&n);
	cout<<"build tree"<<endl; 
	build(1,n,1);
	cout<<"change section"<<endl; 
	int x,y,num;
	scanf("%d%d%d",&x,&y,&num);
	changesection(x,y,num,1);
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

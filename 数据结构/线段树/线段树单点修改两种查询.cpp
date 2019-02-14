#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=10010; 

int n;//n��Ԫ�أ�m������ 

struct node{
	int l,r,v;
}tree[4*MAXN+1];//��ʵ���ٿ���4*MAXN���� 

void build(int l,int r,int k){//��ǰ�ڵ�洢���߶ε����Ҷ˵�&����ڵ�ı�� 
	tree[k].l=l;tree[k].r=r;
	if(l==r){
		scanf("%d",&tree[k].v);//Ҷ�ӽڵ��ֵ����������룡 
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,k*2);
	build(mid+1,r,k*2+1);
	tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

//�����ѯ��Ҷ�ӽڵ㣩 
int askpoint(int x,int k){//Ŀ�����ԭ�����е��±�    kΪ��ǰ���е�λ���±� 
	if(tree[k].l==tree[k].r){
		return tree[k].v;
	}
	int mid=(tree[k].r+tree[k].l)/2;//���1 //
	if(x<=mid)return askpoint(x,k*2);
	else return askpoint(x,k*2+1);
}

//�����޸� 
void changepoint(int x,int num,int k){//Ҫ�������еĵ�x�����м���num   kΪ��ǰ���е��±� 
	if(tree[k].l==tree[k].r){
		tree[k].v+=num;
		return;
	}
	int mid=(tree[k].r+tree[k].l)/2;//���1 //
	if(x<=mid)changepoint(x,num,k*2);
	else changepoint(x,num,k*2+1);
	tree[k].v=tree[k*2].v+tree[k*2+1].v;//������������� 
}

//�����ѯ 
int sum=0;
void asksec(int tl,int tr,int l,int r,int k){
	if(l>=tl&&r<=tr){
		sum+=tree[k].v;
		return;
	}
	int mid=(tree[k].l=tree[k].r)/2;
	if(tl<=mid)asksec(tl,tr,l,mid,k*2);
	if(tr>mid)asksec(tl,tr,mid+1,r,k*2+1);//���2 ����else// 
}

int main(){
	cout<<"����"<<endl;//��������ﲻ�������� 
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

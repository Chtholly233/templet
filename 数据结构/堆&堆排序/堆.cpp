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

void putdown(int x,int m){//�³��ĵ���±�&����³��±� 
	int l=lson(x),r=rson(x),tag;
	if(l>m)return;
	if(r<=m&&a[r]>a[l])tag=r;
	else tag=l;           //�ҵ����Ҷ�������[��]�����滻
	if(a[x]<a[tag])swap(a[x],a[tag]);
	putdown(tag,m);//�����³�
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
	printf("��ոոɵ��˶Ѷ�������ֵΪ%d\n",a[tot]);
	--tot;
	putdown(1,tot);
}

//����� 
int t;
int main(){
	scanf("%d",&t);
	printf("input ��1��for push,or input ��0�� for pop��");
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

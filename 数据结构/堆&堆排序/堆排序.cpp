#include<cstdio>
#include<algorithm>
using namespace std;
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1) 

int n,a[100010];

void swap(int &a,int &b){
	a^=b^=a^=b;
}

void update(int x,int m){//�³��ĵ���±�&����³��±� 
	int l=lson(x),r=rson(x),tag;
	if(l>m)return;
	if(r<=m&&a[r]>a[l])tag=r;
	else tag=l;           //�ҵ����Ҷ�������[��]�����滻
	if(a[x]<a[tag])swap(a[x],a[tag]);
	update(tag,m);//�����³�
}

void heap_sort(){
	for(int i=n;i>=1;i--)update(i,n);//���� 
	for(int i=n-1;i>=1;i--){
		swap(a[i+1],a[1]);//�����Զ������һ���ڵ㣬�൱��pop
		update(1,i);//ע����������³���i����ֹ�Ѷ����ٸ������� 
	}
}

//����� 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heap_sort();
	for(int i=n;i>=1;i--)//������� 
		printf("%d ",a[i]);	
	return 0;
} 

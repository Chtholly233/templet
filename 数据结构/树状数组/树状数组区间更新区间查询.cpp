#include<cstdio>
#define lowbit(x) x&(-x)
using namespace std;
const int MAXN=10010;

int n,m,a[MAXN];
int c[MAXN],d[MAXN];//�������&����d[i]=(i-1)c[i];

void changesection(int x,int num){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=num;
		d[i]+=(x-1)*num;
	}
}

int asksection(int x){//ѯ��[1,x]ǰ׺�� 
	int s=0;
	for(int i=x;i>0;i-=lowbit(i)){
		s+=x*c[i]-d[i];
	}
	return s;
}

int main(){
	//freopen("in.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//Ҫ��ʼ��������
	for(int i=1;i<=n;i++)
		changesection(i,a[i]-a[i-1]);
	int ques;
	for(int i=1;i<=m;i++){
		scanf("%d",&ques);
		if(ques==1){//change section
			int left,right,num;//����[left,right]������num 
			scanf("%d%d%d",&left,&right,&num);
			changesection(left,num);
			changesection(right+1,-num);
		}
		else{//ask section
			int left,right;
			scanf("%d%d",&left,&right);
			int s1=asksection(right),s2=asksection(left-1);
			printf("%d\n",s1-s2);
		}
	}
	return 0;
}

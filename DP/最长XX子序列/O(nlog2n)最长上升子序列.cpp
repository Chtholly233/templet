#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10010;

int n,a[MAXN],stack[MAXN];
int ans=1;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	stack[1]=a[1];//��ʼ��Ϊ��һ��Ԫ�� !
	for(int i=2;i<=n;i++){//��2��ʼ�ң�
		if(a[i]>stack[ans]){//����ע��stack[ans]������stack[i]!!!�����״����� 
			stack[++ans]=a[i];
		}else{
			int qwq=lower_bound(stack+1,stack+ans+1,a[i])-stack;//ע����stack+ans+1����Ϊ���������Χ��һ������ҿ������� 
			stack[qwq]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}

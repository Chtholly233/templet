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
	stack[1]=a[1];//初始化为第一个元素 !
	for(int i=2;i<=n;i++){//从2开始找！
		if(a[i]>stack[ans]){//这里注意stack[ans]而不是stack[i]!!!很容易错！！！ 
			stack[++ans]=a[i];
		}else{
			int qwq=lower_bound(stack+1,stack+ans+1,a[i])-stack;//注意是stack+ans+1，因为这个函数范围是一个左闭右开！！！ 
			stack[qwq]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}

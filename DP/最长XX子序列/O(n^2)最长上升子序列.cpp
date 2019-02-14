#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10010;

int n,a[MAXN],dp[MAXN],ans=0;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[1]=1;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
} 

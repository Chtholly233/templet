#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

int st[100010][21],n;//st的第二维取到log2(10010)即可 

void init(){
    for(int k=1;(1<<k)<=n;k++)
        for(int i=1;i+(1<<k)-1<=n;i++)
            st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
}

int ask(int l,int r){
    int len=r-l+1;
    //int p=(int)log((double)(len))/log(2.0);//满足2^p<=r-l+1的最大p
    int p=log2(len);
    return max(st[l][p],st[r-(1<<p)+1][p]); 
}

//以最大值为例 
int main(){
	int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[i][0]);
    init();
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=ask(l,r);
        printf("%d\n",ans);
    }
    return 0;
}

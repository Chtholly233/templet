#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff
#define maxn 5005
int cost[maxn][maxn],minn,n,m,v2[maxn]/*与每个点相连的最小边*/,tot=1,now,ans;
bool v1[maxn];
inline void getcost()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[i][j]=inf;
        }
    }
    //先将数组赋为极大值
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(cost[u][v]>w)
        {
            cost[u][v]=cost[v][u]=w;
        }
    }
    //初始化cost数组
    for(int i=1;i<=n;i++)
    {
        v2[i]=cost[1][i];
    }
    v1[1]=1;
    //找出与1节点相连的边并进行标记为 
}
inline int prim()
{
    while(tot<n)
    //最小生成树的概念，边数比点数小一
    {
        minn=inf; 
        //附上初值
        tot++;
        //已经使用边数++
        for(int i=1;i<=n;i++)
        {
            if(!v1[i]&&v2[i]<minn)
            {
                minn=v2[i];
                now=i;//找到连接最小边的节点标记 
            }
        }
        //找出与该点相连的最小边
        ans+=minn;
        //更新答案
        for(int i=1;i<=n;i++)
        {
            if(cost[now][i]<v2[i]&&!v1[i])
            {
                v2[i]=cost[now][i];//更新与now节点相连的点的最小值 
            }
        }
        v1[now]=1;//标记为now为已经使用 
    }
    return ans;
}
int main()
{
    getcost();
    printf("%d",prim());
    return 0;
}

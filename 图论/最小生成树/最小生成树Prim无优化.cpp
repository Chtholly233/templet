#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff
#define maxn 5005
int cost[maxn][maxn],minn,n,m,v2[maxn]/*��ÿ������������С��*/,tot=1,now,ans;
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
    //�Ƚ����鸳Ϊ����ֵ
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(cost[u][v]>w)
        {
            cost[u][v]=cost[v][u]=w;
        }
    }
    //��ʼ��cost����
    for(int i=1;i<=n;i++)
    {
        v2[i]=cost[1][i];
    }
    v1[1]=1;
    //�ҳ���1�ڵ������ı߲����б��Ϊ 
}
inline int prim()
{
    while(tot<n)
    //��С�������ĸ�������ȵ���Сһ
    {
        minn=inf; 
        //���ϳ�ֵ
        tot++;
        //�Ѿ�ʹ�ñ���++
        for(int i=1;i<=n;i++)
        {
            if(!v1[i]&&v2[i]<minn)
            {
                minn=v2[i];
                now=i;//�ҵ�������С�ߵĽڵ��� 
            }
        }
        //�ҳ���õ���������С��
        ans+=minn;
        //���´�
        for(int i=1;i<=n;i++)
        {
            if(cost[now][i]<v2[i]&&!v1[i])
            {
                v2[i]=cost[now][i];//������now�ڵ������ĵ����Сֵ 
            }
        }
        v1[now]=1;//���ΪnowΪ�Ѿ�ʹ�� 
    }
    return ans;
}
int main()
{
    getcost();
    printf("%d",prim());
    return 0;
}

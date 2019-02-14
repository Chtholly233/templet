#include<bits/stdc++.h>
using namespace std;
struct Edge{int u,v,w;}edge[200005];
int fa[5005],n,m,ans,eu,ev,cnt;
inline bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
//���ŵ�����
inline int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
//���鼯ѭ��ʵ��ģ�壬��·��ѹ�����������鼯��ͬѧ���Դ�һ�������Ϸ��ġ����鼯��⡱
inline void kruskal()
{
    sort(edge,edge+m,cmp);
    //���ߵ�Ȩֵ����
    for(int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //�����ֻ�����continue
        ans+=edge[i].w;
        //���˱�Ȩ�����
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
        //ѭ������������������Ϊ������һʱ
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    //��ʼ�����鼯
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    printf("%d",ans);
    return 0;
}

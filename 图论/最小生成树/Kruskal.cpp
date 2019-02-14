#include<bits/stdc++.h>
using namespace std;
struct Edge{int u,v,w;}edge[200005];
int fa[5005],n,m,ans,eu,ev,cnt;
inline bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
//快排的依据
inline int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
//并查集循环实现模板，及路径压缩，不懂并查集的同学可以戳一戳代码上方的“并查集详解”
inline void kruskal()
{
    sort(edge,edge+m,cmp);
    //将边的权值排序
    for(int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //若出现环，则continue
        ans+=edge[i].w;
        //将此边权计入答案
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
        //循环结束条件，及边数为点数减一时
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    //初始化并查集
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    printf("%d",ans);
    return 0;
}

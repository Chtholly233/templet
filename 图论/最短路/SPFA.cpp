/*
	Author : FlierKing
	Language : C++
	Problem : LG3371 
*/
#include <bits/stdc++.h>
#define ll long long
#define MAXM 500005
#define MAXN 10005
using namespace std;
    int n,m,s,sz,st,en;
    int Q[4000005],f[MAXN],to[MAXM<<1],nex[MAXM<<1],v[MAXM<<1],las[MAXN];
    bool inq[MAXN];
int inline read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void ins(int x,int y,int z)
{
    sz++;to[sz]=y;v[sz]=z;nex[sz]=las[x];las[x]=sz;
}
void spfa()
{
	memset(f,127/2,sizeof(f));
    f[s]=0;Q[st=en=1]=s;
    while (st<=en)
	{
		int x=Q[st++];
	    inq[x]=false;
	    for (int i=las[x];i;i=nex[i])
	    if (f[x]+v[i]<f[to[i]])
	    {
	        f[to[i]]=f[x]+v[i];
	        if (!inq[to[i]])
	        {
	            inq[to[i]]=true;
	            Q[++en]=to[i];
	        }
	    }
	}
}
int main()
{
    n=read(),m=read(),s=read();
    for (int i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        ins(x,y,z);
    }
    spfa(); 
    for (int i=1;i<=n;i++)
        printf("%d%c",f[i]>1e9?2147483647:f[i],i==n?'\n':' ');
    return 0;
}

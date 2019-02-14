//最小生成树 Kruskal算法  洛谷2330
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct road
{
	int A,B,V;
}R[10001];
int n,m,sz;
int to[20005],nex[20005],las[305];
void ins(int x,int y)
{
	sz++;to[sz]=y;nex[sz]=las[x];las[x]=sz;
	sz++;to[sz]=x;nex[sz]=las[y];las[y]=sz;
}
inline bool comp(const road &a,const road &b)
{
	return a.V<b.V;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&R[i].A,&R[i].B,&R[i].V);
}
bool check(int x,int y)
{
	bool u[305];
	memset(u,false,sizeof(u));
	int l[305],st=1,en=1;
	l[1]=x;u[x]=true;
	while (st<=en)
	{
		int tmp=l[st++];
		for (int i=las[tmp];i;i=nex[i])
		if (!u[to[i]])
		{
			u[to[i]]=true;
			l[++en]=to[i];
		}
	}
	return u[y]==false;
}
void solve(){
	int i,now=0;
	sort(R+1,R+1+m,comp);
	for(i=1;i<=m;i++)
		if(check(R[i].A,R[i].B))
		{
			ins(R[i].A,R[i].B);
			now++;
			if(now==n-1)
			{
				printf("%d %d\n",now,R[i].V);
				return;
			}
		}
}
int main()
{
	init();
	solve();
	return 0;
}

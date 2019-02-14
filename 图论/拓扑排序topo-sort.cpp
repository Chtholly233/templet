#include<cstdio>
#include<queue>
#define MAX 10010
using namespace std;
struct Edge{
	int u,v,next;
}edge[MAX];
int first[MAX],n,m,cnt=0,rudu[MAX],ans[MAX];
void AddEdge(int u,int v){
	edge[++cnt].u=u;edge[cnt].v=v;edge[cnt].next=first[u];first[u]=cnt;
}
void topsort(){
	int bl=0;
	queue<int> q;
	for(int i=1;i<=n;i++)if(rudu[i]==0){q.push(i);ans[++bl]=i;}
	while(!q.empty()){
		int u=q.front();q.pop();
		int i=first[u];
		while(i!=-1){
			int v=edge[i].v;
			rudu[v]--;
			if(rudu[v]==0){
				ans[++bl]=v;
				q.push(v);
			}
			i=edge[i].next;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)first[i]=-1;
	for(int i=1;i<=n;i++)rudu[i]=0;
	for(int i=1;i<=n;i++)ans[i]=-1;
	int X,Y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X,&Y);
		AddEdge(X,Y);
		rudu[Y]++;
	}
	topsort();
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

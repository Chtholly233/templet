#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

const int MAX=233;
int m,n;
int first[MAX];

struct edge{
	int u,v,next;
}e[10086];

int cnt=0;
void insert(int u,int v){
	++cnt;e[cnt].u=u;e[cnt].v=v;e[cnt].next=first[u];first[u]=cnt;
}

int dfn[MAX]={0},low[MAX]={0},ins[MAX]={0};
stack<int> s;
int tot=0;
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	s.push(u);
	ins[u]=1;
	for(int i=first[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(dfn[v]==0){//没搜过 
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]){//已搜过&在队里 
			low[u]=min(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u]){
		int fa=0,van[MAX];
		while(s.top()!=u){
			van[++fa]=s.top();
			ins[s.top()]=0;
			s.pop();
		}
		s.pop();
		++fa;van[fa]=u;
		for(int i=1;i<=fa;i++){
			printf("%d ",van[i]);
		}
		printf("是一个scc\n");
	}
}

int main(){
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	return 0;
} 

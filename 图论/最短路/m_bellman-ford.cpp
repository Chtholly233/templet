#include<cstdio>
#define INF 2147483647
#define MAX 10010
struct Edge{
	int u,v,w;
}edge[MAX];
int n,m,s,t,dist[MAX];
void BellmanFord(){
	int updated=0;
	for(int j=1;j<=n-1;j++){
	    for(int i=1;i<=m;i++)
	    	if(dist[edge[i].u]+edge[i].w<dist[edge[i].v]){
	    		dist[edge[i].v]=dist[edge[i].u]+edge[i].w;
	    		updated=1;
	    	}
	    if(!updated)break;
	    updated=0;
	}
	for(int i=1;i<=m;i++)
		if(dist[edge[i].u]+edge[i].w<dist[edge[i].v]){
		    printf("Orz");
			return;
		}
	printf("%d",dist[t]);    
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int X,Y,Z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&X,&Y,&Z);
		edge[i].u=X;
		edge[i].v=Y;
		edge[i].w=Z;
	}
	BellmanFord();
	return 0;
}

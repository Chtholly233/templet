#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 500001;

inline int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*w;
}

int n,t,root;
int upto[MAXN][25],d[MAXN]={0},first[MAXN],lg[MAXN];

struct edge{
	int u,v,next;
}e[2*MAXN];

int tot=0;
void insert(int u,int v){
	++tot;e[tot].u=u;e[tot].v=v;e[tot].next=first[u];first[u]=tot;
}

void init(int u,int fa){
	d[u]=d[fa]+1;
	upto[u][0]=fa;
	for(int k=1;(1<<k)<=d[u];k++){
		upto[u][k]=upto[upto[u][k-1]][k-1];
	}
	for(int i=first[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v!=fa)init(v,u);
	}
}

int solve(int a,int b){
	if(d[a]<d[b])swap(a,b);
	while(d[a]>d[b]){
		a=upto[a][lg[d[a]-d[b]]-1]; 
	}
	if(a==b)return a;
	for(int k=lg[d[a]]-1;k>=0;k--)
		if(upto[a][k]!=upto[b][k]){
			a=upto[a][k];b=upto[b][k];
		}
	return upto[a][0];
}

int main(){
	memset(first,-1,sizeof(first)); 
	n=read();t=read();root=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}
	init(root,0);
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);//Ô¤´¦Àílg[i]=log2(i)+1 
	for(int i=1;i<=t;i++){
		int a=read(),b=read();
		printf("%d\n",solve(a,b));
	}
	return 0;
}

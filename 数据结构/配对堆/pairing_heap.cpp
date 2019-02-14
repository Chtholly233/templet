#include<cstdio>

inline void swap(int &x,int &y){
	x^=y^=x^=y;
}

//大根堆 
struct pairing_heap{
	struct node{
		int v,s,r;
	}tree[10010];
	int tot,root;
	pairing_heap(int _tot=0,int _root=0):tot(_tot),root(_root){}
	int Merge(int x,int y){//合并根为x,y的两棵树，返回根 
		if(!x||!y){root=x+y;return x+y;}//有一个是空树（为0）
		if(tree[x].v<tree[y].v)swap(x,y);
		tree[y].r=tree[x].s;tree[x].s=y;
		return root=x;
	}
	int Push(int x){
		tree[++tot].v=x;
		tree[tot].r=tree[tot].s=0;
		return Merge(root,tot);
	}
	void Del(int x){
		tree[root].s=tree[x].r;tree[x].r=0;
	}
	int Pop(){
		int x=tree[root].s,y=tree[x].r;
		if(x==0)return 0;
		Del(x);if(y)Del(y);
		return root=Merge(Merge(x,y),Pop());
	}
	int Top(){
		return tree[root].v;
	}
};

int main(){
	pairing_heap q;
	printf("input “0”for push，“1” for top,“2” for pop or “-1” for exit \n");
	while(1){
		int ques;
		scanf("%d",&ques);
		if(ques==0){
			int x;
			scanf("%d",&x);
			q.Push(x);
		}else if(ques==1){
			printf("%d\n",q.Top());
		}else if(ques==2){
			q.Pop();
		}else if(ques==-1){
			break;
		}
	}
	return 0;
} 

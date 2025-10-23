#include <stdio.h>
#define V_MAX 31
#define E_MAX 60

int isvisited[V_MAX]={0};

typedef struct{
	int u;
	int v;
}Edge;

int parent[V_MAX] = {0};
int rank[V_MAX] = {0};

void makeset(int n){
	for(int i=1;i<=n;i++){
		parent[i] = i;
		rank[i] = 1;//用rank当该集合的大小
	}
}

int find(int x){
	if(parent[x]!=x){
		parent[x] = find(parent[x]);//也可while循环，但是左边的可以捎带把经过的点的root也算出来
	}
	return parent[x];
}

void UnionSets(int a,int b){
	int rootA = find(a);
	int rootB = find(b);
	if(rootA!=rootB){//用集合大小归并各个集合
		if(rank[rootA]>=rank[rootB]){
			parent[rootB] = rootA;
			rank[rootA]+=rank[rootB];
		}else{
			parent[rootA] = rootB;
			rank[rootB]+=rank[rootA];
		}
	}
}

void quick_sort(int* q, int l, int r){
	if(l>=r)	return;
	int x = (l+r)>>1;
	int i = l-1, j = r+1;
	while(i<j){
		do i++;while(q[i]<q[x]);
		do j--;while(q[j]>q[x]);
		if(i<j){
			int t = q[i];
			q[i] = q[j];
			q[j] = t;
		}
	}
	quick_sort(q,l,j),quick_sort(q,j+1,r);
}

int main(){
	int  n, m;
	scanf("%d %d",&n,&m);
	Edge edges[E_MAX];
	for(int i=0;i<m;i++){
		int j,k;
		scanf("%d %d",&j,&k);
		edges[i].u = j;
		edges[i].v = k;
	}
	int count_sub = 0;
	int sub[V_MAX] = {0};
	
	makeset(n);
	for(int i=0;i<m;i++){
		UnionSets(edges[i].u,edges[i].v);
	}
	for(int i=1;i<=n;i++){
		int root = find(i);
		if(rank[root]!=1&&isvisited[root]){
			sub[count_sub++] = rank[root];
			isvisited[root] = 1;
		}
	}
	quick_sort(sub,0,count_sub-1);
	printf("%d\n",count_sub);
	for(int i=0;i<count_sub;i++){
		printf("%d ",sub[i]);
	}
}

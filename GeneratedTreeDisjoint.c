#include <stdio.h>
#include <stdlib.h>
#define V_MAX 31
#define E_MAX 101
typedef struct{
	int u;
	int v;
	int w;
}Edge;

int parent[V_MAX];
int rank[V_MAX];
Edge sub[V_MAX];
Edge result[V_MAX];

int compareofW(const void *a,const void *b){
	return ((Edge*)a)->w - ((Edge*)b)->w;
}

void makeset(int n){
	for(int i=1;i<=n;i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	if(parent[x]!=x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Unionsets(int a,int b){
	int RA = find(a);
	int RB = find(b);
	if(RA!=RB){
		if(rank[RA]>rank[RB]){
			parent[RB] = RA;
		}else if(rank[RA]<rank[RB]){
			parent[RA] = RB;
		}else{
			parent[RB] = RA;
			rank[RA]++;
		}
	}
}

void Kruskal(int n,int m){
	qsort(sub,m,sizeof(Edge),compareofW);
	makeset(n);
	
	int count_E = 0;
	
	for(int i=0;i<m&&count_E<n-1;i++){
		Edge current = sub[i];
		if(find(current.u)!=find(current.v)){
			Unionsets(current.u,current.v);
			result[count_E]=current;
			count_E++;
		}
	}
	
	for (int i = 0; i < count_E; i++) {
		if(result[i].u < result[i].v){
			printf("%d %d %d\n", result[i].u, result[i].v, result[i].w);
		} else {
			printf("%d %d %d\n", result[i].v, result[i].u, result[i].w);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		sub[i].u = u;
		sub[i].v = v;
		sub[i].w = w;
	}
	Kruskal(n,m);
	return 0;
}

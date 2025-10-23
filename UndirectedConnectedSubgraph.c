#include <stdio.h>
#define V_MAX 31

int G[V_MAX][V_MAX]={0};
int isvisited[V_MAX]={0};

int dfs(int start,int n){
	isvisited[start] = 1;
	int count = 1;
	for(int i=1;i<=n;i++){
		if(!isvisited[i] && G[start][i]){
			isvisited[i] = 1;
			count+=dfs(i,n);
		}
	}	
	return count;
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
	
	for(int i=0;i<m;i++){
		int j,k;
		scanf("%d %d",&j,&k);
		G[j][k] = 1;
		G[k][j] = 1;
	}

	int count_subgraph = 0;
	int set_subgraph[V_MAX]={0};
	
	for(int i=1;i<=n;i++){
		if(!isvisited[i]){
			set_subgraph[count_subgraph]=dfs(i,n);
			count_subgraph++;
		}
		
	}
	quick_sort(set_subgraph,0,count_subgraph-1);
	printf("%d\n",count_subgraph);
	for(int i=0;i<count_subgraph;i++){
		printf("%d ",set_subgraph[i]);
	}
	
	return 0;
}

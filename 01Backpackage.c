#include <stdio.h>
#define n_MAX 102

int max(int a,int b){
	if(a>b)	return a;
	return b;
}
int  BackPackage(int n,int V,int *v,int *c){
	int dp[n_MAX][n_MAX] = {0};
	for(int i=1;i<=n;i++){
		for(int j=0;j<=V;j++){
			if(j<v[i]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+c[i]);
			}
		}
	}
	return dp[n][V];
}

int main(){
	int n, V;
	scanf("%d %d",&n,&V);
	int v[n_MAX]={0};
	int c[n_MAX]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	int result = BackPackage(n,V,v,c);
	printf("%d",result);
	return 0;
}

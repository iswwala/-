#include <stdio.h>
#define n_MAX 101

int max(int a,int b){
	return a>b?a:b;
}
int  BackPackage(int n,int V,int *v,int *c){
	int dp[n_MAX] = {0};
	for(int i=1;i<=n;i++){
		for(int j=V;j>=v[i];j--){
			dp[j] = max(dp[j],dp[j-v[i]]+c[i]);
		}
	}
	return dp[V];
}

int main(){
	int n, V;
	scanf("%d %d",&n,&V);
	int v[n_MAX];
	int c[n_MAX];
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

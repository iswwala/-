#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int* q = (int*)malloc(sizeof(int)*n);
	int sum = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&q[i]);
		while(q[i]){
			sum += q[i]%10;
			q[i]/=10;
		}
	}
	printf("%d",sum%10);
}

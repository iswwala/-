#include <stdio.h>
#include <stdlib.h>
void quick_sort(int* q, int l, int r){
	if(l>=r)	return;
	int mid = (l+r)>>1;
	int x = q[mid];
	int i = l-1,j = r+1;
	while(i<j){
		do i++;while(q[i]>x);
		do j--;while(q[j]<x);
		if(i<j){
			int t = q[i];
			q[i] = q[j];
			q[j] = t;
		}
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}

int main(){
	int n;
	scanf("%d",&n);
	int *q = (int*)malloc(sizeof(int)*n);
	for(int i = 0;i<n;i++)	scanf("%d",&q[i]);
	int sum = 0;
	for(int i=n-1;i>=1;i--){
		quick_sort(q,0,i);
		q[i-1] +=q[i];
		sum +=q[i-1];
	}
	printf("%d",sum);
	free(q);
	return 0;
}

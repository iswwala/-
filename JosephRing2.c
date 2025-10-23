#include <stdio.h>
#include <stdlib.h>

void josephus_optimized(int n, int initial_m, int* passwords) {
	int current = 0; 
	int m = initial_m;
	int remaining = n;
	int* out = (int*)calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++) {
		int steps = (m - 1) % remaining;
		
		while (steps > 0) {
			current = (current + 1) % n;
			if (!out[current]) steps--;
		}
		
		printf("%d ", current + 1);
		out[current] = 1;
	
		m = passwords[current];
		remaining--;
		
		if (remaining > 0) {
			do {
				current = (current + 1) % n;
			} while (out[current]);
		}
	}
	printf("\n");
	free(out);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int* passwords = (int*)malloc(n * sizeof(int));
	for(int i = 0;i < n;i++){
		scanf("%d",&passwords[i]);
	}
	josephus_optimized(n,m,passwords);
	free(passwords);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXP 10000  

typedef struct {
	int coeff;
	int exp;
} Term;

void processPolynomial(int n, int m, int t, int* data1, int* data2) {
	int poly[MAX_EXP * 2 + 1] = {0};  
	int max_exp = 0;
	int min_exp = MAX_EXP * 2;
	
	for (int i = 0; i < n; i++) {
		int coeff = data1[2 * i];
		int exp = data1[2 * i + 1];
		poly[exp] += coeff;
		if (exp > max_exp) max_exp = exp;
		if (exp < min_exp) min_exp = exp;
	}
	
	for (int i = 0; i < m; i++) {
		int coeff = data2[2 * i];
		int exp = data2[2 * i + 1];
		if (t == 0) {  
			poly[exp] += coeff;
		} else {        
			poly[exp] -= coeff;
		}
		if (exp > max_exp) max_exp = exp;
		if (exp < min_exp) min_exp = exp;
	}
	
	int first_term = 1;
	int all_zero = 1;  
	
	for (int exp = min_exp; exp <= max_exp; exp++) {
		int coeff = poly[exp];
		if (coeff == 0) continue;
		
		all_zero = 0;  
		
		if (!first_term) {
			if (coeff > 0) {
				printf("+");
			} else {
				printf("-");
				coeff = -coeff;  
			}
		} else {
			if (coeff < 0) {
				printf("-");
				coeff = -coeff;
			}
			first_term = 0;
		}
		
		if (exp == 0) {
			printf("%d", coeff);
		} else if (exp == 1) {
			if (coeff == 1) {
				printf("x");
			} else {
				printf("%dx", coeff);
			}
		} else {
			if (coeff == 1) {
				printf("x^%d", exp);
			} else {
				printf("%dx^%d", coeff, exp);
			}
		}
	}
	
	if (all_zero) {
		printf("0");
	}
	printf("\n");
}

int main() {
	int n, m, t;
	if (scanf("%d %d %d", &n, &m, &t) != 3) {
		printf("输入格式错误\n");
		return 1;
	}
	
	int* data1 = (int*)malloc(2 * n * sizeof(int));
	int* data2 = (int*)malloc(2 * m * sizeof(int));
	
	if (data1 == NULL || data2 == NULL) {
		printf("内存分配失败\n");
		free(data1);
		free(data2);
		return 1;
	}
	
	for (int i = 0; i < 2 * n; i++) {
		if (scanf("%d", &data1[i]) != 1) {
			printf("输入数据错误\n");
			free(data1);
			free(data2);
			return 1;
		}
	}
	for (int i = 0; i < 2 * m; i++) {
		if (scanf("%d", &data2[i]) != 1) {
			printf("输入数据错误\n");
			free(data1);
			free(data2);
			return 1;
		}
	}
	
	processPolynomial(n, m, t, data1, data2);
	
	free(data1);
	free(data2);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double q1, q2, q3, q4;
	scanf("%lf,%lf,%lf,%lf", &q1, &q2, &q3, &q4);

	double R[3][3];

	double q12 = q1*q1,q22=q2*q2,q32=q3*q3,q42=q4*q4;
	R[0][0] = q12+q22-q32-q42;
	R[0][1] = 2*(q2*q3 - q1*q4);
	R[0][2] = 2*(q1*q3 + q2*q4);
	
	R[1][0] = 2*(q1*q4 + q3*q2);
	R[1][1] = q12-q22+q32-q42;
	R[1][2] = 2*(q2*q4 - q1*q2);
	
	R[2][0] = 2*(q2*q4 - q1*q3);
	R[2][1] = 2*(q4*q3 + q1*q2);
	R[2][2] = q12-q22-q32+q42;
	
	// 输出旋转矩阵，每行数据之间用空格分隔
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%.6f", R[i][j]);
			if(j < 2) {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}

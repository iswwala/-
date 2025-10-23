#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 10000

// 快速替换函数 - 直接原地修改
void fast_replace(char* str) {
	char temp[MAXSIZE];
	int i = 0, j = 0;
	
	while (str[i]) {
		if (str[i] == 'A') {
			temp[j++] = 's';
			temp[j++] = 'a';
			temp[j++] = 'e';
			i++;
		} else if (str[i] == 'B') {
			temp[j++] = 't';
			temp[j++] = 's';
			temp[j++] = 'a';
			temp[j++] = 'e';
			temp[j++] = 'd';
			temp[j++] = 's';
			temp[j++] = 'a';
			temp[j++] = 'e';
			i++;
		} else {
			temp[j++] = str[i++];
		}
	}
	temp[j] = '\0';
	strcpy(str, temp);
}

// 快速括号解码 - 无递归，单次遍历
void fast_decode_parentheses(char* input, char* output) {
	int i = 0, j = 0;
	int len = strlen(input);
	
	while (i < len) {
		if (input[i] == '(') {
			i++; // 跳过 '('
			
			// 提取括号内容
			char inner[MAXSIZE] = {0};
			int k = 0;
			while (i < len && input[i] != ')') {
				inner[k++] = input[i++];
			}
			i++; // 跳过 ')'
			
			// 快速展开括号内容
			if (k > 0) {
				char theta = inner[0];
				output[j++] = theta;
				
				// 从后往前处理剩余字符
				for (int m = k - 1; m >= 1; m--) {
					output[j++] = theta;
					output[j++] = inner[m];
				}
			}
		} else {
			// 直接复制普通字符
			output[j++] = input[i++];
		}
	}
	output[j] = '\0';
	
	// 一次性替换所有大写字母
	fast_replace(output);
}

int main() {
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();  // 记录开始时间
	char input[MAXSIZE];
	scanf("%s", input);
	
	char output[MAXSIZE] = {0};
	
	// 单次处理：先解码括号，然后替换
	fast_decode_parentheses(input, output);
	
	printf("%s\n", output);
	
	end = clock();  // 记录结束时间
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("程序运行时间: %f 秒\n", cpu_time_used);
	return 0;
}

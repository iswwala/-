#include <stdio.h>
#include <string.h>
#define MAXSIZE  1000
#define AA "sae"
#define BB "tsaedsae"
void Replace(char* raw){
	char result[MAXSIZE] = {0};
	int len = strlen(raw);
	int result_index=0;
	for(int i=0;i<len;i++){
		if(raw[i]=='A'){
			strcat(result,AA);
			result_index+=3;
		}else if(raw[i]=='B'){
			strcat(result,BB);
			result_index+=8;
		}else{
			result[result_index++]=raw[i];
			result[result_index] = '\0';
		}
	}
	strcpy(raw,result);
}

void DecodeParenthese(char* inner,char* result){
	int len = strlen(inner);
	if(!inner[0]){
		result[0]='\0';
		return;
	}
	char theta = inner[0];
	int result_index=0;
	for(int i=len-1;i>=1;i--){
		result[result_index++] = theta;
		result[result_index++] = inner[i];
	}
	result[result_index++] = theta;
	result[result_index]='\0';
	Replace(result);
}

int main(){

	char raw[MAXSIZE];
	scanf("%s",raw);
	char output[MAXSIZE] = {0};
	int output_index = 0;
	int len = strlen(raw);
	int i = 0;
	while(i < len){
		if(raw[i]=='('){
			i++;
			char inner[MAXSIZE] = {0};
			int inner_size = 0;
			while(raw[i]!=')'){
				inner[inner_size++] = raw[i++];
			}
			i++;
			char temp[MAXSIZE] = {0};
			DecodeParenthese(inner,temp);
			strcat(output,temp);
			output_index = strlen(output)-1+1;
			
		}else{
			if(raw[i]=='A'||raw[i]=='B'){
				char temp[11] = {0};
				if(raw[i]=='A'){
					strcat(temp,AA);
				}else{
					strcat(temp,BB);
				}
				strcat(output,temp);
				output_index = strlen(output)-1+1;
			}else{
				output[output_index++] = raw[i];
				output[output_index] = '\0';
			}
			i++;
		}
	}
	printf("%s",output);
	return 0;
}


#include <stdio.h>
#include <string.h>
#define PMAXSIZE 100
#define CMAXSIZE 20
int KMP(char* p, char* c, int startofp,int * next){
	int i = startofp,j = 0;
	int len_p = strlen(p),len_c = strlen(c);
	//如果一直使用strlen()，结果会出错！！！
	while(i<len_p&&j<len_c){
		if(j==-1||p[i]==c[j]){
			i++,j++;
		}	
		else{
			j = next[j];
		}
	}
	if(j==len_c){
		int result = i-strlen(c)+1;
		return result;
	}else{
		return 0;
	}
}

void GenerateNext(char* c, int* next) {
	int len = strlen(c);
	int i = 0;
	next[0] = -1; 
	int j = -1;
	while(i<len-1){
		if( j==-1 || c[i]==c[j] ){
			i++,j++;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}

int main(){
	char p[PMAXSIZE],c[CMAXSIZE];
	fgets(p,sizeof(p),stdin);
	fgets(c,sizeof(c),stdin);
	p[strcspn(p,"\n")] = '\0';
	c[strcspn(c,"\n")] = '\0';
	int	next[CMAXSIZE] = {0};
	GenerateNext(c,next);
	int result = KMP(p,c,0,next);
	if(result!=0){
		printf("%d",result);
	}else{
		printf("No!");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#define MAXSIZE 21

int main(){
	char p[MAXSIZE],c[MAXSIZE];
	fgets(p,sizeof(p),stdin);
	fgets(c,sizeof(c),stdin);
	p[strcspn(p,"\n")] = '\0';
	c[strcspn(c,"\n")] = '\0';
	char* result = strstr(p,c);
	if(result!=NULL){
		printf("%ld",result-p+1);
	}else{
		printf("No!");
	}
	return 0;
}

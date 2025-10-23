#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int BF(char* p, char* c, int startofp){
	int i = startofp,j = 0;
	while(i<strlen(p)&&j<strlen(c)){
		if(p[i]==c[j])	i++,j++;
		else	i = i-j+1,j=0;
	}
	if(j==strlen(c)){
		return i-strlen(c)+1;
	}else{
		return 0;
	}
}

int main(){
	char p[MAXSIZE],c[MAXSIZE];
	fgets(p,sizeof(p),stdin);
	fgets(c,sizeof(c),stdin);
	p[strcspn(p,"\n")] = '\0';
	c[strcspn(c,"\n")] = '\0';
	int result = BF(p,c,0);
	if(result!=0){
		printf("%d",result);
	}else{
		printf("No!");
	}
	return 0;
}

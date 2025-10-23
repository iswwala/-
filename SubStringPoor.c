#include <stdio.h>
#include <string.h>

int main(){
	char p[21],c[21];
	fgets(p,sizeof(p),stdin);
	fgets(c,sizeof(c),stdin);
	p[strcspn(p,"\n")] = '\0';
	c[strcspn(c,"\n")] = '\0';
	int found = 0;
	int position = 0;
	for(int i = 0;i<strlen(p)-strlen(c)+1;i++){
		int match = 1;
		for(int j = 0;j<strlen(c);j++){
			if(p[i+j]!=c[j]){
				match = 0;
				break;
			}
		}
		if(match){
			found = 1;
			position = i+1;
			break;
		}
	}
	if(found){
		printf("%d",position);
	}else{
		printf("No!");
	}
}

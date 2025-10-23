#include <stdio.h>
#define MAXSIZE 1000
int main(){
	char str[1000]={};
	scanf("%s",str);
	for(int i=0;str[i];i++){
		if(str[i]-'A'>=0 && str[i]-'Z'<=0){
			str[i] = 'A'+(str[i]-'A'+4)%26;
		}else{
			str[i] = 'a'+(str[i]-'a'+4)%26;
		}
	}
	printf("%s",str);
}

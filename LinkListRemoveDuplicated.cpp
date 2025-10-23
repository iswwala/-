#include <iostream>
using namespace std;
typedef struct Node{
	int address,key,next;
}Node;
Node nodes[100000];
int visited[10001] = {0};

int abs(int a){
	if(a<0)	return -a;
	else return a;
}
int main(){
	int first_fake_address, n;
	scanf("%d %d",&first_fake_address,&n);
	for(int i=0;i<n;i++){
		int address,key,next;
		scanf("%d %d %d",&address,&key,&next);
		nodes[address].address = address;
		nodes[address].key = key;
		nodes[address].next = next;
	}
	Node unique[n+1],duplicated[n+1];
	int unique_length = 0,duplicated_length = 0;
	int current = first_fake_address;
	while(current!=-1){
		if(!visited[abs(nodes[current].key)]){
			visited[abs(nodes[current].key)] = 1;
			unique[unique_length++] = nodes[current];
		}else{
			duplicated[duplicated_length++] = nodes[current];
			unique[unique_length-1].next = nodes[current].next;
		}
		current = nodes[current].next;
	}
	printf("%d\n",unique_length);
	for(int i=0;i<unique_length-1;i++){
		printf("%05d %d %05d\n",unique[i].address,unique[i].key,unique[i].next);
	}
	printf("%05d %d %d",unique[unique_length-1].address,unique[unique_length-1].key,unique[unique_length-1].next);
}

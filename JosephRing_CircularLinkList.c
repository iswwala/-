#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int id;
	int password;
	struct Node* next;
}Node;

Node* CreateCircularList(int n,int* passwords){
	Node* head = NULL;
	Node* tail = NULL;
	
	for(int i = 0;i < n;i++){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->id = i+1;
		newNode->password = passwords[i];
		newNode->next = NULL;
		
		if(head==NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	if(tail!=NULL){
		tail->next = head;
	}
	return head;
}

void SolveJoseph(int n,int m,int* passwords){
	Node* head = CreateCircularList(n,passwords);
	Node* current = head;
	Node* prev = NULL;
	while(current->next!=head){
		current = current->next;
	}
	prev = current;
	current = head;
	
	int count = 1;
	int remain = n;
	
	while(remain>0){
		if(count==m){
			printf("%d",current->id);
			if(remain>1){
				printf(" ");
			}
			
			m = current->password;
			Node* toDelete = current;
			prev->next = current->next;
			current = current->next;
			free(toDelete);
			
			count = 1;
			remain--;
		}else{
			count++;
			prev = current;
			current = current->next;
		}
	}
	
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int* passwords = (int*)malloc(n * sizeof(int));
	for(int i = 0;i < n;i++){
		scanf("%d",&passwords[i]);
	}
	SolveJoseph(n,m,passwords);
	free(passwords);
	return 0;
}

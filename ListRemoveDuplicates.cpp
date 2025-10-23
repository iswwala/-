#include <iostream>
using namespace std;

typedef struct LinkNode{
	int Address;
	int key;
	int fakenext;
	struct LinkNode* next;
}LinkNode,*Linklist;

int abs(int a){
	if(a<0)	return -a;
	else	return a;
}
void RemoveDuplicated(Linklist L,int &length){//length_initial=1
	if(L==NULL){
		length = 0;
		return ;
	}
	length = 1;
	LinkNode* current = L;
	while(current!=NULL && current->next!=NULL){
		LinkNode* pre = current;
		LinkNode* runner = current->next;
		while(runner!=NULL){
			if(abs(current->key)==abs(runner->key)){
				pre->fakenext = runner->fakenext;
				pre->next = runner->next;
				runner = pre->next;
			}else{
				pre = runner;
				runner = runner->next;
			}
		}
		current = current->next;
		if(current!=NULL)	length++;
	}
}

void Print(LinkNode* L,int length){
	LinkNode* current = L;
	printf("%d\n",length);
	while(current->next!=NULL){
		printf("%05d %d %05d\n",current->Address,current->key,current->fakenext);
		current = current->next;
	}
	printf("%05d %d %d\n",current->Address,current->key,current->fakenext);
}

LinkNode* CreateRealLinkList(int first_fake_address,int n){
	if(n<=0)	return NULL;
	LinkNode* nodes = (LinkNode*)malloc(n*sizeof(LinkNode));
	for(int i=0;i<n;i++){
		int Address,key,fakenext;
		scanf("%d %d %d",&Address,&key,&fakenext);
		nodes[i].Address = Address;
		nodes[i].key = key;
		nodes[i].fakenext = fakenext;
		nodes[i].next = NULL;
	}
	LinkNode* L = NULL;
	for(int i=0;i<n;i++){
		if(nodes[i].fakenext!=-1){
			for(int j=0;j<n;j++){
				if(nodes[j].Address==nodes[i].fakenext){
					nodes[i].next = &nodes[j];
					break;
				}
			}
		}
		if(nodes[i].Address==first_fake_address)	L = &nodes[i];
	}
	return L;
}

int main(){
	int first_fake_address, n;
	scanf("%d %d",&first_fake_address,&n);
	LinkNode* L = CreateRealLinkList(first_fake_address,n);
	int length = 1;
	RemoveDuplicated(L,length);
	Print(L,length);
}

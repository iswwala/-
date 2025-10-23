#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	stack<char> st;
	for(size_t i=0;i<str.length();i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){
			st.push(str[i]);
		}else if(str[i]==')'||str[i]==']'||str[i]=='}'){
			if(st.empty()){
				printf("no");
				return 0;
			}
			char ch = st.top();
			if((ch=='('&&str[i]==')')||
			   (ch=='['&&str[i]==']')||
			   (ch=='{'&&str[i]=='}')){
				st.pop();
			}else{
				printf("no");
				return 0;
			}
		}
	}
	if(st.empty()){
		printf("yes");
	}else{
		printf("no");
	}
	
	return 0;
}

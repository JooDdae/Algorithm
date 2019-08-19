#include<bits/stdc++.h>
using namespace std;
int n,i;
char s[300];
int main(){
    while(++i){
		vector<string> v;
    	scanf("%d",&n);
    	if(!n) break;
    	while(n--){
    		scanf(" %[^\n]s",s);
    		v.push_back(s);
    	}
    	sort(v.begin(),v.end());
    	printf("%d\n",i);
    	for(string s : v) printf("%s\n",s.data());
    }
}
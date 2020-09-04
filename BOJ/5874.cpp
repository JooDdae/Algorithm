#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[50050];
int ans, cnt;
int main(){
	scanf("%s",s+1);
	for(int i=2;s[i];i++){
		if(s[i-1] == ')' && s[i] == ')') ans += cnt;
		if(s[i-1] == '(' && s[i] == '(') cnt++;
	}
	printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[111];
int n;
int f(int cur,int num){
	if(cur < 0) return 0;
	int re;
	if('0'<=s[cur] && s[cur]<='9') re = num * (s[cur]-'0');
	else re = num * (s[cur]-'A'+10);
	return re + f(cur-1, num*n);
}
int main(){
    scanf("%s %d",s,&n);
    printf("%d",f(strlen(s)-1,1));
}
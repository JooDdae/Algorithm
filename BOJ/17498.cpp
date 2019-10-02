#include<bits/stdc++.h>
int n;
char s[102];
int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<=n/2;i++)s[i]=s[n-i-1]=std::max({s[i],s[n-i-1],'a'});
    puts(s);
}
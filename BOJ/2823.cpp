#include<bits/stdc++.h>
using namespace std;
int n, m;
char s[20][20];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j] == '.' && (s[i][j-1]=='.')+(s[i][j+1]=='.')+(s[i-1][j]=='.')+(s[i+1][j]=='.') < 2) return !printf("1");
	printf("0");
}
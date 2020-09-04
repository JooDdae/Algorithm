#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, u;
char s[88];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %s",s);
		int l = strlen(s);
		if(i == 1) u += l;
		else if(u + l > m) puts(""), u = l;
		else printf(" "), u += l;
		printf("%s",s);
	}
}
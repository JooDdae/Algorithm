#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
char s[9];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s %d",s,&n);
		puts((s[1]-'0'+s[0]-'A'+1)%2 == ((n-1)/8+1+(n-1)%8+1)%2? "YES":"NO");
	}
}
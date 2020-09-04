#include<bits/stdc++.h>
using namespace std;
int n, len;
char s[1010][111];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	len = strlen(s[1]+1);
	for(int l=1;s[1];l++){
		map<string, int> mp;
		int fl = 0;
		for(int j=1;j<=n && !fl;j++) if(mp[s[j]+len-l+1]++) fl = 1;
		if(!fl) return !printf("%d",l);
	}
}
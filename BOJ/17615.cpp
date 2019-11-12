#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt[256];
char s[500500];
int main(){
	scanf("%d %s",&n,s+1);
	for(int i=1;i<=n;i++) cnt[s[i]]++;
	int ans = min(cnt['R'], cnt['B']);
	for(int i=1;i<=n;i++) if(s[1]!=s[i]){ans = min(ans, cnt[s[1]]-i+1); break;}
	for(int i=n;i>=1;i--) if(s[n]!=s[i]){ans = min(ans, cnt[s[n]]-n+i); break;}
	printf("%d",ans);
}
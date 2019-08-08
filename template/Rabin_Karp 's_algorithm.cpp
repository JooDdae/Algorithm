// boj.kr/1786
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
char s1[1010101],s2[1010101];
ull h,h2,pw=1,mod=283,mod2=1000000007;
vector<int> ans;
int l1,l2;
int main(){
	fgets(s1, 1010101, stdin);
	fgets(s2, 1010101, stdin);
	l1 = strlen(s1), l2 = strlen(s2);
	if(s1[l1-1]=='\n') s1[--l1]='\0';
	if(s2[l2-1]=='\n') s2[--l2]='\0';
	for(int i=1;i<l2;i++) (pw*=mod)%=mod2;
	for(int i=0;i<l2;i++) h=(h*mod+s2[i])%mod2;
	for(int i=0;i<l2;i++) h2=(h2*mod+s1[i])%mod2;
	if(h == h2) ans.push_back(1);
	for(int i=l2;i<l1;i++){
		h2 = ((h2-pw*s1[i-l2]%mod2+mod2)%mod2*mod+s1[i])%mod2;
		if(h==h2) ans.push_back(i-l2+2);
	}
	printf("%d\n",ans.size());
	for(int x : ans) printf("%d ",x);
}
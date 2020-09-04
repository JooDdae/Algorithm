#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, mx, m;
char s[30];
map<string,int> mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		mp[s]++;
	}
	for(auto x : mp){
		if(x.second > mx) mx = x.second, m = 1;
		else if(x.second == mx) m++;
	}
	if(m > 1) return !printf("NONE");
	m = mx*2;
	for(auto x : mp) m -= x.second;
	if(m < 1) return !printf("NONE");
	for(auto x : mp) if(x.second == mx) return !printf("%s",x.first.data());
}
#include<bits/stdc++.h>
using namespace std;
int t,n;
string dp[1010];
string f2(string a,string b){
	if(a.size() == 0 || a.size() > b.size()) return b;
	if(a.size() < b.size()) return a;
	return min(a,b);
}
string f(int a){
	if(dp[a].size()) return dp[a];
	string s;
	if(a % 2 == 0) s = f2(s, "1"+f(a/2)+"2");
	if(a % 3 == 0) s = f2(s, "3"+f(a/3)+"4");
	if(a % 5 == 0) s = f2(s, "5"+f(a/5)+"6");
	for(int i=1;i<a;i++) s = f2(s, f(i) + f(a-i));
	return dp[a] = s;
}
int main(){
	dp[1] = "12",dp[2] = "34",dp[3] = "56";
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		f(n);
		for(int i=0;i<dp[n].size();i++) printf("%c","(){}[]"[dp[n][i] - '1']);
		puts("");
	}
}
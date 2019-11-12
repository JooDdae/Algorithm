#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mx,l=-1,sz;
char s[202020];
stack<int> st;
vector<pair<int,int>> v;
int main(){
	scanf("%d %s",&n,s+1);

	for(int i=1;i<=n;i++){
		if(s[i] == '(') st.push(i);
		else if(!st.empty()) v.push_back({st.top(),i}), st.pop();
	}
	sort(v.begin(),v.end());
	for(auto nxt : v){
		if(l+1<nxt.first){
			mx = max(mx, sz);
			l = nxt.second;
			sz = 2;
		}else{
			l = max(l, nxt.second);
			sz += 2;
		}
	}
	printf("%d",max(mx,sz));
}
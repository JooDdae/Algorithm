#include<bits/stdc++.h>
using namespace std;
int n,m,chk[22];
vector<pair<int,int>> v;
bool f2(int num){
	if(num < 0) return !chk[-num];
	return chk[num];
}
bool f(int cur){
	if(cur == n){
		for(pair<int,int> t : v) if(!f2(t.first) && !f2(t.second)) return false;
		return true;
	}
	chk[cur+1] = 0;
	if(f(cur+1)) return true;
	chk[cur+1] = 1;
	if(f(cur+1)) return true;
	return false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	v.push_back({a,b});
    }
    if(f(0)) printf("1");
    else printf("0");
}
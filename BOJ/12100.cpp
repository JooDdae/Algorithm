#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;
int n,mx;
vv mp;
vv r(vv v,int cnt){
	if(!cnt) return v;
	vv re(n, vector<int>(n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) re[i][j] = v[n-j-1][i];
	return r(re,cnt-1);
}
vv p(vv v){
	vv re(n, vector<int>());
	for(int i=0;i<n;i++){
		int fl=0;
		for(int j=0;j<n;j++){
			if(v[i][j]){
				if(fl){
					if(fl == v[i][j]) re[i].push_back(fl*2), fl=0;
                    else re[i].push_back(fl), fl=v[i][j];
				}else fl=v[i][j];
			}
		}
		if(fl) re[i].push_back(fl);
	}
	for(int i=0;i<n;i++) while(re[i].size() < n) re[i].push_back(0);
	return re;
}
void f(int cnt, vv v){
	if(cnt == 5){
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) mx=max(mx, v[i][j]);
		return;
	}
	for(int i=0;i<4;i++) f(cnt+1, p(r(v,i)));
}
int main(){
    scanf("%d",&n);
    mp.resize(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&mp[i][j]);
    f(0,mp);
	printf("%d",mx);
}
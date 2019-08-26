#include<bits/stdc++.h>
using namespace std;
struct query{
	int x,y,id;
	bool operator < (const query &a)const{
		return make_pair(x>>10, y) < make_pair(a.x>>10, a.y);
	}
}in[1010101];
int n,q,arr[1010101],out[1010101],chk[1010101];
vector<pair<int,int>> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	v.push_back({a,i});
    }
    sort(v.begin(),v.end());
	int cnt = 1;
	for(int i=0;i<n;i++){
		if(i && v[i].first != v[i-1].first) ++cnt;
		arr[v[i].second] = cnt;
	}
    scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&in[i].x,&in[i].y);
		in[i].id = i;
	}
	sort(in+1, in+1+q);
	int l=1,r=0,ans=0;
    for(int i=1;i<=q;i++){
    	while(l<in[i].x) if(--chk[arr[l++]] == 0) ans--;
    	while(r<in[i].y) if(chk[arr[++r]]++ == 0) ans++;
    	while(l>in[i].x) if(chk[arr[--l]]++ == 0) ans++;
    	while(r>in[i].y) if(--chk[arr[r--]] == 0) ans--;
    	out[in[i].id] = ans;
    }
	for(int i=1;i<=q;i++) printf("%d\n",out[i]);
}
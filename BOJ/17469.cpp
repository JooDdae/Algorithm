#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,p[101010],c[101010],par[101010],f[1110101],s[1110101],ans[101010],cnt;
unordered_set<int> st[101010];
int F(int a){
	if(a == par[a]) return a;
	return par[a] = F(par[a]);
}
void uni(int a,int b){
	a = F(a), b = F(b);
	if(st[a].size() > st[b].size()) swap(a,b);
	for(int x : st[a]) st[b].insert(x);
	par[a] = b;
}
int main(){
    scanf("%d %d",&n,&q);

    for(int i=1;i<=n;i++) par[i] = i;

    for(int i=2;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) st[i].insert(c[i]);
    for(int i=n+q-1;i>=1;i--) scanf("%d %d",&f[i],&s[i]);

    for(int i=1;i<n+q;i++){
    	if(f[i] == 1) uni(s[i], p[s[i]]);
    	else ans[++cnt] = st[F(s[i])].size();
    }
    while(cnt) printf("%d\n",ans[cnt--]);
}
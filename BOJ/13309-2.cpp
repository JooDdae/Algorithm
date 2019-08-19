#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,cnt,t[200020],lev[200020],in[200020],out[200020],sp[200020][20];
vector<int> v[200020];
void dfs(int cur){
	in[cur] = ++cnt;
	lev[cur] = lev[sp[cur][0]]+1;
	for(int nxt : v[cur]) dfs(nxt);
	out[cur] = cnt;
}
int lca(int a,int b){
	if(lev[a] < lev[b]) swap(a,b);
	for(int i=18;i>=0;i--) if((lev[a]-lev[b])&(1<<i)) a = sp[a][i];
	if(a == b) return a;
	for(int i=18;i>=0;i--) if(sp[a][i] != sp[b][i]) a = sp[a][i], b = sp[b][i];
	return sp[a][0];
}
void up(int bit,int val){
	while(bit <= cnt){
		t[bit] += val;
		bit += bit & -bit;
	}
}
int f(int bit){
	int re=0;
	while(bit){
		re += t[bit];
		bit -= bit & -bit;
	}
	return re;
}
int f2(int a){
	return f(out[a]);
}
int main(){
    scanf("%d%*d",&n);
    for(int i=2;i<=n;i++){
    	scanf("%d",&sp[i][0]);
    	v[sp[i][0]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=18;i++) for(int j=1;j<=n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
    while(~scanf("%d%d%d",&a,&b,&c)){
    	int l = f2(lca(a,b));
    	int fl = f2(a) == l && f2(b) == l;
    	printf("%s\n",fl?"YES":"NO");
    	if(c){
    		if(fl) up(in[a],1),up(out[a]+1,-1);
    		else up(in[b],1),up(out[b]+1,-1);
    	}
    }
}
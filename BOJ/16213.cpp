#include<bits/stdc++.h>
using namespace std;
struct edge{
	int s, e, v;
	bool operator < (const edge &o) const{
		return v > o.v;
	}
}e[500500];
struct query{
	int s, e, l, r, mid, id;
	bool operator < (const query &o) const{
		return mid > o.mid;
	}
}q[200200];
int N, M, Q, par[200200], ans[200200], INF = 1e9;
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
int main(){
	scanf("%d %d %d",&N,&M,&Q);
	for(int i=1;i<=M;i++) scanf("%d %d %d",&e[i].s,&e[i].e,&e[i].v);
	for(int i=1;i<=Q;i++) scanf("%d %d",&q[i].s,&q[i].e), q[i].l = 1, q[i].r = INF, q[i].mid = (q[i].l + q[i].r)>>1, q[i].id = i;
	sort(e+1, e+1+M);

	int flag = 1;
	while(flag--){
		for(int i=1;i<=N;i++) par[i] = i;
		sort(q+1, q+1+Q);

		for(int i=1,j=1;i<=Q;i++){
			if(q[i].l > q[i].r) continue;
			flag = 1;

			while(j <= M && e[j].v >= q[i].mid){
				int a = f(e[j].s), b = f(e[j].e);
				if(a != b) par[a] = b;
				j++;
			}
			if(f(q[i].s) != f(q[i].e)) q[i].r = q[i].mid - 1;
			else q[i].l = q[i].mid + 1;

			q[i].mid = (q[i].l + q[i].r) >> 1;
		}
	}

	for(int i=1;i<=Q;i++) ans[q[i].id] = q[i].l;
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]-1);
}
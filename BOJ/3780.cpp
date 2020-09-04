#include<bits/stdc++.h>
using namespace std;
int t, n, par[20020], dist[20020];
int f(int a){
	if(a == par[a]) return a;
	int tmp = par[a];
	par[a] = f(par[a]);
	dist[a] += dist[tmp];
	return par[a];
}

void merge(int a, int b){
	int c = f(a), d = f(b);
	if(c == d) return;
	par[c] = b;
	dist[c] += abs(c - b) % 1000;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) par[i] = i, dist[i] = 0;
		while(1){
			char a; scanf(" %c",&a);
			if(a == 'O') break;
			if(a == 'E'){
				int b; scanf("%d",&b);
				f(b);
				printf("%d\n",dist[b]);
			}
			if(a == 'I'){
				int b, c; scanf("%d %d",&b,&c);
				merge(b, c);
			}
		}
	}
}
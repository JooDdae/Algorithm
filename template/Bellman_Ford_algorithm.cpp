// boj.kr/11657
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 505
#define INF 1e9

int n,m,dist[MAX_N];
vector<pair<int,int>> v[MAX_N];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n;i++) dist[i] = INF;
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(pair<int,int> nxt : v[j]){
				if(dist[j] != INF && dist[j] + nxt.second < dist[nxt.first]){
					if(i == n) return !printf("-1");
					dist[nxt.first] = dist[j] + nxt.second;
				}
			}
		}
	}
	for(int i=2;i<=n;i++) printf("%d\n",dist[i]!=INF?dist[i]:-1);
}
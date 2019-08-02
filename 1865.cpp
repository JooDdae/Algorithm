#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,val;
};
int t,n,m,k,dist[505];
int main(){
	scanf("%d",&t);
	while(t--){
		vector<node> v;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			v.push_back({a,b,c});
			v.push_back({b,a,c});
		}
		for(int i=1;i<=k;i++){
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			v.push_back({a,b,-c});
		}
		int fl=0;
		for(int i=1;i<=n+1;i++){
			for(node nxt : v){
				if(dist[nxt.from]+nxt.val < dist[nxt.to]){
					if(i > n) fl=1;
					dist[nxt.to] = dist[nxt.from]+nxt.val;
				}
			}
		}
		printf("%s\n",fl?"YES":"NO");
		for(int i=1;i<=n;i++) dist[i]=0;
	}
}
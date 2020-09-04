#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int need, plus, val, id;
}castle[5050];
int n,m,k,ans,d[5050];
vector<int> v[5050];
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		castle[i] = {a, b, c};
	}
 
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		d[b]++;
	}
 
	for(int i=1;i<=n;i++){
		while(!pq.empty() && k < castle[i].need){
			k++;
			pq.pop();
		}
		if(k < castle[i].need) return !printf("-1");
 
		k += castle[i].plus;
		if(d[i] == 0 && k){
			k--;
			pq.push(castle[i].val);
		}else if(!k && !pq.empty() && pq.top() < castle[i].val){
			pq.pop();
			pq.push(castle[i].val);
		}
 
		for(int nxt : v[i]){
			--d[nxt];
			if(k && !d[nxt]){
				k--;
				pq.push(castle[nxt].val);
			}else if(!d[nxt] && !k && !pq.empty() && pq.top() < castle[nxt].val){
				pq.pop();
				pq.push(castle[nxt].val);
			}
		}
	}
 
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
 
	printf("%d",ans);
}
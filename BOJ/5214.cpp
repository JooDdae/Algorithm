#include<bits/stdc++.h>
using namespace std;
int n,m,k,chk[202020];
vector<int> v[202020];
queue<int> q,qc;
int main(){
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=k;j++){
    		int a; scanf("%d",&a);
    		v[i+n].push_back(a);
    		v[a].push_back(i+n);
    	}
    }
    q.push(1),qc.push(0);
    chk[1] = 1;
    while(!q.empty()){
    	int cur=q.front(),c=qc.front();
    	q.pop(),qc.pop();
    	if(cur == n) return !printf("%d",c/2+1);
    	for(int nxt : v[cur]) if(!chk[nxt]) chk[nxt]=1,q.push(nxt),qc.push(c+1);
    }
    printf("-1");
}
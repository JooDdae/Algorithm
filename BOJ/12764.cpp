#include<bits/stdc++.h>
using namespace std;
int n,chk[101010],cnt[101010],c;
priority_queue<pair<int,int>> pq;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	pq.push({-a,i});
    	pq.push({-b,i});
    }
    while(!pq.empty()){
    	int cur=pq.top().second;
    	pq.pop();
    	if(chk[cur]){
    		q.push(chk[cur]);
    		continue;
    	}

    	if(q.empty()) chk[cur]=++c;
    	else{
    		chk[cur]=q.top();
    		q.pop();
    	}
    }
    for(int i=1;i<=n;i++) cnt[chk[i]]++;
    printf("%d\n",c);
	for(int i=1;i<=c;i++) printf("%d ",cnt[i]);
}
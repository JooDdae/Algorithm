#include<bits/stdc++.h>
using namespace std;
int n,m,k;
pair<int,int> p[202020];
long long s;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d %d",&p[i].second,&p[i].first);
    sort(p+1,p+1+k);
	for(int i=1;i<=k;i++){
		s += p[i].second;
		pq.push(p[i].second);

		if(i>n){
			s -= pq.top();
			pq.pop();
		}

		if(s >= m) return !printf("%d",p[i].first);
	}
	puts("-1");
}
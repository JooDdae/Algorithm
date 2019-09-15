#include<bits/stdc++.h>
using namespace std;
int l,n;
pair<int,int> p[101010];
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	p[i] = {abs(a),i};
    	pq.push({a<0?a:-l+a,a});
    }
    sort(p+1, p+1+n);
    int l=1;
    while(pq.size() > 1){
    	if(pq.top().second < 0) l++;
    	pq.pop();
    }
    printf("%d %d",p[l].second,-pq.top().first);
}
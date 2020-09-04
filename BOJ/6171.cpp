#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, front, back = -1, i;
ll dp[50005], x[50005], y[50005];
priority_queue<pair<ll, ll>> pq;
bool f(int a,int b,int c){
    ll X1 = x[b] - x[a], X2 = x[c] - x[a], Y1 = y[b] - y[a], Y2 = y[c] - y[a];
    return X1 * Y2 >= X2 * Y1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll a,b; scanf("%lld %lld",&a,&b);
		pq.push({a, b});
	}
	int mx = 0;
	while(!pq.empty()){
		ll w = pq.top().first, h = pq.top().second; pq.pop();
		if(h <= mx) continue;
		mx = h;

		back++, i++;
		x[back] = w, y[back] = dp[i-1];
		while(front + 1 < back && f(back-2, back-1, back)){
			back--;
			x[back] = x[back+1], y[back] = y[back+1];
		}

		while(front < back && x[front] * h + y[front] > x[front+1] * h + y[front+1]) front++;
		dp[i] = x[front] * h + y[front];
	}
	printf("%lld",dp[i]);
}


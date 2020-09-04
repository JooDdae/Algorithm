#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c = 1, L;
map<ll, int> mp, mp2;
int main(){
	scanf("%lld %lld %lld",&a,&b,&L);
	for(ll i=2;i*i<=1e6;i++){
		int cnt = 0;
		while(a % i == 0){
			cnt++;
			a /= i;
		}
		if(cnt) mp[i] = cnt;
	}
	if(a > 1) mp[a] = 1;
	for(ll i=2;i*i<=1e6;i++){
		int cnt = 0;
		while(b % i == 0){
			cnt++;
			b /= i;
		}
		if(cnt) mp[i] = max(mp[i], cnt);
	}
	if(b > 1) mp[b] = 1;

	for(ll i=2;i*i<=1e12;i++){
		int cnt = 0;
		while(L % i == 0){
			cnt++;
			L /= i;
		}
		if(cnt) mp[i] -= cnt, mp2[i] = cnt;
	}
	if(L > 1) mp[L]--, mp2[L] = 1;

	for(auto it : mp){
		if(it.second > 0) return !printf("-1");
		if(it.second) while(mp2[it.first] > 0) c *= it.first, mp2[it.first]--;
	}
	printf("%lld",c);
}
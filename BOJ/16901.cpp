#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, trie[6006006][2], cnt;
ll a[200200];

ll find(int x){
	int cur = 0, re = 0;
	for(int i=29;i>=0;i--){
		int fl = x & (1<<i) ? 1 : 0;
		if(trie[cur][fl]) cur = trie[cur][fl];
		else re += (1<<i), cur = trie[cur][!fl];
	}
	return re;
}

ll f(int l, int r, int bit, int plus){
	if(!bit || l >= r) return 0;

	int it = lower_bound(a+l, a+r+1, plus + bit) - a;
	if(it == r+1) return f(l, r, bit>>1, plus);
	if(it == l) return f(l, r, bit>>1, plus+bit);

	for(int i=l;i<it;i++){
		int cur = 0;
		for(int j=29;j>=0;j--){
			int fl = (1<<j) & a[i] ? 1 : 0;
			if(!trie[cur][fl]) trie[cur][fl] = ++cnt;
			cur = trie[cur][fl];
		}
	}

	ll re = 1e18;
	for(int i=it;i<=r;i++) re = min(re, find(a[i]));
	for(int i=0;i<=cnt;i++) trie[i][0] = trie[i][1] = 0;
	cnt = 0;

	return re + f(l, it-1, bit>>1, plus) + f(it, r, bit>>1, plus+bit);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1, a+1+n);
	printf("%lld",f(1, n, 1<<29, 0));
}
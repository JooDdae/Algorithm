#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m;
ll a[1001001], b[1001001];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=m;i++) cin >> b[i];
		sort(a+1, a+1+n), sort(b+1, b+1+m);
		b[m+1] = 1e18;

		ll ans = 0, r = 1;

		for(int i=1;i<=n;i++){
			while(abs(a[i]-b[r]) > abs(a[i]-b[r+1])) r++;
			ans += b[r];
		}

		cout << ans << '\n';
	}
}
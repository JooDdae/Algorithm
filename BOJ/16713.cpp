#include<bits/stdc++.h>
using namespace std;
int n,q,a[1001001],ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) a[i] ^= a[i-1];
	while(q--){
		int b,c; cin >> b >> c;
		ans ^= a[c]^a[b-1];
	}
	cout << ans;
}
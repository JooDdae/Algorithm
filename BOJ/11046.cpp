#include<bits/stdc++.h>
using namespace std;
int n,a[2002002],p[2002002],r,k,q;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=2;i<=n*2;i+=2) cin >> a[i];

	for(int i=1;i<=n*2+1;i++){
		p[i] = max(min(r-i, p[2*k-i]), 0);
        while(i-p[i]>1 && i+p[i]<n*2+1 && a[i-p[i]-1]==a[i+p[i]+1]) p[i]++;
        if(i+p[i] > r) r=i+p[i],k=i;
	}

	cin >> q;
	while(q--){
		int b,c; cin >> b >> c;
		cout << (p[b+c] >= c-b) << '\n';
	}
}
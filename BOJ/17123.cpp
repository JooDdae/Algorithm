#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, a[1010][1010], b[1010][1010], r[1010], c[1010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j] = 0;
		for(int i=1;i<=n;i++) r[i] = c[i] = 0;

		while(m--){
			int r1, c1, r2, c2, v;
			cin >> r1 >> c1 >> r2 >> c2 >> v;
			for(int i=r1;i<=r2;i++) b[i][c1] += v, b[i][c2+1] -= v;
		}

		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j] += b[i][j-1], a[i][j] += b[i][j];

		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) r[i] += a[i][j], c[j] += a[i][j];
		for(int i=1;i<=n;i++) cout << r[i] << ' ';
		cout << '\n';
		for(int i=1;i<=n;i++) cout << c[i] << ' ';
		cout << '\n';
	}
}
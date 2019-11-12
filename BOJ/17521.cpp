#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,a[101010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
    	if(a[i] < a[i+1]) c += m/a[i], m %= a[i];
    	else m += c*a[i], c = 0;
    }
    cout << m + c*a[n];
}
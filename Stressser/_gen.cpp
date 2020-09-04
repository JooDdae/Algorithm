#include<bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll lb, ll ub){ return uniform_int_distribution<ll>(lb, ub)(rng); }

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << 1 << '\n' << randint(7817170,7817175) << '\n';
}
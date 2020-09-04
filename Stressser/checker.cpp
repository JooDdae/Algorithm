#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a, b, c;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	ifstream _res("./stress/in");
	ofstream _print("./print");

	_res >> n >> a;
	cin >> b >> c;

	if(b != -1){
		cout << (a % b == 0 && a % c == 0 && __gcd(b + c, a) == 1);
		return 0;
	}

	vector<ll> v;
	for(ll i = 2; i <= a; i++){
		if(a % i == 0) v.push_back(i);
	}


	for(auto x : v){
		for(auto y : v){
			if( __gcd(x + y, a) == 1){
				_print << x << ' ' << y;
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;
}
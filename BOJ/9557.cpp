#include<bits/stdc++.h>
using namespace std;
int t, n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--){
		string a, b, c;
		int fl = 0;
		cin >> n;
		for(int i=1;i<=n;i++){
			string s; cin >> s;
			if(fl) a += ' ' + s;
			else{
				if('a'<=s[0] && s[0]<='z') c = ' ' + s, fl = 1;
				else b += ' ' + s;
			}
		}
		a = a + c + b;
		cout << a.substr(1) << '\n';
	}
}
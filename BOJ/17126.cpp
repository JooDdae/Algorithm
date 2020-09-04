#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct query{
	int type, b;
	string a, c;
}q[100100];
int n, cnt;
ll tree[200200];
vector<string> v;
ll find(int bit){
	ll re = 0;
	while(bit){
		re += tree[bit];
		bit -= bit & -bit;
	}
	return re;
}
void update(int bit, ll val){
	while(bit <= cnt){
		tree[bit] += val;
		bit += bit & -bit;
	}
}
int f(string a){
	return 1 + lower_bound(v.begin(), v.end(), a,  [&](string a, string b){
		if(a.size() != b.size()) return a.size() < b.size();
		return a < b;
	}) - v.begin();
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> q[i].type >> q[i].a;
		if(q[i].type == 1){
			cin >> q[i].b;
			v.push_back(q[i].a);
		}

		if(q[i].type == 2){
			cin >> q[i].c;
		}

		if(q[i].type == 3){
			v.push_back(q[i].a);
		}
	}

	sort(v.begin(), v.end(), [&](string a, string b){
		if(a.size() != b.size()) return a.size() < b.size();
		return a < b;
	});
	v.erase(unique(v.begin(), v.end()), v.end());
	cnt = v.size();

	for(int i=1;i<=n;i++){
		int a = f(q[i].a);
		if(q[i].type == 1){
			update(a, q[i].b);
			cout << find(cnt) << ' ';
		}
		if(q[i].type == 2){
			int c = f(q[i].c);
			if(v[c-1] != q[i].c) c--;
			cout << find(c) - find(a-1) << ' ';
		}
		if(q[i].type == 3){
			ll f = find(a) - find(a-1);
			update(a, -f);
			cout << find(cnt) << ' ';
		}
	}
}
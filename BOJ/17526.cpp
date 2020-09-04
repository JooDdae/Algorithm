#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mid ((l+r)>>1)

struct node{
	ll x, y;
	int l, r;
};
vector<node> tree;

ll f(node u, ll a){
	return u.x * a + u.y;
}

int cross(node a, node b, ll x){
	ll X = a.x - b.x, Y = b.y - a.y;
	if(X < 0) X *= -1, Y *= -1;

	__int128 L = Y, R = x;
	R *= X;
	if(L > R) return 1;
	if(L < R) return -1;
	return 0;
}

void update(ll x, ll y, int u = 0, ll l = 0, ll r = 1e9){
	if(tree.empty()){
		tree.push_back({x, y, -1, -1});
		return;
	}

	node H = tree[u], L = {x, y, -1, -1};
	if(f(H, l) > f(L, l)) swap(H, L);
	tree[u].x = H.x, tree[u].y = H.y;
	if(f(H, r) <= f(L, r)) return;
	
	if(cross(H, L, mid) <= 0){
		tree[u].x = L.x, tree[u].y = L.y;
		if(tree[u].l == -1){
			tree[u].l = tree.size();
			tree.push_back({H.x, H.y, -1, -1});
		}else update(H.x, H.y, tree[u].l, l, mid);
	}else{
		if(tree[u].r == -1){
			tree[u].r = tree.size();
			tree.push_back({L.x, L.y, -1, -1});
		}else update(L.x, L.y, tree[u].r, mid+1, r);
	}
}

ll query(ll x, int u = 0, ll l = 0, ll r = 1e9){
	if(u < 0) return 2e18;
	return min(f(tree[u], x), x <= mid ? query(x, tree[u].l, l, mid) : query(x, tree[u].r, mid+1, r));
}

int n;
ll dp[100100], psum[100100], pace[100100], pre[100100];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=2;i<=n;i++){
		int a; cin >> a;
		psum[i] = psum[i-1] + a;
	}
	for(int i=1;i<n;i++) cin >> pre[i] >> pace[i];

	update(pace[1], pre[1]);
	for(int i=2;i<=n;i++){
		dp[i] = query(psum[i]);
		update(pace[i], pre[i] - psum[i] * pace[i] + dp[i]);
	}
    cout << dp[n];
}
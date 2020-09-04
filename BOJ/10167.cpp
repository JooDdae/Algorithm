#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct Coor{
	int x, y, w;
	bool operator < (const Coor &a) const{
		return x < a.x;
	}
}a[3030];
struct Node{
	ll l, r, mx, sum;
}tree[20020];
int n;
vector<int> vy;
ll ans;
void update(int node, int l, int r, int id, ll val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node].l += val;
		tree[node].r += val;
		tree[node].mx += val;
		tree[node].sum += val;
		return;
	}
	update(node*2, l, mid, id, val), update(node*2+1, mid+1, r, id, val);
	Node L = tree[node*2], R = tree[node*2+1];
	tree[node] = {max(L.l, L.sum+R.l), max(R.r, L.r+R.sum), max({L.mx, R.mx, L.r + R.l, L.sum + R.sum}), L.sum + R.sum};
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
	for(int i=1;i<=n;i++) vy.push_back(a[i].y);
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	for(int i=1;i<=n;i++) a[i].y = lower_bound(vy.begin(), vy.end(), a[i].y) - vy.begin() + 1;
	sort(a+1, a+1+n);
	for(int i=1;i<=n;){
		int j = i;
		while(j <= n){
			int x = a[j].x;
			while(a[j].x == x){
				update(1, 1, vy.size(), a[j].y, a[j].w);
				j++;
			}
			ans = max(ans, tree[1].mx);
		}
		for(int i=1;i<=4*n;i++) tree[i] = {0, 0, 0, 0};
		int x = a[i].x;
		while(x == a[i].x) i++;
	}
	printf("%lld",ans);
}
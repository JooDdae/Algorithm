#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n,m,a[250010],tree[65537 * 4];
ll ans;
int find(int node,int l,int r,int v){
	if(l == r) return l;

	if(tree[node*2] >= v) return find(node*2,l,mid,v);
	return find(node*2+1,mid+1,r,v-tree[node*2]);
}
void up(int node,int l,int r,int id,int v){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] += v;
		return;
	}
	up(node*2,l,mid,id,v);
	up(node*2+1,mid+1,r,id,v);
	tree[node] = tree[node*2] + tree[node*2+1];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		up(1,1,65537,++a[i],1);
		if(i >= m){
			ans += find(1,1,65537,(m+1)/2)-1;
			up(1,1,65537,a[i-m+1],-1);
		}
	}
	printf("%lld",ans);
}
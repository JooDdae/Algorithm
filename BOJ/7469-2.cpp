#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
int n,m,arr[101010];
vector<int> tree[404040];
void build(int node,int l,int r){
	if(l == r){
		tree[node].push_back(arr[l]);
		return;
	}
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].resize(tree[node*2].size() + tree[node*2+1].size());
	merge(tree[node*2].begin(),tree[node*2].end(),tree[node*2+1].begin(),tree[node*2+1].end(),tree[node].begin());
}
int f(int node,int l,int r,int nl,int nr,int x){
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return upper_bound(tree[node].begin(),tree[node].end(),x) - tree[node].begin();
	return f(node*2,l,mid,nl,nr,x) + f(node*2+1,mid+1,r,nl,nr,x);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    build(1,1,n);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		int l=-1e9,r=1e9;
		while(l<=r){
			if(f(1,1,n,a,b,mid) < c) l = mid+1;
			else r = mid-1;
		}
		printf("%d\n",l);
	}
}
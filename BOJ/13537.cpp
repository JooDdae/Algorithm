#include<bits/stdc++.h>
using namespace std;
int n,m,arr[101010];
vector<int> tree[404040];
void up(int node,int l,int r){
	if(l == r){
		tree[node].push_back(arr[l]);
		return;
	}
	up(node*2,l,(l+r)/2);
	up(node*2+1,(l+r)/2+1,r);
	tree[node].resize(tree[node*2].size() + tree[node*2+1].size());
	merge(tree[node*2].begin(),tree[node*2].end(),tree[node*2+1].begin(),tree[node*2+1].end(),tree[node].begin());
}
int f(int nl,int nr,int k,int node=1,int l=1,int r=n){
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node].size() - (upper_bound(tree[node].begin(),tree[node].end(),k) - tree[node].begin());
	return f(nl,nr,k,node*2,l,(l+r)/2) + f(nl,nr,k,node*2+1,(l+r)/2+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    up(1,1,n);
    scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",f(a,b,c));
	}
}
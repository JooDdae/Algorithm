#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<int,int> tree[404040];
pair<int,int> f2(pair<int,int> a,pair<int,int> b){
	pair<int,int> re = a;
	if(re.second < b.first) re.second = b.first;
	if(re.first < re.second) swap(re.first, re.second);
	if(re.second < b.second) re.second = b.second;
	if(re.first < re.second) swap(re.first, re.second);
	return re;
}
void up(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] = {val,0};
		return;
	}
	up(node*2,l,(l+r)/2,id,val);
	up(node*2+1,(l+r)/2+1,r,id,val);

	tree[node] = f2(tree[node*2], tree[node*2+1]);
}
pair<int,int> f(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l) return {0,0};
	if(nl<=l && r<=nr) return tree[node];
	return f2(f(node*2,l,(l+r)/2,nl,nr),f(node*2+1,(l+r)/2+1,r,nl,nr));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	up(1,1,n,i,a);
    }
    scanf("%d",&q);
    while(q--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	if(a == 1) up(1,1,n,b,c);
    	else{
    		pair<int,int> p = f(1,1,n,b,c);
    		printf("%d\n",p.first + p.second);
    	}
    }
}
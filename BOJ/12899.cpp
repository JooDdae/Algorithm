#include<bits/stdc++.h>
using namespace std;
int q,tree[8000008];
int up(int id,int val,int node=1,int l=1,int r=2000000){
	if(id<l || r<id) return id;
	if(l==r) tree[node] += val;
	else{
		up(id,val,node*2,l,(l+r)/2);
		up(id,val,node*2+1,(l+r)/2+1,r);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	return id;
}
int f(int k,int node=1,int l=1,int r=2000000){
	if(l==r) return l;
	if(k>tree[node*2]) return f(k-tree[node*2],node*2+1,(l+r)/2+1,r);
	return f(k,node*2,l,(l+r)/2);
}
int main(){
    scanf("%d",&q);
    while(q--){
    	int a,b; scanf("%d %d",&a,&b);
    	if(a==1) up(b,1);
    	else printf("%d\n",up(f(b),-1));
    }
}
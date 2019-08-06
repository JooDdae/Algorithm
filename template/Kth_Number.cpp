// boj.kr/2243
#include<bits/stdc++.h>
using namespace std;

#define MAX_M 1010101
#define mid ((l+r)>>1)

int q,tree[MAX_M*4];

void update(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] += val;
		return;
	}
	update(node*2,l,mid,id,val);
	update(node*2+1,mid+1,r,id,val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int find(int node,int l,int r,int val){
	if(l == r) return l;
	if(val > tree[node*2]) return find(node*2+1,mid+1,r,val-tree[node*2]);
	return find(node*2,l,mid,val);
}

int main(){
    scanf("%d",&q);
    while(q--){
    	int a,b,c; scanf("%d",&a);
    	if(a == 1){
    		scanf("%d",&b);
    		int fl = find(1,1,MAX_M,b);
    		printf("%d\n",fl);
    		update(1,1,MAX_M,fl,-1);
    	}else{
    		scanf("%d %d",&b,&c);
    		update(1,1,MAX_M,b,c);
    	}
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pw[10],n,m;
int tree[800080][10],chk[10],arr[10];
pair<int,int> tree2[808080][10];
pair<int,int> f(pair<int,int> a,pair<int,int> b){
	pair<int,int> c = a;
	if(b.first < c.first) c.second = c.first, c.first = b.first;
	else if(b.first < c.second) c.second = b.first;
	if(b.second < c.second) c.second = b.second;
	return c;
}
void up(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		for(int i=0;i<10;i++){
			tree[node][i] = val/pw[i]%10 ? 1 : 0;
			if(tree[node][i]) tree2[node][i] = {val,1e9};
			else tree2[node][i] = {1e9,1e9};
		}
		return;
	}
	up(node*2,l,(l+r)/2,id,val);
	up(node*2+1,(l+r)/2+1,r,id,val);
	for(int i=0;i<10;i++) tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
	for(int i=0;i<10;i++){
		tree2[node][i] = f(tree2[node*2][i], tree2[node*2+1][i]);
	}
}
void fnd(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		for(int i=0;i<10;i++) chk[i] += tree[node][i];
		return;
	}
	fnd(node*2,l,(l+r)/2,nl,nr);
	fnd(node*2+1,(l+r)/2+1,r,nl,nr);
}
pair<int,int> fnd2(int node,int j,int l,int r,int nl,int nr){
	if(r<nl || nr<l) return {1e9,1e9};
	if(nl<=l && r<=nr) return tree2[node][j];
	return f(fnd2(node*2,j,l,(l+r)/2,nl,nr),fnd2(node*2+1,j,(l+r)/2+1,r,nl,nr));
}
int main(){
    pw[0] = 1;
    for(int i=1;i<=9;i++) pw[i] = pw[i-1]*10;
    scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		up(1,1,n,i,a);
	}
	while(m--){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		if(a == 1) up(1,1,n,b,c);
		else{
			for(int i=0;i<10;i++) chk[i]=0;
			fnd(1,1,n,b,c);
			int fl=0;
			for(int i=0;i<10;i++) if(chk[i]>1) fl=1;
			if(!fl) printf("-1\n");
			else{
				int ans = 2e9;
				for(int i=0;i<10;i++) if(chk[i]>1){
					pair<int,int> p = fnd2(1,i,1,n,b,c);
					ans = min(ans, p.first + p.second);
				}
				printf("%d\n",ans);
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n,m,q,a[101010],w[1010101],tree[4040404],chk2[1010101];
pair<int,int> ans[101010];
ll chk[1010101];
struct node{
	int num, cnt, id;
	bool operator < (const node &a)const{
		return w[num] < w[a.num];
	};
};
vector<node> Q;
void up(int node,int l,int r,int id,int val){
	if(id < l || r < id) return;
	if(l == r) tree[node] += val;
	else{
		up(node*2,l,mid,id,val);
		up(node*2+1,mid+1,r,id,val);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}
int f(int node,int l,int r,int k){
	if(l == r) return l;
	if(k > mid-l+1-tree[node*2]) return f(node*2+1,mid+1,r,k-(mid-l+1-tree[node*2]));
	return f(node*2,l,mid,k);
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=m;i++) chk[i] = m,w[i] = n;
    for(int i=n;i>=1;i--){
    	chk[a[i]] = m - tree[1];
    	w[a[i]] = i;
    	if(!chk2[a[i]]++) up(1,1,m,a[i],1);
    }

    for(int i=1;i<=m;i++) chk[i] += chk[i-1];
    for(int i=1;i<=q;i++){
    	ll a; scanf("%lld",&a);
    	if(a > chk[m]){
    		ans[i] = {-1,-1};
    		continue;
    	}

    	int l=1,r=m;
    	while(l<=r){
    		if(chk[mid] >= a) r = mid-1;
    		else l = mid+1;
    	}
    	Q.push_back({l,(int)(a-chk[l-1]),i});
    }

    sort(Q.begin(),Q.end());
    int cur = 1;
    for(node x : Q){
    	while(cur <= w[x.num]){
    		if(chk2[a[cur]] == 1) up(1,1,m,a[cur],-1);
    		--chk2[a[cur++]];
    	}
    	ans[x.id] = {x.num, f(1,1,m,x.cnt)};
    }
    for(int i=1;i<=q;i++) printf("%d %d\n",ans[i].first,ans[i].second);
}
#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,id;
	bool operator < (const node &a)const{
		return make_pair(l>>9,r) < make_pair(a.l>>9,a.r);
	}
}q[101010];
int n,m,arr[101010],ans[101010];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) scanf("%d %d",&q[i].l,&q[i].r), q[i].id=i;
    sort(q+1,q+1+n);
	int l=0,r=0,s=0;
	for(int i=1;i<=n;i++){
		while(l < q[i].l) s -= arr[l++];
		while(r < q[i].r) s += arr[++r];
		while(l > q[i].l) s += arr[--l];
		while(r > q[i].r) s -= arr[r--];
		ans[q[i].id] = s;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
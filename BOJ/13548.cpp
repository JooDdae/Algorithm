#include<bits/stdc++.h>
using namespace std;
struct query{
	int l,r,id;
	bool operator < (const query &a)const{
		int L1 = l>>9, L2 = a.l>>9;
		return tie(L1, r) < tie(L2, a.r);
	}
}q[101010];
int n,m,arr[101010],cnt[101010],chk[101010],ans[101010],mx;
void f1(int a){
	if(cnt[a]==mx && chk[cnt[a]]==1) mx--;
	chk[cnt[a]]--;
	cnt[a]--;
}
void f2(int a){
	if(++cnt[a] > mx) mx++;
	chk[cnt[a]]++;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
   	cin >> m;
    for(int i=1;i<=m;i++) cin >> q[i].l >> q[i].r, q[i].id=i;
    sort(q+1,q+1+m);
	int l=0,r=0;
	for(int i=1;i<=m;i++){
		while(l > q[i].l) f2(arr[--l]);
		while(r < q[i].r) f2(arr[++r]);
		while(l < q[i].l) f1(arr[l++]);
		while(r > q[i].r) f1(arr[r--]);
		ans[q[i].id] = mx;
	}
	for(int i=1;i<=m;i++) cout << ans[i] << "\n";
}
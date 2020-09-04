#include<bits/stdc++.h>
using namespace std;
struct node{
	int x, y, z;
	bool operator < (const node &a) const{
		return x < a.x;
	}
}a[500500];
int n, tree[500500], ans;
void update(int bit, int val){
	while(bit <= n){
		tree[bit] = min(tree[bit], val);
		bit += bit & -bit;
	}
}
int find(int bit){
	int re = 1e9;
	while(bit){
		re = min(re, tree[bit]);
		bit -= bit & -bit;
	}
	return re;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int b; scanf("%d",&b);
		a[b].x = i;
	}
	for(int i=1;i<=n;i++){
		int b; scanf("%d",&b);
		a[b].y = i;
	}
	for(int i=1;i<=n;i++){
		int b; scanf("%d",&b);
		a[b].z = i;
	}
	sort(a+1, a+1+n);
	for(int i=1;i<=n;i++){
		if(find(a[i].y) >= a[i].z-n) ans++;
		update(a[i].y, a[i].z-n);
	}
	printf("%d",ans);
}
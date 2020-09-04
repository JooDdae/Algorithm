#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
int n, m, mp[1515][1515], tree[6060][6060];

int InitY(int id, int l, int r, int y, int L){
	if(l == r) return tree[id][y] = mp[l][L];
	return tree[id][y] = max(InitY(id*2, l, mid, y, L), InitY(id*2+1, mid+1, r, y, L));
}
void InitY2(int id, int l, int r, int y){
	tree[id][y] = max(tree[id][y*2], tree[id][y*2+1]);
	if(l == r) return;
	InitY2(id*2, l, mid, y);
	InitY2(id*2+1, mid+1, r, y);
}
void InitX(int id, int l, int r){
	if(l == r){
		InitY(1, 1, 1500, id, l);
		return;
	}
	InitX(id*2, l, mid);
	InitX(id*2+1, mid+1, r);
	InitY2(1, 1, 1500, id);
}
int QueryY(int id, int l, int r, int y, int yy, int L){
	if(r<y || yy<l) return 0;
	if(y<=l && r<=yy) return tree[L][id];
	return max(QueryY(id*2, l, mid, y, yy, L), QueryY(id*2+1, mid+1, r, y, yy, L));
}
int QueryX(int id, int l, int r, int x, int y, int xx, int yy){
	if(r<x || xx<l) return 0;
	if(x<=l && r<=xx) return QueryY(1, 1, 1500, y, yy, id);
	return max(QueryX(id*2, l, mid, x, y, xx, yy), QueryX(id*2+1, mid+1, r, x, y, xx, yy));
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d);
		a++, b++, c++, d++;
		mp[a][b]++;
		mp[a][d]--;
		mp[c][b]--;
		mp[c][d]++;
	}

	for(int i=1;i<=1500;i++){
		for(int j=1;j<=1500;j++){
			mp[i][j] += mp[i][j-1] + mp[i-1][j] - mp[i-1][j-1];
		}
	}

	InitX(1, 1, 1500);

	for(int i=1;i<=m;i++){
		int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",QueryX(1, 1, 1500, a+1, b+1, c, d));
	}
}
#include<bits/stdc++.h>
using namespace std;
int mp[10][10], r[10][10], c[10][10], b[10][10];
bool find(int cur){
	if(cur % 10 == 0) cur++;
	if(cur > 99) return 1;

	int x = cur/10, y = cur%10;
	if(mp[x][y]) return find(cur+1);

	for(int i=1;i<=9;i++){
		if(r[x][i] || c[y][i] || b[(x-1)/3*3 + (y-1)/3 + 1][i]) continue;
		r[x][i] = c[y][i] = b[(x-1)/3*3 + (y-1)/3 + 1][i] = 1;
		mp[x][y] = i;
		if(find(cur+1)) return 1;
		r[x][i] = c[y][i] = b[(x-1)/3*3 + (y-1)/3 + 1][i] = 0;
	}
	mp[x][y] = 0;
	return 0;
}
int main(){
	for(int i=1;i<=9;i++) for(int j=1;j<=9;j++) scanf("%01d",mp[i]+j);
	for(int i=1;i<=9;i++) for(int j=1;j<=9;j++) r[i][mp[i][j]] = c[j][mp[i][j]] = b[(i-1)/3*3 + (j-1)/3 + 1][mp[i][j]] = 1;
	find(11);
	for(int i=1;i<=9;i++,puts("")) for(int j=1;j<=9;j++) printf("%d",mp[i][j]);
}
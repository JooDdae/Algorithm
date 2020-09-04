#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, cnt[30];
char mp[111][111], s[111], chk[111][111], dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
queue<int> qx[30], qy[30];
int main(){
	scanf("%d",&t);
	while(t--){
		int ans = 0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
		scanf("%s",s);
		for(int i=0;s[i];i++){
			if(s[i] == '0') break;
			cnt[s[i]-'a'+1] = 1;
		}
		for(int i=0;i<=n+1;i++) mp[i][0] = mp[i][m+1] = '.';
		for(int j=0;j<=m+1;j++) mp[0][j] = mp[n+1][j] = '.';
		chk[0][0] = 1;
		qx[0].push(0), qy[0].push(0);
		while(!qx[0].empty()){
			int x = qx[0].front(), y = qy[0].front();
			qx[0].pop(), qy[0].pop();
			if(mp[x][y] == '$') ans++;

			for(int i=0;i<4;i++){
				int xx = x+dx[i], yy = y+dy[i];
				if(xx<0 || yy<0 || xx>n+1 || yy>m+1 || chk[xx][yy] || mp[xx][yy] == '*') continue;
				char u = mp[xx][yy];
				int f = u - 'a' + 1;
				if('a'<=u && u<='z' && !cnt[f]){
					cnt[f] = 1;
					while(!qx[f].empty()){
						chk[qx[f].front()][qy[f].front()] = 1;
						qx[0].push(qx[f].front()); qx[f].pop();
						qy[0].push(qy[f].front()); qy[f].pop();
					}
				}

				f = u - 'A' + 1;
				if('A'<=u && u<='Z' && !cnt[f]){
					qx[f].push(xx), qy[f].push(yy);
				}else{
					chk[xx][yy] = 1;
					qx[0].push(xx), qy[0].push(yy);
				}
			}
		}

		printf("%d\n",ans);
		for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) chk[i][j] = 0;
		for(int i=0;i<30;i++) cnt[i] = 0;
		for(int i=0;i<30;i++) while(!qx[i].empty()) qx[i].pop(), qy[i].pop();
	}
}
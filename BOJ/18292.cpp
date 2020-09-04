#include<bits/stdc++.h>
using namespace std;
int N, M, K, dp[11][11][111][1<<10], mp[11][11], lx, ly, ans = -1e9;
int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) scanf("%d",mp[i]+j);

	for(int i=0;i<=N;i++) for(int j=0;j<=M;j++) for(int k=0;k<=K;k++) for(int l=0;l<(1<<M);l++) dp[i][j][k][l] = -1e9;
	dp[0][0][0][0] = 0;

	int mask = (1<<M)-1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			for(int k=0;k<=K;k++){
				for(int l=0;l<(1<<M);l++){
					dp[i][j][k][(l<<1) & mask] = max(dp[i][j][k][(l<<1) & mask], dp[lx][ly][k][l]);
					if((j == 1 || !(l & 1)) && !(l & (1<<(M-1)))) 
						dp[i][j][k+1][((l<<1) & mask)+1] = max(dp[i][j][k+1][((l<<1) & mask)+1], dp[lx][ly][k][l] + mp[i][j]);
				}
			}
			lx = i, ly = j;
		}
	}

	for(int i=0;i<(1<<M);i++) ans = max(ans, dp[N][M][K][i]);
	printf("%d",ans);
}
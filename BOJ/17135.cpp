#include<bits/stdc++.h>
using namespace std;
int n,m,d,mp[20][20],st[20][20],c[3],x[3],y[3];
int f(int a,int t){
	int re = 0;
	if(t == 3){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mp[i][j] = st[i][j];

		for(int k=1;k<=n;k++){
			for(int l=0;l<3;l++){
				x[l] = 19, y[l] = 19;
				int mn = 1e9;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						int dist = abs(n+1-i) + abs(c[l]-j);
						if(!mp[i][j] || dist > d || dist > mn) continue;
						if(dist == mn){
							if(j < y[l]) x[l] = i, y[l] = j;
						}else{
							mn = dist;
							x[l] = i, y[l] = j;
						}
					}
				}
			}
			
			for(int l=0;l<3;l++) if(mp[x[l]][y[l]]) mp[x[l]][y[l]] = 0, re++;
			for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) mp[i][j] = mp[i-1][j];
		}

		return re;
	}
	for(int i=a+1;i<=m;i++){
		c[t] = i;
		re = max(re, f(i, t+1));
	}
	return re;
}
int main(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&st[i][j]);
	printf("%d",f(0,0));
}
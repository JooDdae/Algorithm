#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mp[111][111],ans;
int f(int x,int y){
	int re = 0;
	for(int i=0;i<=100-x;i++){
		for(int j=0;j<=100-y;j++){
			if(mp[i+x][j+y] + mp[x-1][y-1] - mp[x-1][j+y] - mp[i+x][y-1] == (i+1)*(j+1)) re = max(re, (i+1)*(j+1));
		}
	}
	return re;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		for(int j=0;j<10;j++) for(int k=0;k<10;k++) mp[a+j][k+b]=1;
	}

	for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) mp[i][j] += mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1];
	
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(mp[i][j]) ans = max(ans, f(i,j));
		}
	}
	printf("%d",ans);
}
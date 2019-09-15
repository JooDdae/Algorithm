#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[2020],b[2020],dp[2020][2020],ans=1e9;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) b[i]=a[i];
    sort(b+1,b+1+n);
	for(int k=0;k<2;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(j==1?1000000000:dp[i][j-1], dp[i-1][j] + abs(a[i]-b[j]));
				if(i==n) ans = min(ans, dp[i][j]);
			}
		}
		reverse(a+1, a+1+n);
	}
	printf("%d",ans);
}
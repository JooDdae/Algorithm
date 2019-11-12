#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk[2010][2010][2],x[202],y[202],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(i!=j){
			int X = x[i] - x[j], Y = y[i] - y[j];
			int fl = X*Y < 0;
			if(Y == 0){
				if(chk[0][0][0]++ == 0) ans++;
			}else if(X == 0){
				if(chk[0][0][1]++ == 0) ans++;
			}else{
				X = abs(X), Y = abs(Y);
				if(chk[X/__gcd(X,Y)][Y/__gcd(X,Y)][fl]++ == 0) ans++;
			}
		}
	}

	printf("%d",ans);
}
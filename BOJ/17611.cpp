#include<bits/stdc++.h>
using namespace std;
int n,x[100100],y[100100],X[1001001],Y[1001001],ans,m=500001;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",x+i,y+i);
	for(int i=1;i<=n;i++){
		if(x[i] != x[i%n+1]) X[min(x[i], x[i%n+1])+m]++, X[max(x[i], x[i%n+1])+m]--;
		else Y[min(y[i], y[i%n+1])+m]++, Y[max(y[i], y[i%n+1])+m]--;
	}
	for(int i=1;i<=1000001;i++) ans=max({ans, X[i]+=X[i-1], Y[i]+=Y[i-1]});
	printf("%d",ans);
}
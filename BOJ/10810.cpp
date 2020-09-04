#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,chk[111],x[111],y[111],c[111];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d %d %d",x+i,y+i,c+i);

	for(int i=m;i>=1;i--) for(int j=x[i];j<=y[i];j++) if(!chk[j]) chk[j] = c[i];

	for(int i=1;i<=n;i++) printf("%d ",chk[i]);
}
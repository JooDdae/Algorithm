#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[22][22], ans;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int b; scanf("%d",&b);
		a[i][b] = j;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) if(i != j){
			int fl = 1;
			for(int k=1;k<=n;k++) if(a[k][i] > a[k][j]) fl = 0;
			ans += fl;
		}
	} 
	printf("%d",ans);
}
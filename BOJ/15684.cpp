#include<bits/stdc++.h>
using namespace std;
int n,k,m,chk[33][33],ans=4,cur[33];
bool f(int a,int c){
	if(a > n || c == 3){
		for(int i=1;i<=m;i++) cur[i] = i;
		for(int i=1;i<=n;i++) for(int j=1;j<m;j++) if(chk[i][j]) swap(cur[j],cur[j+1]);
		for(int i=1;i<=m;i++) if(cur[i] != i) return false;
		ans = min(ans, c);
		return true;
	}

	bool fl = false;
	fl |= f(a+1,c);
	for(int i=1;i<m;i++){
		if(chk[a][i-1] || chk[a][i] || chk[a][i+1]) continue;
		chk[a][i] = 1;
		fl |= f(a,c+1);
		chk[a][i] = 0;
	}
	return fl;
}
int main(){
    scanf("%d %d %d",&m,&k,&n);
    for(int i=1;i<=k;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	chk[a][b] = 1;
    }
    printf("%d",f(1,0)?ans:-1);
}
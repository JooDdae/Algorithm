#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s[2020][2020],l[20202],r[20202],mn=1e9,mnn;
char d[2020];
int main(){
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
    	scanf(" %c",&d[i]);
    	for(int j=1;j<=m;j++){
    		scanf(" %1d",&s[i][j]);
    		if(d[i] == 'L') l[j] += s[i][j];
    		if(d[i] == 'R') r[j] += s[i][j];
    	}
    }

    for(int i=1;i<=n;i++){
    	int a=0,c=0;
    	for(int j=1;j<=m;j++){
    		a = a - l[j] + r[j];
    		if(d[i] == 'L') a += s[i][j];
    		if(d[i] == 'R') a -= s[i][j];
    		c = max(c, abs(a));
    	}
    	if(mn > c) mn=c,mnn=i;
    }

    printf("%d\n%d",mnn,mn);
}
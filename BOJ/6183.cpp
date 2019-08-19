#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[1010];
char name[1010][1010], s[33];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",name[i]);
    for(int i=1;i<=n;i++) for(int j=0;name[i][j];j++) if('A'<=name[i][j] && name[i][j]<='Z') name[i][j] = name[i][j] - 'A' + 'a';
    for(int i=1;i<=m;i++){
    	scanf("%s",s);
    	for(int j=0;s[j];j++) if('A'<=s[j] && s[j]<='Z') s[j] = s[j]-'A'+'a';
    	for(int j=1;j<=n;j++){
    		int l=0;
    		for(int k=0;name[j][k];k++) if(name[j][k] == s[l]) l++;
    		if(!s[l]) cnt[j]++;
    	}
    }
    for(int i=1;i<=n;i++) printf("%d\n",cnt[i]);
}
#include<bits/stdc++.h>
using namespace std;
char s[1010];
int ans,n;
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i=1;i<=n;i++){
    	if(s[i] == 'Y'){
    		ans++;
    		for(int j=i;j<=n;j+=i) s[j] = s[j]=='Y'?'N':'Y';
    	}
    }
    printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[101010];
int n,cnt[101010],sz[101010],c,z=-1,fl;
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i=1;i<=n;i++){
    	if(s[i-1]=='1' && s[i]=='0') cnt[++fl] = c, sz[fl] = ++z, c = 0, z = 0;
    	else if(s[i] == '1') c++,z++;
    	else z++;
    }
    if(z) cnt[++fl] = c, sz[fl] = ++z;
    for(int i=1;i<=fl;i++) printf("%d %d\n",cnt[i],sz[i]);
}
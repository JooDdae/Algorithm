#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[111];
int n,m;
int main(){
    scanf("%s",s);
    n = strlen(s);
    for(int i=1;i*i<=n;i++) if(n%i == 0)  m = i;
    for(int i=0;i<m;i++) for(int j=i;j<n;j+=m) printf("%c",s[j]);
}

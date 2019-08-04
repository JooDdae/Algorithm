#include <bits/stdc++.h>
using namespace std;
char s[111];
int n,ans;
int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n-2;i++){
        if(s[i]+1 == s[i+1]){
            int j = i;
            while(j<n && s[j]+1 == s[j+1]) j++;
            if(j - i == 2) ans++;
            i = j;
        }
    }
    printf("%d",ans);
}

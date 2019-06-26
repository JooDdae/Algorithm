#include <bits/stdc++.h>
using namespace std;
char s[111];
int sc,ans;
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if('0'<=s[i] && s[i]<='9') ans=max(ans, sc);
        else if(s[i] == ')') sc -= 1;
        else if(s[i] == '}') sc -= 2;
        else if(s[i] == ']') sc -= 3;
        else if(s[i] == '(') sc += 1;
        else if(s[i] == '{') sc += 2;
        else if(s[i] == '[') sc += 3;
    }
    printf("%d",ans);
}

#include <cstdio>
char s[111];
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i++) printf("%c",s[i]^(s[0]^'C'));
}

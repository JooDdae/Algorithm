#include<cstdio>
char s[10101];
int main(){
	scanf("%*d");
	while(~scanf("%s",s)) printf("%d\n",s[0]==s[1]&&s[1]==s[4]&&s[2]==s[3]&&s[3]==s[5]&&s[5]==s[6]&&s[0]!=s[6]&&!s[7]&&s[6]);
}
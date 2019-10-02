#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[3][10];
int a,b;
int main(){
	for(int i=0;i<3;i++) scanf("%s",s[i]);
	a = (s[0][0] == 't');
	b = (s[2][0] == 't');
	if(s[1][0] == 'O') printf("%s",a|b?"true":"false");
	else printf("%s",a&b?"true":"false");
}
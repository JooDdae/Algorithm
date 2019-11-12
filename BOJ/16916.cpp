#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
char s[1001001], p[1001001];
int len;
ull h1,h2,m=1e4+7,m1;
int main(){
	scanf("%s %s",s,p);

	len = strlen(p);
	m1 = 1;
	for(int i=1;i<len;i++) m1 *= m;

	for(int i=0;i<len;i++) h1 = h1*m + p[i]-'a'+1;
	for(int i=0;i<len;i++) h2 = h2*m + s[i]-'a'+1;
	
	for(int i=len,l=strlen(s);i<=l;i++){
		if(h1 == h2) return !printf("1");
		h2 = (h2 - (s[i-len]-'a'+1)*m1) * m + s[i]-'a'+1;
	}
	
	printf("0");
}
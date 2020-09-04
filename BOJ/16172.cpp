#include<bits/stdc++.h>
using namespace std;
char in[200200], s[400400];
int z[400400], len, len2;
int main(){
	scanf("%s %s",in,s+1);
	len = len2 = strlen(s+1);
	s[++len] = '#';
	for(int i=0;in[i];i++) if(!('0'<=in[i] && in[i]<='9')) s[++len] = in[i];

	for(int i=2, l=0, r=0;i<=len;i++){
		if(i <= r) z[i] = min(z[i-l], r-i);
		while(i+z[i]<len && s[i+z[i]+1] == s[z[i]+1]) z[i]++;
		if(i+z[i] > r) r = i+z[i], l = 1;

		if(z[i] == len2) return !printf("1");
	}
	printf("0");
}
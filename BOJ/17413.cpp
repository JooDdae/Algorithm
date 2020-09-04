#include<bits/stdc++.h>
using namespace std;
char s[100100];
int l=1, r, fl;
int main(){
	scanf("%[^\n]s",s+1);
	for(int i=1;s[i];i++){
		if(s[i] == '<') reverse(s+l,s+i), fl = 1;
		if(s[i] == '>') l = i+1, fl = 0;
		if(s[i] == ' ' && !fl) reverse(s+l,s+i), l = i+1;
		r = i;
	}
	if(s[r] != '>') reverse(s+l, s+r+1);
	printf("%s",s+1);
}
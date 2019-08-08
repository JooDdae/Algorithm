#include<bits/stdc++.h>
using namespace std;
char s[1010101];
int n,fl;
int f(int x){
	if(x < 10){
		fl = x%3;
		return 1;
	}
	int sum=0;
	while(x){
		sum += x%10;
		x/=10;
	}
	return f(sum)+1;
}
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i++) n += s[i]-'0';
    if(strlen(s) == 1) return !printf("0\n%s",n%3?"NO":"YES");
    printf("%d\n",f(n));
    printf("%s",fl?"NO":"YES");
}
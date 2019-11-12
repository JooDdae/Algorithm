#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[20];
int t,fl,fl2;
int main(){
	scanf("%*d %s",s);
	for(int i=0;s[i];i++){
		if(s[i] == 'W') t++;
		else{
			if(t == 1) fl2 = 1;
			if(t < 1) fl = !fl;
		}
	}
	if(t < 2) return !printf("0");
	printf("%d",fl2?6:fl?1:5);
}
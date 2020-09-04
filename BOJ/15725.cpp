#include<bits/stdc++.h>
using namespace std;
char s[30];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i] == 'x'){
			if(i == 0) return !printf("1");
			else if(i == 1 && s[0] == '-') return !printf("-1");
			s[i] = 0;
			return !printf("%s",s);
		}
	}
	printf("0");
}
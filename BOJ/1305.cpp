#include<bits/stdc++.h>
using namespace std;
int n, z[1001001];
char s[1001001];
int main(){
	scanf("%d %s",&n,s+1);
	for(int i=1, l=0, r=0;i<=n;i++){
		if(i <= r) z[i] = min(r-i, z[i-l]);
		while(i+z[i] < n && s[i+z[i]+1] == s[z[i]+1]) z[i]++;
		if(r < i + z[i]) r = i + z[i], l = i;
		if(r == n) return !printf("%d",i);
	}
}
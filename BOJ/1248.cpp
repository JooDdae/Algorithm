#include<bits/stdc++.h>
using namespace std;
int n, a[11], chk[21];
char s[100];
bool f(int c){
	if(c > n) return true;
	
	int mn = -10, mx = 10, cnt = c;
	for(int i=1;i<=c;i++){
		if(s[cnt] == '+') mn = max(mn, -a[c-1]+a[i-1]+1);
		if(s[cnt] == '-') mx = min(mx, -a[c-1]+a[i-1]-1);
		if(s[cnt] == '0') mn = max(mn, -a[c-1]+a[i-1]), mx = min(mx, -a[c-1]+a[i-1]);
		cnt += n-i;
	}

	for(int i=mn;i<=mx;i++){
		if(!chk[i+10]){
			chk[i+10] = 1;
			a[c] = i + a[c-1];
			if(f(c+1)) return true;
			chk[i+10] = 0;
		}
	}

	return false;
}
int main(){
	scanf("%d %s",&n,s+1);
	f(1);
	for(int i=1;i<=n;i++) printf("%d ",a[i]-a[i-1]);
}
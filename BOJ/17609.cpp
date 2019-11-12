#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
char s[101010];
int f(int l,int r,int cur){
	for(int i=cur;i+l<n-i+1-r;i++) if(s[i+l] != s[n-i+1-r]) return 2;
	return 1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n = strlen(s+1);
		int fl=0;
		for(int i=1;i<n-i+1;i++){
			if(s[i] != s[n-i+1]){
				fl = 2;
				if(s[i] == s[n-i]) fl = min(fl,f(0,1,i));
				if(s[i+1] == s[n-i+1]) fl = min(fl,f(1,0,i));
				break;
			}
		}
		printf("%d\n",fl);
	}
}
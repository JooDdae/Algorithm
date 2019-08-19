#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[10];
int f(int a){
	int re=0;
	while(a){
		re = re*10 + a%10;
		a/=10;
	}
	return re;
}
bool f2(int a){
	int c=0;
	while(a){
		cnt[++c] = a%10;
		a/=10;
	}
	for(int i=1;i<=c/2;i++) if(cnt[i] != cnt[c-i+1]) return false;
	return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	printf("%s\n",f2(n+f(n))?"YES":"NO");
    }
}
#include<bits/stdc++.h>
using namespace std;
int t;
int f(int l,int r){
	int a = 31-__builtin_clz(l+1), b = 31-__builtin_clz(r+1);
	if(!(r&r+1)){
		int t = max(l-(1<<b)+b, 0);
		return (b*(b-1) - t*(t-1))/2+1;
	}
	int x = (1<<b)-1;
	if(a == b) return f(l-x, r-x) + b;
	return max(f(l, x), f(1, r-x) + b);
}
int main(){
	scanf("%d",&t);
	while(t--){
		int a,b; scanf("%d %d",&a,&b);
		printf("%d\n",f(a,b));
	}
}

2^k-k
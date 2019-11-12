#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[20],chk[4004004],sum;
int f(int l,int r,int m){
	if(m == n){
		if(r-l <=0 || chk[r-l]) return 0;
		return chk[r-l] = 1;
	}
	return f(l,r,m+1) + f(l+a[m+1],r,m+1) + f(l,r+a[m+1],m+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) sum += a[i];
	printf("%d",sum - f(0,0,0));
}
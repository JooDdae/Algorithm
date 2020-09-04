#include<bits/stdc++.h>
using namespace std;
int n, a[22][22], L[22], R[22];
int f(int c, int l, int r, int ls, int rs){
	if(c > n) return abs(ls - rs);

	int re = 1e9, sum = 0;
	for(int i=1;i<=l;i++) sum += a[L[i]][c] + a[c][L[i]];
	L[++l] = c;
	re = min(re, f(c+1, l, r, ls+sum, rs));

	sum = 0;
	for(int i=1;i<=r;i++) sum += a[R[i]][c] + a[c][R[i]];
	R[++r] = c;
	re = min(re, f(c+1, l-1, r, ls, rs+sum));

	return re;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
	printf("%d",f(1,0,0,0,0));
}
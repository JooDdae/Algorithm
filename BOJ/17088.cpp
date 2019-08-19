#include<bits/stdc++.h>
using namespace std;
int n,arr[101010],ans=1e9;
int f(int st,int a){
	int re=0;
	for(int i=2;i<=n;i++){
		st -= a;
		if(abs(arr[i] - st) > 1) return 1e9;
		re += abs(arr[i] - st);
	}
	return re;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    if(n < 3) return !printf("0");
	for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) ans = min(ans, f(arr[1]+i,arr[1]+i-arr[2]-j)+(i!=0));
    printf("%d",ans>n?-1:ans);
}
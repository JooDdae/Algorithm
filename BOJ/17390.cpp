#include<bits/stdc++.h>
using namespace std;
int n,q,arr[303030];
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1, arr+1+n);
	for(int i=2;i<=n;i++) arr[i] += arr[i-1];
	while(q--){
		int a,b; scanf("%d %d",&a,&b);
		printf("%d\n",arr[b]-arr[a-1]);
	}
}
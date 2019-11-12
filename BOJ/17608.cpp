#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mx,a[100100],n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=n;i>=1;i--) if(mx < a[i]) mx=a[i],cnt++;
	printf("%d",cnt);
}
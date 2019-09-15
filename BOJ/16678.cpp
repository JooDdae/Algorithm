#include<bits/stdc++.h>
using namespace std;
int n,arr[101010],mx;
typedef long long ll;
ll cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		if(mx < arr[i]){
			cnt += arr[i]-mx-1;
			mx++;
		}
	}
	printf("%lld",cnt);
}
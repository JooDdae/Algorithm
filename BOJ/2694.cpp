#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,arr[10101];
bool f(int a){
	int cur = 0;
	while(cur < n){
		int l=cur+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(arr[mid] - arr[cur] > a) r = mid-1;
			else if(arr[mid] - arr[cur] < a) l = mid+1;
			else{
				l = mid;
				break;
			}
		}
		if(arr[l] - arr[cur] != a) return false;
		cur = l;
	}
	return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    	for(int i=1;i<=n;i++) arr[i] += arr[i-1];
    	for(int i=1;i<=n;i++) if(arr[n]%arr[i] == 0 && f(arr[i])){
    		printf("%d\n",arr[i]);
    		break;
    	}
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[20202],ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		int l=i+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]+a[i] > m) r=mid-1;
			else l=mid+1; 
		}
		ans += l-i-1;
	}
	printf("%d",ans);
}
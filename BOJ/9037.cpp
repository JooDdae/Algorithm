#include<bits/stdc++.h>
using namespace std;
int t,n,a[11],b[11];
bool f(){
	for(int i=2;i<=n;i++) if(a[i] != a[1]) return true;
	return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    	for(int i=1;i<=n;i++) a[i] += a[i]%2;
    	int ans=0;
    	while(f()){
    		for(int i=1;i<=n;i++) b[i%n+1] = a[i]/2;
    		for(int i=1;i<=n;i++) a[i] = b[i]+b[i%n+1];
    		for(int i=1;i<=n;i++) a[i] += a[i]%2;
    		ans++;
    	}
    	printf("%d\n",ans);
    }
}
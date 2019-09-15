#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1010],b[1010],c[1010],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
    	b[i] = 1;
    	for(int j=1;j<i;j++) if(a[i] < a[j]) b[i] = max(b[i], b[j]+1);
    }
    for(int i=n;i>=1;i--){
    	c[i] = 1;
    	for(int j=n;j>i;j--) if(a[i] < a[j]) c[i] = max(c[i], c[j]+1);
    }
	
	for(int i=1;i<=n;i++) ans=max(ans,b[i]+c[i]-1);
	printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
int t,n,arr[303],chk[1000100];
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    	int ans=0;
    	while(++ans){
    		int fl=0;
    		for(int i=1;i<=n;i++){
    			if(chk[arr[i]%ans] == ans){
    				fl=1; break;
    			}
    			chk[arr[i]%ans] = ans;
    		}
    		if(!fl) break;
    	}
    	printf("%d\n",ans);
    	for(int i=0;i<=ans;i++) chk[i]=0;
    }
}
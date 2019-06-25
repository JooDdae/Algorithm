#include<bits/stdc++.h>
using namespace std;
int n,arr[2020],f[2020],b[2020],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(arr[i] > arr[j]) f[i] = max(f[i],f[j]+1);
            if(arr[i] < arr[j]) b[i] = max(b[i],b[j]+1);
        }
        ans = max(ans, f[i]+b[i]+1);
    }
    printf("%d",ans);
}

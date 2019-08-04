#include <bits/stdc++.h>
using namespace std;
int n,arr[55],m,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    scanf("%d",&m);
    int it = max_element(arr+1,arr+1+n) - arr;
    for(int i=1;i<arr[it];i++){
        for(int j=i+1;j<arr[it];j++){
            if(!(i<=m&&m<=j)) continue;
            int fl=0;
            for(int k=1;k<=n;k++) if(i<=arr[k]&&arr[k]<=j) fl = 1;
            cnt += !fl;
        }
    }
    printf("%d",cnt);
}

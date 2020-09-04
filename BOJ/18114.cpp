#include<bits/stdc++.h>
using namespace std;
int n,m,a[5050];
map<int,int> mp;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=1;i<=n;i++) mp[a[i]]++;

    for(int i=1;i<=n;i++) if(a[i] == m) return !printf("1");
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i] + a[j] == m) return !printf("1");
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(mp.count(m - (a[i] + a[j])) && mp[m - (a[i] + a[j])] > (a[i] == m - (a[i] + a[j])) + (a[j] == m - (a[i] + a[j]))) return !printf("1");
    printf("0");
}
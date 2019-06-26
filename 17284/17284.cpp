#include <bits/stdc++.h>
using namespace std;
int n,a[3]={500,800,1000},ans;
int main(){
    while(scanf("%d",&n) != EOF) ans += a[n-1];
    printf("%d",5000-ans);
}

#include<bits/stdc++.h>
using namespace std;
int n,ans[11];
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) v.push_back(i);
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        ans[v[a]] = i;
        v.erase(v.begin() + a);
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

#include<bits/stdc++.h>
using namespace std;
int n,ans[1010];
pair<int,int> p[1010];
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i].first);
    for(int i=1;i<=n;i++) p[i].second = i;
    sort(p+1,p+1+n);
	for(int i=1;i<=n;i++) ans[p[i].second] = i;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]-1);
}
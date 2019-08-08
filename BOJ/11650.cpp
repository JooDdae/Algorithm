#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> p[101010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&p[i].first,&p[i].second);
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++) printf("%d %d\n",p[i].first,p[i].second);
}
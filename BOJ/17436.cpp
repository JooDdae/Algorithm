#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[10],ans;
ll f(int cnt,int cur,ll g){
	if(cnt < 0) return m/g;
	if(cur == n) return 0;
	return f(cnt,cur+1,g) + f(cnt-1,cur+1,g*a[cur]);
}
int main(){
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) ans += f(i,0,1) * (i%2?-1:1);
    printf("%lld",ans);
}
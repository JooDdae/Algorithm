#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll tree[303030],mx[606060],mx2[606060];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&tree[i]);
    scanf("%d",&q);
	for(int i=n;i>=1;i--) mx[i] = tree[i]+max(mx[i*2],mx[i*2+1]), mx2[i] = max({mx2[i*2], mx2[i*2+1], tree[i]+mx[i*2]+mx[i*2+1]});;
	printf("%lld\n",mx2[1]);
	while(q--){
		int a,b; scanf("%d %d",&a,&b);
		tree[a] = b;
		while(a){
			mx[a] = tree[a] + max(mx[a*2], mx[a*2+1]);
			mx2[a] = max({mx2[a*2], mx2[a*2+1], tree[a]+mx[a*2]+mx[a*2+1]});
			a/=2;
		}
		printf("%lld\n",mx2[1]);
	}
}
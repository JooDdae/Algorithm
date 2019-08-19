#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[101010];
int n,q;
void up(int bit,int val){
	while(bit <= n){
		tree[bit] += val;
		bit += bit & -bit;
	}
}
ll f(int bit){
	ll re=0;
	while(bit){
		re += tree[bit];
		bit -= bit & -bit;
	}
	return re;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	up(i,a); up(i+1,-a);
    }
    scanf("%d",&q);
    while(q--){
    	int a,b,c,d; scanf("%d %d",&a,&b);
    	if(a == 2) printf("%lld\n",f(b));
    	else{
    		scanf("%d %d",&c,&d);
    		up(b,d); up(c+1,-d);
    	}
    }
}
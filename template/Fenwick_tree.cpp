// boj.kr/2042
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 1010101

int n,m,k;
ll tree[MAX_N];

void update(int bit, int val){
	while(bit <= n){
		tree[bit] += val;
		bit += bit & (-bit);
	}
}

ll find(int bit){
	ll re=0;
	while(bit){
		re += tree[bit];
		bit -= bit & (-bit);
	}
	return re;
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	update(i,a);
    }
    for(int i=1;i<=m+k;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	if(a == 1) update(b, c-find(b)+find(b-1));
    	else printf("%lld\n",find(c)-find(b-1));
    }
}
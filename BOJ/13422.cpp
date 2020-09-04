#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, k, a[100100];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		int cnt = 0, sum = 0;
		for(int i=1;i<m;i++) sum += a[i];
		if(n == m){
			printf("%d\n",sum+a[m] < k);
			continue;
		}
		for(int i=1;i<=n;i++){
			sum += a[(i+m-2)%n+1];
			if(sum < k) cnt++;
			sum -= a[i];
		}
		printf("%d\n",cnt);
	}
}
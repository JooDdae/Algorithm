#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int tmp = n;
		for(int i=2;i*i<=n;i++) if(n % i == 0){
			int c = 0;
			while(n % i == 0) c++, n/=i;
			printf("%d %d\n",i,c);
		}
		if(n > 1) printf("%d 1\n",n);
	}
}
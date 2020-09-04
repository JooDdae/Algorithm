#include<bits/stdc++.h>
using namespace std;
int a, b;
int main(){
	while(~scanf("%d %d",&a,&b)){
		int ans = 1, c = b;
		for(int i=2;i*i<=c;i++) if(b % i == 0){
			int c1 = 0, c2 = 0;
			while(b % i == 0) b /= i, c1++;
			for(int j=i;j<=a;j*=i) c2 += a / j;
			for(int j=1;j<=min(c1, c2);j++) ans *= i;
		}
		if(a >= b) ans *= b;
		printf("%d\n",ans);
	}
}
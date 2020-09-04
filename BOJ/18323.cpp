#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1010], chk[1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) chk[j] = 0;

		int fl = 0;
		for(int j=0,u=-i;j<n && !fl;j++){
			u = a[j] - u;
			if(u < 1 || n < u || chk[u]) fl = 1;
			else chk[u] = 1;
		}

		if(!fl){
			for(int j=0,u=-i;j<n;j++){
				u = a[j] - u;
				printf("%d ",u);
			}
			break;
		}
	}
}
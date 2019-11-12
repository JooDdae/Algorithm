#include<bits/stdc++.h>
using namespace std;
int n,mp[1030][1030];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&mp[i][j]);
	while(n > 1){
		for(int i=1;i<=n;i+=2){
			for(int j=1;j<=n;j+=2){
				int a = mp[i][j], b = mp[i][j+1];
				if(a < b) swap(a,b);
				if(b < mp[i+1][j]){
					b = mp[i+1][j];
					if(a < b) swap(a,b);
				}
				if(b < mp[i+1][j+1]){
					b = mp[i+1][j+1];
					if(a < b) swap(a,b);
				}

				mp[(i+1)/2][(j+1)/2] = b;
			}
		}
		n/=2;
	}
	printf("%d",mp[1][1]);
}
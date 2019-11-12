#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int j=i,k=0;
		while(j){
			k+=j%10;
			j/=10;
		}
		if(i%k == 0) cnt++;
	}
	printf("%d",cnt);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j){
			if(j%10 == 3 || j%10 == 6 || j%10 == 9) cnt++;
			j/=10;
		}
	}
	printf("%d",cnt);
}
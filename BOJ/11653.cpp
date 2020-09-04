#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d",&n);
	int tmp = n;
	for(int i=2;i*i<=tmp;i++){
		while(n % i == 0){
			printf("%d\n",i);
			n /= i;
		}
	}
	if(n > 1) printf("%d",n);
}
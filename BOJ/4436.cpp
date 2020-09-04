#include<bits/stdc++.h>
using namespace std;
int chk[10], cnt;
long long n;
void f(long long a){
	while(a){
		if(++chk[a%10] == 1) cnt++;
		a /= 10;
	}
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=100;i++){
			f(n * i);
			if(cnt == 10){
				printf("%d\n",i);
				break;
			}
		}
		cnt = 0;
		for(int i=0;i<10;i++) chk[i] = 0;
	}
}
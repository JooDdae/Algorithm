#include<bits/stdc++.h>
using namespace std;
int n, k, h, m, s, cnt;
int main(){
	scanf("%d %d",&n,&k);
	while(h <= n){
		if(h/10 == k || h%10 == k || m/10 == k || m%10 == k || s/10 == k || s%10 == k) cnt++;
		s++;
		if(s == 60) m++, s = 0;
		if(m == 60) h++, m = 0;
	}
	printf("%d",cnt);
}
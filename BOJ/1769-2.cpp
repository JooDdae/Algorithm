#include<bits/stdc++.h>
using namespace std;
int n,a,cnt,fl;
int f(int x){
	if(x < 10){
		fl = x%3;
		return 1;
	}
	int sum=0;
	while(x){
		sum += x%10;
		x/=10;
	}
	return f(sum)+1;
}
int main(){
    while(~scanf("%01d",&a)) n+=a,cnt++;
    if(cnt == 1) return !printf("0\n%s",n%3?"NO":"YES");
    printf("%d\n",f(n));
    printf("%s",fl?"NO":"YES");
}
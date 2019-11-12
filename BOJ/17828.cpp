#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	scanf("%d %d",&a,&b);
	if(a * 26 < b || a > b) return !printf("!");

	for(int i=1;i<=a;i++){
		if((a-i)*26+1 >= b) printf("A"),b--;
		else if((a-i+1)*26 == b) printf("Z"),b-=26;
		else printf("%c",'A'+b-(a-i)*26-1),b-=b-(a-i)*26;
	}
}
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		if(!a && !b && !c) break;
		c -= a;
		if(!c || c%b) puts("X");
		else printf("%d\n",c/b+1);
	}
}
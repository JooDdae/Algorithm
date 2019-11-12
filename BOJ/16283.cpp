#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d,fl,ans;
int main(){
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(int i=1;i<c;i++){
		if(i*a + (c-i)*b == d){
			if(fl) return !printf("-1");
			fl = 1;
			ans = i;
		}
	}
	if(fl) printf("%d %d",ans,c-ans);
	else printf("-1");
}
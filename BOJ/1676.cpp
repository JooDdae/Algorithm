#include<bits/stdc++.h>
using namespace std;
int n,ans;
int f(int a){
	if(a%5) return 0;
	return f(a/5)+1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) ans += f(i);
    printf("%d",ans);
}
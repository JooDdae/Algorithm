#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&m);
    	for(int i=1;i<=m;i++) scanf("%*d%*d");
    	printf("%d\n",n-1);
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> p[101010];
int f(int a,int b,int c){
	for(int i=1;i<=n;i++){
		if(p[i].second < a || b < p[i].second) continue;
		if(!(--c)) return p[i].first;
	}
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d",&p[i].first);
    	p[i].second=i;
    }
    sort(p+1,p+1+n);
    while(m--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	printf("%d\n",f(a,b,c));
    }
}
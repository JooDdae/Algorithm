#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[101],y[101],ans;
int f(int a,int b,int c,int d){
	if(a>n || c>n || b>m || d>m || (a+c>n && b+d>m)) return 0;
	return a*b+c*d;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++) ans=max({ans,f(x[i],y[i],x[j],y[j]),f(x[i],y[i],y[j],x[j]),f(y[i],x[i],x[j],y[j]),f(y[i],x[i],y[j],x[j])});
	printf("%d",ans);
}
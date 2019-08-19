#include<bits/stdc++.h>
using namespace std;
int t,s[101010],chk[1010101],n,a,b;
int main(){
    for(int i=2;i<=100000;i++){
    	if(s[i]) continue;
    	for(int j=i+i;j<=100000;j+=i) s[j]=1;
    }
	
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		queue<int> qx,qc;
		scanf("%d %d %d",&n,&a,&b);
		int fl=0;
		qx.push(n),qc.push(0);
		chk[n] = i;
		while(!qx.empty()){
			int x=qx.front(),c=qc.front();
			qx.pop(),qc.pop();
			if(a<=x && x<=b && !s[x]){
				printf("%d\n",c); fl=1;
				break;
			}
			if(x && chk[x/2]!=i) qx.push(x/2),qc.push(c+1),chk[x/2]=i;
			if(x && chk[x/3]!=i) qx.push(x/3),qc.push(c+1),chk[x/3]=i;
			if(x<=1000001 && chk[x+1]!=i) qx.push(x+1),qc.push(c+1),chk[x+1]=i;
			if(x && chk[x-1]!=i) qx.push(x-1),qc.push(c+1),chk[x-1]=i;
		}
		if(!fl) puts("-1");
	}
}
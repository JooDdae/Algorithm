#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,chk[101010];
queue<int> qx,qc;
void f(int a){
	if(0<=a && a<=100000 && !chk[a]) qx.push(a),qc.push(qc.front()+1),chk[a]=1;
}
int main(){
    scanf("%d %d %d %d",&a,&b,&n,&m);
    qx.push(n),qc.push(0);
    while(!qx.empty()){
    	int x=qx.front();
    	if(x==m) return !printf("%d",qc.front());
    	f(x-1),f(x+1),f(x-a),f(x-b),f(x+a),f(x+b),f(x*a),f(x*b);
    	qx.pop(),qc.pop();
    }
}
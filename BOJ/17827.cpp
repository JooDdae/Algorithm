#include<iostream>
using namespace std;
int n,m,e,a[200200],b;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>e;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(m--){
		cin>>b;
		if(++b > e) b = (b-e) % (n-e+1) + e;
		cout<<a[b]<<'\n';
	}
}
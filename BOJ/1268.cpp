#include<bits/stdc++.h>
using namespace std;
int n,arr[1010][10],ans[1010],mx,mxn;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&arr[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int fl=0;
			for(int k=1;k<=5;k++) if(arr[i][k] == arr[j][k]) fl=1;
			ans[i] += fl;
		}
	}
	for(int i=1;i<=n;i++) if(mx < ans[i]) mx = ans[i], mxn = i;
	printf("%d",mxn);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3],d,e,chk[505][505];
int main(){
	for(int i=0;i<3;i++) scanf("%d",&a[i]);
	while(~scanf("%d %d",&d,&e)){
		for(int i=0;i<=d;i++) for(int j=0;j<=e;j++) chk[i][j] = 1;

		for(int i=0;i<=d;i++){
			for(int j=0;j<=e;j++){
				for(int k=0;k<3;k++){
					if(a[k] <= i) chk[i][j] = min(chk[i][j], 1 - chk[i - a[k]][j]);
					if(a[k] <= j) chk[i][j] = min(chk[i][j], 1 - chk[i][j - a[k]]);
				}
			}
		}

		printf("%c\n",chk[d][e] ? 'B' : 'A');
	}
}
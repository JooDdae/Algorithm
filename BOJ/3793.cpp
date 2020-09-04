#include<bits/stdc++.h>
using namespace std;
char a[222],b[222];
int l[222][222];
int main(){
	while(~scanf(" %s %s",a+1,b+1)){
		for(int i=1;a[i];i++){
			for(int j=1;b[j];j++){
				l[i][j] = max(l[i-1][j], l[i][j-1]);
				if(a[i] == b[j]) l[i][j] = max(l[i][j], l[i-1][j-1] + 1);
			}
		}
		printf("%d\n",l[strlen(a+1)][strlen(b+1)]);
	}
}
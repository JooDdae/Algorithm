#include<bits/stdc++.h>
using namespace std;
string s[10];
int a[10],b[3],c[10],d[3],e[3],fl;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=0;i<6;i++) cin >> s[i];
	a[3]=1,a[4]=2,a[5]=3;
	do{
		int cnt = 0;
		for(int i=0;i<6;i++){
			if(a[i]) d[a[i]-1] = i;
			else e[cnt++] = i;
		}
		c[0]=0,c[1]=1,c[2]=2;
		do{
			if(s[e[c[0]]][0] == s[d[0]][0] && s[e[c[0]]][1] == s[d[1]][0] && s[e[c[0]]][2] == s[d[2]][0] &&
			   s[e[c[1]]][0] == s[d[0]][1] && s[e[c[1]]][1] == s[d[1]][1] && s[e[c[1]]][2] == s[d[2]][1] &&
			   s[e[c[2]]][0] == s[d[0]][2] && s[e[c[2]]][1] == s[d[1]][2] && s[e[c[2]]][2] == s[d[2]][2]){ 
				if(!fl || s[e[c[0]]]+s[e[c[1]]]+s[e[c[2]]] < s[d[0]]+s[d[1]]+s[d[2]]){
					b[0]=e[c[0]],b[1]=e[c[1]],b[2]=e[c[2]];
					fl = 1;
				}
			}
		}while(next_permutation(c, c+3));
	}while(next_permutation(a, a+6));
	if(!fl) cout << 0;
	else cout << s[b[0]] << '\n' << s[b[1]] << '\n' << s[b[2]];
}
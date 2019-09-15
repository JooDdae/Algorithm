#include<bits/stdc++.h>
using namespace std;
int n,chk[4][4];
bool f(int x,int y){
	if(chk[x][1] && chk[x][1] == chk[x][2] && chk[x][2] == chk[x][3]) return true;
	if(chk[1][y] && chk[1][y] == chk[2][y] && chk[2][y] == chk[3][y]) return true;
	if(chk[1][1] && chk[1][1] == chk[2][2] && chk[2][2] == chk[3][3]) return true;
	if(chk[3][1] && chk[3][1] == chk[2][2] && chk[2][2] == chk[1][3]) return true;
	return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=9;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	chk[a][b] = i%2+1;
    	if(f(a,b)) return !printf("%d",n);
    	n = n==2?1:2;
    }
    printf("0");
}
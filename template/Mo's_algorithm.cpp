// boj.kr/13547
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 101010
#define MAX_M 101010

struct node{
	int x,y,id;
	bool operator < (const node &a)const{
		if(x>>9 == a.x>>9) return y < a.y;
		return x>>9 < a.x>>9;
	}
}in[MAX_M];
int n,m,arr[MAX_N],out[MAX_M],chk[1010101];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	scanf("%d %d",&in[i].x,&in[i].y);
    	in[i].id = i;
    }
    sort(in+1, in+1+m);
    int l=1,r=0,ans=0;
    for(int i=1;i<=m;i++){
    	while(l<in[i].x) if(--chk[arr[l++]] == 0) ans--;
    	while(r<in[i].y) if(chk[arr[++r]]++ == 0) ans++;
    	while(l>in[i].x) if(chk[arr[--l]]++ == 0) ans++;
    	while(r>in[i].y) if(--chk[arr[r--]] == 0) ans--;
    	out[in[i].id] = ans;
    }
    for(int i=1;i<=m;i++) printf("%d\n",out[i]);
}
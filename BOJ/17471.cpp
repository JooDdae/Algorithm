#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[11],t[11],chk[11],C[3];
vector<int> v[11];
void dfs(int a){
	chk[a] = 1;
	for(int nxt : v[a]) if(!chk[nxt] && t[a]==t[nxt]) dfs(nxt);
}
int f(int a,int b,int c){
	if(a == n){
		for(int i=1;i<=n;i++) chk[i]=0;
		C[1]=C[2]=0;
		for(int i=1;i<=n;i++) if(!C[t[i]]){
			dfs(i);
			C[t[i]]=1;
		}
		for(int i=1;i<=n;i++) if(!chk[i]) return 1e9;
		return abs(b-c);
	}
	int re=1e9;
	t[a+1] = 1;
	re=min(re,f(a+1,b+arr[a+1],c));
	t[a+1] = 2;
	re=min(re,f(a+1,b,c+arr[a+1]));
	return re;
}
int f2(int a){
	return a>10000000?-1:a;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	while(a--){
    		int b; scanf("%d",&b);
    		v[i].push_back(b);
    	}
    }

    printf("%d",f2(f(0,0,0)));
}
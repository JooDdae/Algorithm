#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,cnt,n,fl;
ll p[202020],sum[2];
map<string,int> mp;
char s[30];
int main(){
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=a+b+c;i++){
		scanf(" %s",s);
		if(i<=a+b) scanf("%lld",&p[i]);
		mp[s] = ++cnt;
	}
	scanf("%d",&n);
	while(n--){
		scanf(" %s",s);
		if(mp[s] > a+b){
			if(fl) return !printf("No");
			fl=1;
		}else sum[mp[s]>a] += p[mp[s]];
	}
	if(sum[0] < 20000 && (sum[1] || fl)) return !printf("No");
	if(sum[0]+sum[1] < 50000 && fl) return !printf("No");

	printf("Okay");
}
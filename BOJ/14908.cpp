#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int t, s, id;
	bool operator < (const node &a) const{
		return make_pair(t*a.s, id) < make_pair(a.t*s, a.id);
	}
}p[1010];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&p[i].t,&p[i].s);
	for(int i=1;i<=n;i++) p[i].id = i;
	sort(p+1, p+1+n);
	for(int i=1;i<=n;i++) printf("%d ",p[i].id);
}
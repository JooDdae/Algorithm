#include<bits/stdc++.h>
using namespace std;
int n,m,ans[10101];
queue<int> chk[2][10101];
pair<int,int> p[10101];
int main(){
	scanf("%d %d",&m,&n);
	if(m < n) return !printf("impossible");
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		if(a > b) swap(a,b);
		chk[a==b][a].push(i);
	}
	for(int i=1;i<=n;i++) scanf("%d",&p[i].first);
	for(int i=1;i<=n;i++) p[i].second = i;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++){
		if(chk[1][p[i].first].size()){
			ans[p[i].second] = chk[1][p[i].first].front();
			chk[1][p[i].first].pop();
		}else{
			if(chk[0][p[i].first-1].size()){
				ans[p[i].second] = chk[0][p[i].first-1].front();
				chk[0][p[i].first-1].pop();
			}else if(chk[0][p[i].first].size()){
				ans[p[i].second] = chk[0][p[i].first].front();
				chk[0][p[i].first].pop();
			}else return !printf("impossible");
		}
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
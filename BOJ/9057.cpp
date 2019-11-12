#include<bits/stdc++.h>
using namespace std;
struct node{
	string team;
	int school,solved,penalty,flag;
	bool operator < (const node &a)const{
		return tie(a.solved, penalty) < tie(solved, a.penalty);
	}
}arr[1010];
int t,n,chk[1010],c[1010];
char s1[30],s2[30];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		unordered_map<string,int> mp;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int a,b; scanf("%s %s %d %d",s1,s2,&a,&b);
			if(!mp[s2]) mp[s2] = ++cnt, c[cnt] = 0;
			c[mp[s2]]++;
			arr[i] = {s1, mp[s2], a, b, 0};
		}
		sort(arr+1, arr+1+n);
		for(int i=1;i<=cnt;i++) chk[i] = 0;
		node mn = arr[1];
		cnt = 0;
		for(int i=1;i<=n && cnt<60;i++){
			int cur =  arr[i].school;
			if(c[cur]/2 + c[cur]%2 <= chk[cur]) continue;
			if(i <= 10){
				if(chk[cur] <= 3) cnt++, chk[cur]++, arr[i].flag=1, mn=max(mn, arr[i]);
			}
			else if(i <= 20){
				if(chk[cur] <= 2) cnt++, chk[cur]++, arr[i].flag=1, mn=max(mn, arr[i]);
			}
			else if(i <= 30){
				if(chk[cur] <= 1) cnt++, chk[cur]++, arr[i].flag=1, mn=max(mn, arr[i]);
			}
			else{
				if(chk[cur] <= 0) cnt++, chk[cur]++, arr[i].flag=1, mn=max(mn, arr[i]);
			}
		}
		for(int i=1;i<=n && cnt<60;i++) if(!arr[i].flag) mn = max(mn, arr[i]), ++cnt;
		printf("%s\n",mn.team.data());
	}
}
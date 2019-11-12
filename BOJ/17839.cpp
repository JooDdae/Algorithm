#include<bits/stdc++.h>
using namespace std;
int n,cnt,chk[202020];
char s1[20],s2[20];
vector<int> v[202020];
map<string, int> mp;
string re[202020];
priority_queue<string,vector<string>,greater<string>> pq;
void f(int a){
    if(chk[a]) return;
    chk[a] = 1;
	if(a != mp["Baba"]) pq.push(re[a]);
	for(int nxt : v[a]) f(nxt);
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s is %s",s1,s2);
		if(!mp[s1]) mp[s1] = ++cnt,re[cnt] = s1;
		if(!mp[s2]) mp[s2] = ++cnt,re[cnt] = s2;
		v[mp[s1]].push_back(mp[s2]);
	}
	f(mp["Baba"]);
	while(!pq.empty()){
		printf("%s\n",pq.top().data());
		pq.pop();
	}
}
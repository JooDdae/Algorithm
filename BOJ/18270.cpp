#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> mp;
int n;
char a[20], b[20], s[8][20] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<int> v[8];
vector<vector<string>> vv;
int main(){
	for(int i=0;i<8;i++) mp[s[i]] = i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %s must be milked beside %s",a,b);
		v[mp[a]].push_back(mp[b]);
		v[mp[b]].push_back(mp[a]);
	}
	for(int i=0;i<8;i++){
		if(v[i].size() == 0) vv.push_back(vector<string>(1, s[i]));
		else if(v[i].size() == 1){
			vector<string> V(1, s[i]);
			int cur = v[i][0], p = i;
			V.push_back(s[cur]);
			while(v[cur].size() != 1){
				if(v[cur][0] == p) swap(v[cur][0], v[cur][1]);
				p = cur;
				cur = v[cur][0];
				V.push_back(s[cur]);
			}
			v[cur].push_back(1);
			if(V.front() > V.back()) reverse(V.begin(), V.end());
			vv.push_back(V);
		}
	}
	sort(vv.begin(), vv.end());
	for(auto x : vv) for(auto y : x) printf("%s\n",y.data());
}
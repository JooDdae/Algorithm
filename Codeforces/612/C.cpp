#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, arr[111], chk[111], cnt[2], ans;
vector<int> v[2],sp[2];
int main(){
	scanf("%d",&n);
	if(n == 1) return !printf("0");
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		chk[arr[i]] = 1;
	}
	for(int i=1;i<=n;i++) if(arr[i] && arr[i+1] && arr[i]%2 != arr[i+1]%2) ans++;
	for(int i=1;i<=n;i++) if(!chk[i]) cnt[i%2]++;

	if(cnt[0] + cnt[1] == n) return !printf("1");
	
	int l = 0, fl = 0, fl2 = 0;
	for(int i=1;i<=n;i++){
		if(arr[i] == 0) fl = 1;
		else{
			if(fl && (arr[1] != 0 || fl2)){
				if(arr[l]%2 == arr[i]%2) v[arr[i]%2].push_back(i-l-1);
				else ans++;
			}
			fl = 0;
			fl2 = 1;
			l = i;
		}
	}

	if(arr[1] == 0){
		int cur = 1;
		while(arr[cur] == 0) cur++;
		sp[arr[cur]%2].push_back(cur-1);
	}
	if(arr[n] == 0){
		int cur = n;
		while(arr[cur] == 0) cur--;
		sp[arr[cur]%2].push_back(n-cur);
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(sp[0].begin(), sp[0].end());
	sort(sp[1].begin(), sp[1].end());

	int cur = 0;
	while(cur < v[0].size() && ((sp[0].size() == 2 && sp[0][0] + sp[0][1] <= cnt[0]) || cnt[0] >= v[0][cur])){
		if(sp[0].size() == 2 && sp[0][0] + sp[0][1] <= v[0][cur]){
			cnt[0] -= sp[0][0] + sp[0][1];
			sp[0].clear();
			continue;
		}
		cnt[0] -= v[0][cur];
		cur++;
	}
	while(cur < v[0].size()){
		ans += 2;
		cur++;
	}
	cur = 0;
	while(cur < sp[0].size() && sp[0][cur] <= cnt[0]){
		ans--;
		cnt[0]-=sp[0][cur];
		cur++;
	}

	cur = 0;
	while(cur < v[1].size() && ((sp[1].size() == 2 && sp[1][0] + sp[1][1] <= cnt[1]) || cnt[1] >= v[1][cur])){
		if(sp[1].size() == 2 && sp[1][0] + sp[1][1] <= v[1][cur]){
			cnt[1] -= sp[1][0] + sp[1][1];
			sp[1].clear();
			continue;
		}
		cnt[1] -= v[1][cur];
		cur++;
	}
	while(cur < v[1].size()){
		ans += 2;
		cur++;
	}
	cur = 0;
	while(cur < sp[1].size() && sp[1][cur] <= cnt[1]){
		ans--;
		cnt[1]-=sp[1][cur];
		cur++;
	}

	printf("%d",ans+sp[0].size()+sp[1].size());
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[200200];
vector<int> v[200200];

pair<int, int> f(int u){
	int sum = 0, mx = 0;
	for(int x : v[u]){
		pair<int, int> g = f(x);
		sum += max(g.first, g.second);
		mx = max(mx, g.second + a[x] * a[u] - max(g.first, g.second));
	}

	return {sum + mx, sum};
}

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int b; scanf("%d",&b);
		v[b].push_back(i);
	}
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	pair<int, int> p = f(1);
	printf("%d",max(p.first, p.second));
}
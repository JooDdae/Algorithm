#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v, ans;
set<vector<int>> s;
queue<vector<int>> q;
queue<int> qc;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	for(int i=1;i<=n;i++) ans.push_back(i);
	q.push(v), qc.push(0);
	while(!q.empty()){
		vector<int> u = q.front(); q.pop();
		int c = qc.front(); qc.pop();

		if(u == ans) return !printf("%d",c);

		for(int i=0;i<=n-k;i++){
			for(int j=0;j<k/2;j++) swap(u[i+j], u[i+k-j-1]);
			if(!s.count(u)){
				s.insert(u);
				q.push(u), qc.push(c+1);
			}
			for(int j=0;j<k/2;j++) swap(u[i+j], u[i+k-j-1]);
		}
	}
	printf("-1");
}
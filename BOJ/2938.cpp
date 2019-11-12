#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
queue<int> q[3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		q[a%3].push(a);
	}

	if(q[0].size() > q[1].size()+q[2].size()+1 || (q[1].size() && q[2].size() && q[0].size() == 0)) return !printf("-1");
	
	while(!q[1].empty()){
		if(q[0].size() > 1){
			printf("%d ",q[0].front());
			q[0].pop();
		}
		printf("%d ",q[1].front());
		q[1].pop();
	}
	while(!q[2].empty()){
		if(!q[0].empty()){
			printf("%d ",q[0].front());
			q[0].pop();
		}
		printf("%d ",q[2].front());
		q[2].pop();
	}
	if(!q[0].empty()){
		printf("%d ",q[0].front());
		q[0].pop();
	}
}
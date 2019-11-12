#include<bits/stdc++.h>
using namespace std;

#define MAX_N 2020

struct node{
	int to, cap, flow, rev;
};
int t, n, m, source, sink, lev[MAX_N], used[MAX_N], INF=1e9;
vector<node> v[MAX_N];

void addEdge(int l,int r,int cap){
	v[l].push_back({r, cap, 0, v[r].size()});
	v[r].push_back({l, 0, 0, v[l].size()-1});
}

bool bfs(){
	for(int i=2;i<=n;i++) lev[i] = -1;

	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto nxt : v[cur]){
			if(lev[nxt.to] == -1 && nxt.cap != nxt.flow){
				lev[nxt.to] = lev[cur] + 1;
				q.push(nxt.to);
			}
		}
	}

	return lev[sink] != -1;
}

int dfs(int cur, int flow){
	if(cur == sink) return flow;

	for(int &i = used[cur]; i<v[cur].size(); i++){
		node &nxt = v[cur][i];
		if(lev[cur] + 1 == lev[nxt.to] && nxt.cap != nxt.flow){
			int f = dfs(nxt.to, min(flow, nxt.cap - nxt.flow));
			if(f){
				nxt.flow += f;
				v[nxt.to][nxt.rev].flow -= f;
				return f;
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		source = 1, sink = n;
		for(int i=1;i<=m;i++){
            int a,b,c; scanf("%d %d %d",&a,&b,&c);
            addEdge(a, b, c);
        }

        int ans = 0, cnt = 0;
		while(bfs()){
			for(int i=1;i<=n;i++) used[i] = 0;
			while(1){
				int flow = dfs(source, INF);
				if(!flow) break;
				ans += flow;
			}
		}

		for(int i=1;i<=n;i++) for(auto &x : v[i]){
            if(x.cap && x.flow){
                for(int j=1;j<=n;j++) for(auto &u : v[j]) u.flow = 0;
                x.cap--;
                int f = 0;

                while(bfs()){
                    for(int i=1;i<=n;i++) used[i] = 0;
                    while(1){
                        int flow = dfs(source, INF);
                        if(!flow) break;
                        f += flow;
                    }
                }

                if(f != ans) cnt++;
                x.cap++;
            }
        }

		printf("%d\n",cnt);
		for(int i=1;i<=n;i++) v[i].clear();
	}
}
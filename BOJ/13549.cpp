#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,e,chk[101010];
deque<int> q,qc;
int main(){
    scanf("%d %d",&s,&e);
   	q.push_back(s),qc.push_back(0);
   	while(!q.empty()){
   		int x=q.front(),c=qc.front();
   		q.pop_front(),qc.pop_front();
   		if(chk[x]) continue;
   		chk[x] = 1;
   		if(x == e) return !printf("%d",c);
   		if(x*2<=100000 && !chk[x*2]) q.push_front(x*2),qc.push_front(c);
   		if(x+1<=100000 && !chk[x+1]) q.push_back(x+1),qc.push_back(c+1);
   		if(x-1>=0 && !chk[x-1]) q.push_back(x-1),qc.push_back(c+1);
   	}
}
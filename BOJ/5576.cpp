#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;i<=2;i++){
    	priority_queue<int> pq;
    	int ans=0;
    	for(int j=1;j<=10;j++){
    		int a; scanf("%d",&a);
    		pq.push(a);
    	}
    	for(int j=1;j<=3;j++){
    		ans += pq.top();
    		pq.pop();
    	}
    	printf("%d ",ans);
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,i,cur,bit;
int main(){
    scanf("%d %d",&n,&k);
    if(--k == cur) printf("%d ",cnt++);
    while(++i){
    	if(i >= (1<<bit)) bit++;
    	for(int j=bit-1;j>=0;j--){
    		cur=(cur+1)%n;
    		if(cur == k){
    			printf("%d ",(1<<j)&i?1:0);
    			if(++cnt == 5) return 0;
    		}
    	}
    }
}
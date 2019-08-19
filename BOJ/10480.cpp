#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
    	int a; scanf("%d",&a);
    	printf("%d is %s\n",a,a%2?"odd":"even");
    }
}
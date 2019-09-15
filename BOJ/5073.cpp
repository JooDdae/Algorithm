#include<bits/stdc++.h>
using namespace std;
int a[3];
int main(){
    while(1){
    	for(int i=0;i<3;i++) scanf("%d",&a[i]);
    	if(!a[0]) break;
    	sort(a,a+3);
    	if(a[0]+a[1] <= a[2]){
    		puts("Invalid");
    		continue;
    	}
    	if(a[0] == a[1] && a[1] == a[2]) puts("Equilateral");
    	else if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) puts("Isosceles");
    	else puts("Scalene");
    }
}
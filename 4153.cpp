#include <bits/stdc++.h>
using namespace std;
int a[3];
int main(){
    while(1){
        for(int i=0;i<3;i++) scanf("%d",&a[i]);
        if(!a[0]) break;
        sort(a,a+3);
        printf("%s\n",(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]?"right":"wrong"));
    }
}

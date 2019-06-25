#include<bits/stdc++.h>
using namespace std;
double a[5]={350.34,230.90,190.55,125.30,180.90};
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        double ans=0;
        for(int i=0;i<5;i++){
            int b; scanf("%d",&b);
            ans += a[i]*b;
        }
        printf("$%.2f\n",ans);
    }
}

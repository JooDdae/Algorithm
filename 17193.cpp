#include<bits/stdc++.h>
using namespace std;
long long a=2019201913,b=2019201949,c=2019201997;
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    printf("%lld",(a*(m-1)+b*n)%c);
}

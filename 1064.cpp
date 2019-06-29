#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d,e,f;
double len(int a,int b,int c,int d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    if(a*d+c*f+e*b-b*c-d*e-f*a == 0) return !printf("-1");
    double mn = min({len(a,b,c,d)+len(c,d,e,f),len(a,b,e,f)+len(e,f,c,d),len(a,b,c,d)+len(a,b,e,f)}),mx = max({len(a,b,c,d)+len(c,d,e,f),len(a,b,e,f)+len(e,f,c,d),len(a,b,c,d)+len(a,b,e,f)});
    printf("%.12f",mx*2-mn*2);
}

#include<bits/stdc++.h>
using namespace std;
int n,arr[10101];
vector<int> x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    for(int i=1;i<=n;i++){
        if(arr[i] != i){
            for(int j=i+1;j<=n;j++){
                if(arr[j] == i){
                    x.push_back(i),y.push_back(j);
                    reverse(arr+i,arr+j+1);
                }
            }
        }
    }
    int fl = 0;
    for(int i=1;i<=n;i++) if(arr[i] != i) fl = 1;

    if(!fl && x.size()<=2){
        for(int i=0;i<x.size();i++) printf("%d %d\n",x[i],y[i]);
        for(int i=1;i<=2-x.size();i++) printf("1 1\n");
        return 0;
    }

    if(!x.empty()) for(int i=x.size()-1;i>=0;i--) reverse(arr+x[i],arr+y[i]+1);
    x.clear(),y.clear();

    for(int i=n;i>=1;i--){
        if(arr[i] != i){
            for(int j=i-1;j>=1;j--){
                if(arr[j] == i){
                    x.push_back(j),y.push_back(i);
                    reverse(arr+j,arr+i+1);
                }
            }
        }
    }

    for(int i=0;i<x.size();i++) printf("%d %d\n",x[i],y[i]);
    for(int i=1;i<=2-x.size();i++) printf("1 1\n");
}

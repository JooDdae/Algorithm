#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);cin.tie(nullptr);
   int H, W, N, m=0;
   cin>>H>>W>>N;
   vector<pair<int, int>> A(N);
   rep(i, 0, N) {
      auto&[a,b]=A[i];
      cin>>a>>b;
      if(a<b) swap(a, b);
      rep(j, 0, i) {
         auto[c,d]=A[j];
         if(a+d<=W && b<=H && c<=H
         || a+d<=H && b<=W && c<=W
         || b+d<=W && a<=H && c<=H
         || b+d<=H && a<=W && c<=W)
            m=max(m, a*b+c*d);
      }
   }
   cout<<m;
}
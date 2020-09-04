#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1);
typedef complex<double> base;
 
void fft(vector <base> &a, bool invert)
{
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = pi*2/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const vector<ll> &a,const vector<ll> &b,vector<ll> &res)
{
    vector <base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n = 1;
    while (n < max(a.size(),b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = round(fa[i].real());
}

int n,m,l,ans;
ll k;
int main(){
    scanf("%d %d %d %lld",&m,&l,&n,&k);
    vector<ll> A(n*m), B(n*l), C;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%lld",&A[i+j*n]);
    for(int i=0;i<n;i++) for(int j=0;j<l;j++) scanf("%lld",&B[i+j*n]);
    reverse(B.begin(), B.end());

    multiply(A, B, C);

    for(int i=l*n-1;i<m*n;i+=n) if(C[i] > k) ans++;
    printf("%d",ans);
}

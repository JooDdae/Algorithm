//boj.kr/15576

#include<bits/stdc++.h>
using namespace std;
 
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
 
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n = 1;
    while (n < max(a.size(),b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(round(fa[i].real()));
}

char a[303030], b[303030];
int main(){
    scanf("%s %s",a,b);
    int al = strlen(a), bl = strlen(b);
    vector<int> A(al,0), B(bl,0), C;
    for(int i=0;a[i];i++) A[al-i-1] = a[i]-'0';
    for(int i=0;b[i];i++) B[bl-i-1] = b[i]-'0';
    multiply(A, B, C);
    for(int i=0;i<al+bl;i++) C[i+1] += C[i]/10, C[i] %= 10;

    int fl = 0;
    for(int i=al+bl;i>=0;i--) if(fl || C[i]) fl=1, printf("%d",C[i]);
    if(!fl) printf("0");
}

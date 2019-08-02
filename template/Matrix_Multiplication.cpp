// boj.kr/2740
#include<bits/stdc++.h>
using namespace std;

struct matrix{
	vector<vector<int>> mt;
	matrix operator * (const matrix &a) const{
		matrix m;
		m.mt.resize(mt.size(),vector<int>(a.mt[0].size()));
		for(int i=0;i<mt.size();i++){
			for(int j=0;j<a.mt[0].size();j++){
				for(int k=0;k<mt[0].size();k++){
					m.mt[i][j] += mt[i][k] * a.mt[k][j];
				}
			}
		}
		return m;
	}
}a,b;
int n,m,k;

int main(){
    scanf("%d %d",&n,&m);
    a.mt.resize(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a.mt[i][j]);
    scanf("%*d %d",&k);
    b.mt.resize(m, vector<int>(k));
    for(int i=0;i<m;i++) for(int j=0;j<k;j++) scanf("%d",&b.mt[i][j]);

    matrix c = a*b;
	for(vector<int> v : c.mt){
		for(int x : v) printf("%d ",x);
		puts("");
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
void put(string s){
	for(int i=1;i<=n-a;i++) for(int j=1;j<=4;j++) printf("_");
	printf("%s\n",s.data());
}
void f(){
	put("\"재귀함수가 뭔가요?\"");
	if(a == 0){
		put("\"재귀함수는 자기 자신을 호출하는 함수라네\"");
	}else{
		put("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
		put("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
		put("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
	}
	a--;
	if(a>=0) f();
	a++;
	put("라고 답변하였지.");
}
int main(){
	scanf("%d",&n);
	a=n;
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	f();
}

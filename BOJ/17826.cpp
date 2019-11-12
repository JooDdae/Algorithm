#include<bits/stdc++.h>
int a[50],b;
int main(){
	for(int i=0;i<50;i++) scanf("%d",a+i);
	scanf("%d",&b);
	std::sort(a,a+50,std::greater<int>());
	for(int i=0;i<50;i++) if(a[i] == b) return !printf("%s",i<5?"A+":i<15?"A0":i<30?"B+":i<35?"B0":i<45?"C+":i<48?"C0":"F");
}
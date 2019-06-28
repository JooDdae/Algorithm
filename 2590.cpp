#include<bits/stdc++.h>
using namespace std;
int arr[10],cnt,cnt1,cnt2;
int main(){
    for(int i=1;i<=6;i++) scanf("%d",&arr[i]);
    cnt = arr[6] + arr[5] + arr[4] + arr[3]/4;

    cnt1 += 11 * arr[5];
    cnt2 += 5 * arr[4];

    if(arr[3]%4 == 3) cnt2+=1,cnt1+=5,cnt+=1;
    else if(arr[3]%4 == 2) cnt2+=3,cnt1+=6,cnt+=1;
    else if(arr[3]%4 == 1) cnt2+=5,cnt1+=7,cnt+=1;

    if(cnt2 >= arr[2]){
        cnt2 -= arr[2];
        cnt1 += cnt2*4;
    }else{
        arr[2] -= cnt2;
        cnt += (arr[2]-1)/9+1;
        if(arr[2]%9) cnt1 += (9-arr[2]%9)*4;
    }

    arr[1] -= cnt1;
    if(arr[1] > 0) cnt += (arr[1]-1) / 36 + 1;

    printf("%d",cnt);
}

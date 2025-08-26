#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i*(n-i+1)*arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    cout<<solve(arr,n)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int dif[n+1]={0};
    int q;
    cin>>q;
    while(q--){
        int l,r,v;
        cin>>l>>r>>v;
        dif[l]+=v;
        dif[r+1]-=v;
    }
    for(int i=1;i<n;i++)dif[i]+=dif[i-1];
    for(int i=0;i<n;i++)arr[i]+=dif[i];
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

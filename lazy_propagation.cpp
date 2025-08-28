#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mx=100001;
struct Node{
    ll sum=0,prop=0;
} tree[mx*4];
int arr[mx];
void build(int node,int st,int end){
    if(st==end){
        tree[node].sum=arr[st];
        tree[node].prop=0;
        return;
    }
    int m=st+(end-st)/2;
    build(node*2,st,m);
    build(node*2+1,m+1,end);
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void update(int node,int st,int end,int l,int r,int val){
    if(r<st||l>end)return;
    if(l<=st&&end<=r){
        tree[node].sum+=(end-st+1)*val;
        tree[node].prop+=val;
        return;
    }
    int m=st+(end-st)/2;
    update(2*node,st,m,l,r,val);
    update(2*node+1,m+1,end,l,r,val);
    tree[node].sum=tree[l].sum+tree[r].sum;
}
ll query(int node,int st,int end,int l,int r,ll carry=0){
    if(r<st||end>l)return 0;
    if(l<=st&&end<=r){
        return tree[node].sum+carry*(end-st+1);
    }
    int m=st+(end-st)/2;
    ll q1=query(node*2,st,m,l,r,carry+tree[node].prop);
    ll q2=query(node*2+1,m+1,end,l,r,carry+tree[node].prop);
    return q1+q2;
}
int main(){
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(q--){
        int type,l,r,val;
        cin>>type;
        if(type==1){//type=1 , update the value
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else{//print the value
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
            cout.flush();
        }

    }
    return 0;
}

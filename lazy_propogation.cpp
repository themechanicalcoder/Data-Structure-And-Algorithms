#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int t[4*MAXN],lazy[4*MAXN]={0};
int a[]={-1,2,3,-9,4,8,3,5,-6,14,16,17,-12,23};
    //    0 1 2  3 4 5 6 7  8  9 10 11  12 13
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return ;}
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=t[2*v]+t[2*v+1];
}



void shift(int node,int start,int end,int val){
    t[node]+=(end-start+1)*val;
    if(start !=end){
        lazy[node*2]+=val;
        lazy[node*2+1]+=val;
    }
}
void increase(int node,int start ,int end,int l,int r,int val){
    if(lazy[node]!=0){
        shift(node,start,end,lazy[node]);
        lazy[node]=0;
    }
    if(start>end || start >r || end<l)
        return ;
    if(start >=l && end<=r){
       shift(node,start,end,val);
       return;
    }
    int mid=(start+end)/2;
    increase(node*2,start,mid,l,r,val);
    increase(node*2+1,mid+1,end,l,r,val);
    t[node]=t[node*2]+t[2*node+1];
}
int query(int node,int start,int end,int l,int r){
    if(start>end || start >r || end<l)
        return 0;
    if(lazy[node]!=0){
        shift(node,start,end,lazy[node]);
        lazy[node]=0;
    }
    if(start>=l && end<=r)
        return t[node];
    int mid=(start+end)/2;
    return query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r);
}


int main(){
int n=sizeof(a)/sizeof(a[0]);
build(1,0,n-1);
increase(1,0,n-1,1,5,3);
increase(1,0,n-1,5,7,-1);
cout<<query(1,0,n-1,2,6);
return 0;
}

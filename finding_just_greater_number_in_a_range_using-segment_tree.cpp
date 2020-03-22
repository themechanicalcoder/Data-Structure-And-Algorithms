#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
int a[]={1,-1,2,5,3,7,-5,7,9,10};
vector<int>t[4*MAXN];
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]={a[tl]};
        return ;}
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    merge(t[2*v].begin(),t[2*v].end(),t[2*v+1].begin(),t[2*v+1].end(),back_inserter(t[v]));
}
int query(int v,int tl,int tr,int l,int r,int x){
    if(l>r)
        return INT_MAX;
    if(l==tl && r==tr){
        auto it=lower_bound(t[v].begin(),t[v].end(),x);
        if(it!=t[v].end())
            return *it;
        return INT_MAX;}
    int tm=(tl+tr)/2;
    return min(
    query(v*2,tl,tm,l,min(tm,r),x),
    query(v*2+1,tm+1,tr,max(l,tm+1),r,x));


}



int main(){
int n=sizeof(a)/sizeof(a[0]);
build(1,0,n-1);
cout<<query(1,0,n-1,1,9,8);
return 0;
}

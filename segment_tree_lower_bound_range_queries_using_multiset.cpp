#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
int a[]={1,2,6,29,33,22,11,44,1,10,8,8,11,22,7,34};
multiset<int>t[4*MAXN];
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v].insert(a[tl]);
        return;}
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    merge(t[2*v].begin(),t[2*v].end(),t[2*v+1].begin(),t[2*v+1].end(),inserter(t[v],t[v].begin()));
}
int query(int v,int tl,int tr,int l,int r,int x){
    if(l>r)
        return INT_MAX;
    if(tl==l && tr==r){
        auto it= t[v].lower_bound(x);
        if(it!=t[v].end())
            return *it;
        return INT_MAX;}
    int tm=(tl+tr)/2;
    return min(
    query(2*v,tl,tm,l,min(tm,r),x),
    query(2*v+1,tm+1,tr,max(l,tm+1),r,x));

}
void update(int v,int tl,int tr,int pos,int new_value){

        t[v].erase(t[v].find(a[pos]));
        t[v].insert(new_value);
    if(tl!=tr){
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_value);
        else
            update(2*v+1,tm+1,tr,pos,new_value);
    }
    else
        a[pos]=new_value;


}





int main(){
int n=sizeof(a)/sizeof(a[0]);
//cout<<a[4]<<"\n";
//cout<<n<<"\n";
build(1,0,n-1);
cout<<query(1,0,n-1,0,6,25)<<"\n";
update(1,0,n-1,3,-1);
cout<<query(1,0,n-1,0,6,25)<<"\n";
//cout<<a[4];
return 0;
}

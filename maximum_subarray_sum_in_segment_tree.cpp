#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000

struct data{
int sum,pref,suff,ans;
};
//       0 1  2 3 4  5  6  7  8  9  10 11  12 13
int a[]={1,3,-4,5,2,-3,24,-43,67,10,45,20,-34,29};
data t[4*MAXN];

data combine(data l,data r){
    data res;
    res.sum=l.sum+ r.sum;
    res.pref=max(l.pref,l.sum+r.pref);
    res.suff=max(r.suff,r.sum+l.suff);
    res.ans=max(max(l.ans,r.ans),l.suff+r.pref);
    return res;
}
data make_data(int val){
    data res;
    res.sum=val;
    res.pref=res.suff=res.ans=max(0,val);
    return res;
}

void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=make_data(a[tl]);
        return ;}
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=combine(t[2*v],t[2*v+1]);
}
data  query(int v,int tl,int tr,int l,int r){
    if(tl==l && tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    if(r<=tm)
        return query(v*2,tl,tm,l,r);
    if(l>tm)
        return query(2*v+1,tm+1,tr,l,r);
    return combine(
                   query(v*2,tl,tm,l,tm),
                   query(v*2+1,tm+1,tr,tm+1,r)
    );
}

void update(int v,int tl,int tr,int pos,int new_value){
    if(tl==tr){
        t[v]=make_data(new_value);
        return ;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(2*v,tl,tm,pos,new_value);
    else
        update(2*v+1,tm+1,tr,pos,new_value);
    t[v]=combine(t[2*v],t[2*v+1]);
}



int main(){
int n=sizeof(a)/sizeof(a[0]);

build(1,0,n-1);
cout<<query(1,0,n-1,3,8).ans<<"\n";
update(1,0,n-1,8,-1);
cout<<query(1,0,n-1,3,8).ans;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000

int gcd(int a,int b){
    if(a==0){return b;}

    return gcd(b%a,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int a[]={5,7,5,2,10,12,11,17,14,2,44};
int t[4*MAXN];

void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return ;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=lcm(t[2*v],t[2*v+1]);
}
int get_lcm(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 1;
    if(tl==l && tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    int left_lcm=get_lcm(2*v,tl,tm,l,min(tm,r));
    int right_lcm=get_lcm(2*v+1,tm+1,tr,max(tm+1,l),r);
    return lcm(left_lcm,right_lcm);
}



void update(int v,int tl,int tr,int pos ,int new_value){
    if(tl==tr){
        t[v]=new_value;
        return ;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(2*v,tl,tm,pos,new_value);
    else
        update(2*v+1,tm+1,tr,pos,new_value);
    t[v]=lcm(t[2*v],t[2*v+1]);

}


int main(){
build(1,0,10);
cout<<get_lcm(1,0,10,2,5)<<"\n";
update(1,0,10,3,79);
cout<<get_lcm(1,0,10,2,5);
return 0;
}

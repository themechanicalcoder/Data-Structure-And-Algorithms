#include<bits/stdc++.h>
using namespace std;
int n=9;
int a[]={1,2,3,4,5,6,7,8,9};
int t[4*9];


void build(int a[],int t[],int v,int tl ,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return ;
        }
    int mid=(tl+tr)/2;
    build(a,t,2*v,tl,mid);
    build(a,t,2*v+1,mid+1,tr);
    t[v]=t[2*v]+t[2*v+1];
}
int sum(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(l==tl && r== tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);

}
void update(int v,int tl ,int tr,int pos,int new_val){
    if(tl==tr){
        t[v]=new_val;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(v*2,tl,tm,pos,new_val);
    else
        update(2*v+1,tm+1,tr,pos,new_val);

    t[v]=t[v*2]+t[v*2+1];


}




int main(){


build(a,t,1,0,n-1);
for(int i=1;i<=2*n;i++){
    cout<<t[i]<<"\n";
}
cout<<"the sum is \n"<<sum(1,0,n-1,0,6)<<"\n";
update(1,0,n-1,2,-1);
cout<<"after update the sum is \n"<<sum(1,0,n-1,0,6)<<"\n";
return 0;
}

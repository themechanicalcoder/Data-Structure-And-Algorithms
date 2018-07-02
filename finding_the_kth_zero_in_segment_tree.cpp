#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
int a[]={0,1,2,3,0,5,6,7,0,10,12,1,15,16,0,1,4,6,0,56};
int t[4*MAXN];
void build(int v,int tl,int tr){
    if(tl==tr ){
            if(a[tl]==0)
                t[v]=1;//if the element is 0 assign t[v]=1
            else
                t[v]=0;//else 0
        return;}
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=t[2*v]+t[2*v+1];
}

int find_kth(int v,int tl,int tr,int k){
    if(t[v]<k)
        return -1;//if the element is not found
    if(tl==tr)
        return tl;
    int tm=(tl+tr)/2;
    if(t[2*v]>=k)
        return find_kth(v*2,tl,tm,k);
    else
        return find_kth(v*2+1,tm+1,tr,k-t[2*v]);
}
void update(int v,int tl ,int tr,int pos,int new_val){

    //reached a node
    if(tl==tr){
        if(new_val==0)
            t[v]=1;
        else
            t[v]=0;
        return ;
    }
    int tm=(tl+tr)/2;

    //checking for the left child
    if(pos<=tm)
        update(v*2,tl,tm,pos,new_val);

    //checking for the right child
    else
        update(2*v+1,tm+1,tr,pos,new_val);

    t[v]=t[v*2]+t[v*2+1];


}









int main(){
int n=sizeof(a)/sizeof(a[0]);
build(1,0,n-1);
cout<<find_kth(1,0,n-1,4)<<"\n";
update(1,0,n-1,14,3);
cout<<find_kth(1,0,n-1,4)<<"\n";
return 0;
}

//search for maximum/minimum and find the number of times it occurs
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int >ii;
#define MAXN 100000
#define n 9
#define INF INT_MIN
ii t[4*MAXN];
int a[]={-1,2,-3,4,6,11,11,16,11};
ii combine(ii a,ii b){
    if(a.first>b.first)
        return a;
    if(b.first>a.first)
        return b;
    return make_pair(a.first,a.second+b.second);
}

void build(int v,int tl ,int tr){
    if(tl==tr){
        t[v]=make_pair(a[tl],1);
        return;
        }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=combine(t[2*v],t[2*v+1]);
}
//returns a pair with first as max_element and second as the number of times it occur element
ii get_max(int v,int tl,int tr,int l,int r){
    if(l>r)
        return make_pair(INF,0);
    if(tl==l && tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    return combine(get_max(2*v,tl ,tm,l,min(r,tm)),
                   get_max(2*v+1,tm+1,tr,max(1+tm,l),r));
}

void update(int v,int tl,int tr,int pos,int new_value){
    if(tl==tr){
        t[v]=make_pair(new_value,1);
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
build(1,0,8);
ii m=get_max(1,0,8,3,6);
cout<<"the max_element is "<<m.first<<" and it has occured "<<m.second<<"number if times \n";
update(1,0,8,0,25);
update(1,0,8,1,25);
m=get_max(1,0,8,0,6);
cout<<"the max_element after update is "<<m.first<<" and it has occured "<<m.second<<"number if times \n";

return 0;
}

#include<bits/stdc++.h>
using namespace std;
string p,t;
vector<int>lps(9);
void prefix_fuction(){
    lps.assign(p.length(),0);
    int j=0;
    for(int i=1;i<p.length();i++){
        while(j>0 && p[i]!=p[j]){
            j=lps[j-1];}
        if(p[i]==p[j])
            j++;
        lps[i]=j;

    }
}


void kmp(){

    int m=p.length();
    prefix_fuction();
    int j=0;
    for(int i=0;i<t.length();i++){
        while (j>0 && p[j]!=t[i])
            j=lps[j-1];
          if(j==m-1){
            cout<<"pattern found at index "<<(i-j);
            j=lps[j-1];
            return;}

        else if(p[j]==t[i])
            j++;
    }

cout<<"not found "<<j;
}




int main(){

    p="ABABCABAB";
    t="ABABDABACDABABCABAB";
    cout<<p.length()<<"\n";
    kmp();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

string   lcs(string s1,string s2){

    if ((s1.length()==0)||(s2.length()==0))
        return "";




    int m=s1.length(),n=s2.length();
    int a[m+1][n+1];
    //cout<<m<<" "<<n;

    int i,j;
    for( i=0;i<=m;i++){
        for( j=0;j<=n;j++){
                if(i==0||j==0){
                    a[i][j]=0;
                }
            else if(s1[i-1]==s2[j-1]){
                a[i][j]=a[i-1][j-1]+1;
                }
            else
               a[i][j]=max(a[i-1][j],a[i][j-1]);



        }
    }
int l;
l=a[m][n];
string s="";

while((i!=0)&&(j!=0)){
    if(s1[i-1]==s2[j-1])
        s+=s1[i-1];
    if(a[i][j]==a[i-1][j]){
        i=i-1;

    }
    if(a[i][j]==a[i][j-1])
        j=j-1;
    else{
        i=i-1;
        j=j-1;
    }
}
reverse(s.begin(),s.end());
return s;
}



int main(){
string s1="aggtab";
string s2="gxtxayb";
cout<<lcs(s1,s2);
return 0;
}


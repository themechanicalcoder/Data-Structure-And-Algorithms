#include<bits/stdc++.h>
using namespace std;

string coinproblem(int coins[] ,int amount,int n ){
    string s="";
    int a[n+1][amount+1];
    int i,j;
    for( i=0;i<=n;i++){
        for(j=0;j<=amount;j++){
            if((i==0)||(j==0))
                a[i][j]=0;

            else if(i==1){
                    a[i][j]=1;}
            else if (coins[i]>=j){
                    a[i][j]=a[i-1][j];
            }

                       else{
                min(a[i-1][j],1+a[i][j-coins[i]]);
            }


        }
    }
    int number=a[n][amount];
    while(a[i][j]!=0){

        if(a[i-1][j]==a[i][j])
            i=i-1;
        else{
            i=i-coins[i];
            s+to_string(coins[i]);
        }

    }

return s;

}



int main(){

int arr[] = {1,3,5,7};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<coinproblem(arr,11,m);
    return 0;


}

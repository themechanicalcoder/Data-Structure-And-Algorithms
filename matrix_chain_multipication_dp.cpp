#include<bits/stdc++.h>
using namespace std;

int matrix_mult(int p[],int n){
    int m[n][n];
    int j;
    for(int i=1;i<n;i++)
        m[i][i]=0;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
        }

    }


return m[1][n-1];
}


int main(){

int arr[] = {40, 20, 30, 10,30};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<matrix_mult( arr,n);
  return 0;
}


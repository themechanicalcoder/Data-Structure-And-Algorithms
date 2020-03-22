#include<bits/stdc++.h>
using namespace std;

int matrix_mult(int m[],int i,int j){
    if(i==j){
        return 0;
    }
    int count1 =INT_MAX;
    for(int k=i;k<j;k++)
        count1=min(count1,matrix_mult(m,i,k)+matrix_mult(m,k+1,j)+m[i-1]*m[k]*m[j]);


return count1 ;
}




int main(){

  int arr[] = {1, 2, 3, 4,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<matrix_mult( arr,1,n-1);
  return 0;


}

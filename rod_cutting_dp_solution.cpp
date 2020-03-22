//time complexity=O(n^2)
//memory complexity=O(n)

#include<bits/stdc++.h>
using namespace std;

int cutrod(int p[],int n){
    int r[n+1];
    r[0]=0;
    int i,j;
    //cout<<r[n];
    for(i=1;i<=n;i++){
        int q=INT_MIN;
        for( j=0;j<i;j++){
            q=max(q,r[i-j-1]+p[j]);
        }
        r[i]=q;

    }
return r[n];


}


int main(){

int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
cout<<cutrod(arr,sizeof(arr)/sizeof(arr[0]));
return 0;

}

#include<bits/stdc++.h>
using namespace std;
//maz_ref=answer of the full array
int lis_recursive(int a[],int n,int max_ref){
    if(n==1)
        return 1;
        //max_ending_here=length of lis ending with arr[n-1]
    int res,max_ending_here=1;
    for(int i=1;i<n;i++){
        res=lis_recursive(a,i,max_ref);
        if(a[i-1]<a[n-1]&&res+1>max_ending_here)
            max_ending_here=res+1;
    }
    if(max_ref<max_ending_here)
        max_ref=max_ending_here;

return max_ending_here;
}
int lis_dp(int a[],int n){
    int lis[n],i,j;
    for(int i=0;i<n;i++)
        lis[i]=1;

    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[i]>a[j]&& lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
 int ans=0;
 for(int i=0;i<n;i++)
    ans=max(ans,lis[i]);
 return ans;

 }



int main(){
int a[]={10,22,9,33,21,50,41,60};
int n=sizeof(a)/sizeof(a[0]);
cout<<n<<"\n";
cout<<"the length of lis is "<<lis_dp(a,n);
return 0;
}


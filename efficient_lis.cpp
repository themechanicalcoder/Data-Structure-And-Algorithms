 #include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;

int find_lis_length(int a[],int n){
    multiset<int >s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        auto it=s.upper_bound(a[i]);//lower bound for strictly increasing s.lower_bound;it++;
        if(it!=s.end())
            s.erase(it);}
return s.size();

}
void print(int a[],auto& parent,multiset<ii>&s){
    stack<int>lis;
   //start from the last element of s
    int index=s.rbegin()->second;
    int n=s.size();
    //retrieve lis elment from the parent map
    while(n--){
        lis.push(a[index]);
        index=parent[index];
    }
    cout<<"lis is ";
    while(!lis.empty()){
        cout<<lis.top()<<" ";
        lis.pop();
    }

}
void print_lis(int a[],int n){
    multiset<ii>s;
    //for storing array  element ,index
    unordered_map<int,int>parent;//predecessor of element at index i
    //LIS  ending at index i
    for(int i=0;i<n;i++){
        ii p=make_pair(a[i],i);
        auto it=s.insert(p);
        // if not inserted then delete the next node
        if(++it!=s.end())
            s.erase(it);
    //iterator to find the current node and update the predecessor
    it=s.find(p);
        parent[i]=(--it)->second;
    }

print(a,parent,s);
}


int main(){
int arr[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<"the length of the longest increasing subsequence is "<<find_lis_length(arr,n)<<"\n";
print_lis(arr,n);
return 0;
}

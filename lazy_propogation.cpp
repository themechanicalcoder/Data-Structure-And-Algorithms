#include<algorithm>
#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>

#define LL long long
#define endl "\n"

using namespace std;

LL tree[1200001] ;
LL lazy[1200001] ;
int a[100001] ;

void Make_tree(int node,int low,int high);
void add_update(int node,int low,int high,int qlow,int qhigh,LL v) ;
LL query(int node,int low,int high,int qlow,int qhigh) ;

int main()
{
 	int t,n,q,x,y,k ;
 	LL v ;
 	scanf("%d",&t) ;
 	while(t--)
 	{
 	   scanf("%d %d",&n,&q) ;

 	   //memset(a,0,sizeof(int)) ;
 	   memset(tree,0,sizeof(tree)) ;
 	   memset(lazy,0,sizeof(lazy));
 	  // a = new int[n] ;
 	   //tree = new LL[n<<2] ;
 	   //lazy = new LL[n<<2] ;

 	    //Make_tree(1,0,n-1) ;

 	   while(q--)
 	   {
 	      scanf("%d %d %d",&k,&x,&y) ;
 	     if(k==0)
 	     {
 	         scanf("%lld",&v) ;
 	         add_update(1,0,n-1,x-1,y-1,v) ;
 	     }
 	     else
 	     {
 	         cout<<query(1,0,n-1,x-1,y-1)<<endl ;
 	     }
 	   }
 	  // delete[] a ;
 	   //delete[] tree ;
 	 //  delete[] lazy ;
  	 }
	return 0;
}
void Make_tree(int node,int low,int high)
{
	if(low>high)
	return ;
    if(low==high)
    {
        tree[node] = a[low] ;
        return ;

    }
    Make_tree(2*node,low,(low+high)/2) ;
    Make_tree(2*node+1,(low+high)/2 + 1 , high) ;

    tree[node] = tree[2*node] + tree[2*node+1] ;
}
void add_update(int node,int low,int high,int qlow,int qhigh,LL v)
{
    if(lazy[node])
    {
        tree[node] += (lazy[node]*((LL)(high - low + 1)))  ;

        if(low!=high)
        {
            int mid = (low + high)/2 ;
            lazy[2*node] += lazy[node] ;
            lazy[2*node+1] +=lazy[node] ;
        }
        lazy[node] = 0 ;
    }
    if(qlow > high || qhigh < low || low > high)
     return ;
     //the segment is a subset of the given range
    if(qlow<=low && qhigh>=high)
    {
        tree[node] += (v*((LL)(high - low + 1) ));
        if(low!=high)
        {
            lazy[2*node] += v ;
            lazy[2*node+1] += v ;
        }

        return ;   /* because we are lazy to go deeper :D */
    }

    add_update(2*node,low,(low+high)/2,qlow,qhigh,v) ;
    add_update(2*node+1,(low+high)/2 + 1,high,qlow,qhigh,v) ;

    tree[node] = tree[2*node] + tree[2*node+1] ;
}
LL query(int node,int low,int high,int qlow,int qhigh)
{
    if(low > high || qlow > high || qhigh < low)
     return 0 ;
    if(lazy[node])
    {
        tree[node] += (lazy[node]*((LL)(high - low + 1)))  ;
        if(low!=high)
        {
            int mid = (low + high)/2 ;
            lazy[2*node] +=lazy[node] ;
            lazy[2*node+1] +=lazy[node] ;
        }
        lazy[node] = 0 ;
    }
    if(qlow<=low && qhigh>=high)
     {
      return (tree[node]);
     }
   int mid = (high + low)/2 ;
   return (query(2*node,low,mid,qlow,qhigh) + query(2*node+1,mid + 1,high,qlow,qhigh)) ;
}

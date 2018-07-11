//problem codechef add mul  queries add update mul

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cerr<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define fast_cin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define UNIQUE(v)        (v).erase(unique((v).begin(),(v).end()),(v).end())
#define POPCOUNT         __builtin_popcountll
#define RIGHTMOST        __builtin_ctzll
#define LEFTMOST(x)      (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y)    (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x)          if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x)           (((x)&1)==0?(0):(1))
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

using namespace std;

//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

#define mx 100005
#define segment_tree int l=n*2,r=l+1,mid=(b+e)/2

struct data
{
    ll sum,lazys,lazym,lazyu;
};

data tree[3*mx];
ll ara[mx];

void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n].sum+=ara[b];
        tree[n].lazys=tree[n].lazyu=0;
        tree[n].lazym=1;
        return;
    }
    segment_tree;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[n].sum=(tree[l].sum+tree[r].sum)%MOD;
    tree[n].lazym=1;
}

void push_down(ll n, ll b, ll e)
{
    segment_tree;
    if(tree[n].lazyu!=0)
    {
        tree[l].lazym=1;
        tree[l].lazys=0;
        tree[l].lazyu=tree[n].lazyu;
        tree[l].sum=((mid-b+1)*tree[n].lazyu)%MOD;
        tree[l].sum%=MOD;

        tree[r].lazym=1;
        tree[r].lazys=0;
        tree[r].lazyu=tree[n].lazyu;
        tree[r].sum=((e-mid)*tree[n].lazyu)%MOD;
        tree[r].sum%=MOD;
        tree[n].lazyu=0;
    }
    if(tree[n].lazym!=1)
    {
        tree[l].lazym=(tree[l].lazym*tree[n].lazym)%MOD;
        tree[l].lazys=(tree[l].lazys*tree[n].lazym)%MOD;
        tree[l].sum=(tree[l].sum*tree[n].lazym)%MOD;;

        tree[r].lazym=(tree[r].lazym*tree[n].lazym)%MOD;
        tree[r].lazys=(tree[r].lazys*tree[n].lazym)%MOD;
        tree[r].sum=(tree[r].sum*tree[n].lazym)%MOD;
        tree[n].lazym=1;
    }
    if(tree[n].lazys!=0)
    {
        tree[l].lazys=(tree[l].lazys+tree[n].lazys)%MOD;
        tree[l].sum+=((mid-b+1)*tree[n].lazys)%MOD;;
        tree[l].sum%=MOD;

        tree[r].lazys=(tree[r].lazys+tree[n].lazys)%MOD;
        tree[r].sum+=((e-mid)*tree[n].lazys)%MOD;;
        tree[l].sum%=MOD;
        tree[n].lazys=0;
    }
}

void update(ll n, ll b, ll e, ll i, ll j, ll val, ll id)
{
    if(b>j || e<i) return;
    if(b>=i && e<=j)
    {
        if(id==0) // up
        {
            tree[n].lazys=0;
            tree[n].lazym=1;
            tree[n].lazyu=val;
            tree[n].sum=((e-b+1)*val)%MOD;
        }
        else if(id==1) //sum
        {
            tree[n].lazys=(tree[n].lazys+val)%MOD;;
            tree[n].sum+=((e-b+1)*val)%MOD;
            tree[n].sum%=MOD;
        }
        else if(id==2) // mul
        {
            tree[n].lazys=(tree[n].lazys*val)%MOD;
            tree[n].lazym=(tree[n].lazym*val)%MOD;
            tree[n].sum=(tree[n].sum*val)%MOD;
        }
        return;
    }
    push_down(n,b,e);
    segment_tree;
    update(l,b,mid,i,j,val,id);
    update(r,mid+1,e,i,j,val,id);
    tree[n].sum=(tree[l].sum+tree[r].sum)%MOD;
}


ll query(ll n, ll b, ll e, ll i, ll j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j)
    {
        return tree[n].sum;
    }
    push_down(n,b,e);
    segment_tree;
    ll p=query(l,b,mid,i,j);
    ll q=query(r,mid+1,e,i,j);
    return (p+q)%MOD;
}

int main()
{
//    freopen("in.txt","r",stdin);
//	  freopen("out.txt","w",stdout);

    int n,q;
    sff(n,q);
    for(int i=1; i<=n; i++)
    {
        sfl(ara[i]);
    }

    init(1,1,n);

    while(q--)
    {
        ll a,b,c,d;
        sfl(a);
        if(a==1)
        {
            sfffl(b,c,d);
            update(1,1,n,b,c,d,1);
        }
        else if(a==2)
        {
            sfffl(b,c,d);
            update(1,1,n,b,c,d,2);
        }
        else if(a==3)
        {
            sfffl(b,c,d);
            update(1,1,n,b,c,d,0);
        }
        else if(a==4)
        {
            sffl(b,c);
            ll ans=query(1,1,n,b,c);
            printf("%lld\n",ans);
        }
//        D(query(1,1,n,1,n));

    }


    return 0;
}

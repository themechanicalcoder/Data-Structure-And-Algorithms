#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
int mod=1e9+7;
const int maxn=2e5+5;

#define pb push_back
#define f first
#define s second
#define rep(i,start,lim) for(ll i=start;i<lim;i++)
#define repd(i,start,lim) for(ll i=start;i>=lim;i--)
#define forn(i, n)   for (int i = 0; i < int(n); i++)
#define forall(it,m) for(auto it=(m).begin();it!=(m).end();it++)
#define all(v) (v).begin(), (v).end()
#define sz(v)  (v).size()

void input(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
    #endif
}

void Sieve(ll n){bool prime[n+1];memset(prime, true, sizeof(prime));for (int p=2; p*p<=n; p++) {if (prime[p] == true) {for (int i=p*p; i<=n; i += p)prime[i] = false;}}}
ll pw(int x, unsigned int y, int p) { ll res = 1;x = x % p;while (y > 0){ if (y & 1)res =1ll*(res*x) % p;y = y>>1;x = (1ll*x*x) % p;}return res;}


class d_set{
public:
    vector<int>parent;
    vector<int>rnk;
    d_set(int n){
        rnk.assign(n,0);
        parent.assign(n,0);
        forn(i,n)parent[i]=i;
    }

    int find(int u){
    if(u!=parent[u])
        parent[u]=find(parent[u]);

    return parent[u];
    }
    void union1(int x,int y){
    int xset=find(x);
    int yset=find(y);

    if(rnk[xset]>rnk[yset])
        parent[yset]=xset;
    else if(rnk[yset]>rnk[xset])
        parent[xset]=yset;
    else{
        parent[yset]=xset;
        rnk[xset]+=1;
    }

}

};


vector<pair<char,char>>v;
int main(){
    input();

    return 0;

}

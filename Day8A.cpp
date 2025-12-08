#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <string>
#include <sys/types.h>
#include <vector>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<string> vs;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define FORl(i, a, b) for (ll i = a; i < (b); i++)
#define F0Rl(i, a) for (ll i = 0; i < (a); i++)
#define FORld(i, a, b) for (ll i = (b) - 1; i >= a; i--)
#define F0Rld(i, a) for (ll i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
const int MOD = 1000000007;
const int MUD = 998244353;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int find(int child, vi &parent){
    if(parent[child]==child) return child;
    return parent[child]=find(parent[child],parent);
}

void unite(int u, int v, vi &parent, vi &size){

    int pu=find(u,parent);
    int pv=find(v,parent);

    if(pu==pv) return;

    if(size[pu]>size[pv]){
        parent[pv]=pu;
        size[pu]+=size[pv];
    }
    else{
        parent[pu]=pv;
        size[pv]+=size[pu];
    }

}

void solve(){

    string s;

    vector<vl> pnts;

    while(cin>>s){
        string t="";
        vl pnt;

        for(auto &x:s){
            if(x==','){
                pnt.pb(stol(t));
                t="";
            }
            else{
                t+=x;
            }
        }
        pnt.pb(stol(t));
        pnts.pb(pnt);
    }

    int n=pnts.size();

    vector<vl> dist;
    F0R(i,n){
        FOR(j,i+1,n){
            ll d=(pnts[i][0]-pnts[j][0])*(pnts[i][0]-pnts[j][0])+(pnts[i][1]-pnts[j][1])*(pnts[i][1]-pnts[j][1])+(pnts[i][2]-pnts[j][2])*(pnts[i][2]-pnts[j][2]);
            dist.pb({d,i,j});
        }
    }

    sort(all(dist));

    vector<int> par(n), size(n,1);
    F0R(i,n) par[i]=i;

    for(int i=0;i<1000;i++){
        unite(dist[i][1],dist[i][2],par,size);
    }

    vl sizes;

    F0R(i,n){
        if(par[i]==i){
            sizes.pb(size[i]);
        }
    }

    sort(all(sizes),greater<ll>());

    cout<<sizes[0]*sizes[1]*sizes[2]<<"\n";
    
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;

    cout << fixed;
    cout.precision(20);

    
    while (t--)
    {
        solve();
    }
    return 0;
}
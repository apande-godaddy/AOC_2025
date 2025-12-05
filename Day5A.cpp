#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
typedef vector<int> vs;

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

void solve(){

    vector<pair<ll,ll>> ranges;
    vl val;

    string s;
    while(cin>>s){
        string t="";
        pair<ll,ll> p;

        int mk=0;
        for(auto &x:s){
            if(x=='-'){
                p.first=stol(t);
                t="";
                mk=1;
            }
            else{
                t+=x;
            }
        }

        if(t!=""){
            if(mk==1){
                p.second=stol(t);
                ranges.pb(p);
            }
            else{
                val.pb(stol(t));
            }
        }
    }


    int n=ranges.size();

    sort(all(ranges));

    map<ll,ll> mp;

    ll st=-1;
    ll end=-1;

    F0R(i,n){
        if(ranges[i].first<=end){
            end=max(end,ranges[i].second);
        }
        else{
            if(st!=-1) mp[st]=end;
            st=ranges[i].first;
            end=ranges[i].second;
        }
    }
    mp[st]=end;


    int ans=0;
    for(auto &x:val){
        auto it=mp.upper_bound(x);
        if(it!=mp.begin()){
            it--;
            if(x<=it->second) ans++;
        }
    }

    cout<<ans<<"\n";

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
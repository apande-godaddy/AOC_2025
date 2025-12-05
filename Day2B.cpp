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

    string s;
    cin>>s;


    vl v;

    int n=s.size();

    int mx=0;
    string t="";
    F0R(i,n){
        if(s[i]=='-' || s[i]==','){
            v.pb(stol(t));
            mx=max(mx,(int)t.size());
            t="";
        }
        else{
            t+=s[i];
        }
    }
    v.pb(stol(t));
    mx=max(mx,(int)t.size());

    // cout<<mx<<"\n";

    int m=v.size();

    set<ll> pos;
    for(int i=0;i<100000;i++){
        string curr=to_string(i);
        string ncurr=curr;
        while(ncurr.size()<=10){
            ncurr+=curr;
            pos.insert(stol(ncurr));
        }
    }

    map<ll,ll> mp;
    mp[0]=0;

    ll lst=0;
    for(auto &x:pos){
        mp[x]=lst+x;
        lst=mp[x];
    }

    ll ans=0;
    for(int i=0;i<m;i+=2){
        
        auto low=mp.lower_bound(v[i]);
        auto high=mp.upper_bound(v[i+1]);
        high--;
        low--;

        // cout<<high->second<<" "<<low->second<<"\n";
        ans+=high->second-low->second;

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
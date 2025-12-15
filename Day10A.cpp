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

void solve(){

    string s;

    vs pat;
    vector<vector<vi>> mark;
    vector<vi> jolt;
    
    while(cin>>s){
        int n=s.size();

        if(s[0]=='['){
            pat.pb(s.substr(1,n-2));
            
            string t;
            vector<vi> mrk;
            while(cin>>t){
                int m=t.size();

                vi val;
                if(t[0]=='('){
                    string v="";
                    FOR(i,1,m){
                        if('0'<=t[i] && t[i]<='9'){
                            v+=t[i];
                        }
                        else{
                            val.pb(stoi(v));
                            v="";
                        }
                    }
                    mrk.pb(val);
                }

                if(t[0]=='{'){
                    string v="";
                    FOR(i,1,m){
                        if('0'<=t[i] && t[i]<='9'){
                            v+=t[i];
                        }
                        else{
                            val.pb(stoi(v));
                            v="";
                        }
                    }
                    jolt.pb(val);
                    break;
                }
            }
            mark.pb(mrk);

        }

    }

    int n=pat.size();
    int ans=0;

    F0R(i,n){
        int nans=INT_MAX;

        int m=mark[i].size();
        int p=pat[i].size();

        F0R(j,(1<<m)){
            vi vals(p);
            F0R(k,m){
                if(j&(1<<k)){
                    for(auto &x:mark[i][k]){
                        vals[x]=1-vals[x];
                    }
                }
            }

            int t=1;
            F0R(k,p){
                if((vals[k]==1 && pat[i][k]=='.') || (vals[k]==0 && pat[i][k]=='#')){
                    t=0;
                    break;
                }
            }

            if(t==1){
                nans=min(nans,__builtin_popcount(j));
            }
        }

        ans+=nans;
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
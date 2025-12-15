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

    vector<vs> grid;

    vector<vi> cross;
    vector<vi> cnt;

    while(cin>>s){

        vs arr;
        if(s.size()==2 && s.back()==':'){
            F0R(i,3){
                cin>>s;
                arr.pb(s);
            }
            grid.pb(arr);
        }

        if(s.size()>2 && s.back()==':'){
            vi arr;
            string t="";
            for(auto &x:s){
                if(x=='x' || x==':'){
                    arr.pb(stoi(t));
                    t="";
                }
                else{
                    t+=x;
                }
            }
            cross.pb(arr);

            vi a;
            F0R(i,6){
                cin>>s;
                a.pb(stoi(s));
            }
            cnt.pb(a);
        }

    }

    int uncertain=0;
    int not_valid=0;
    int ans=0;

    vi hash_cnt={7,6,5,7,7,7};

    int n=cross.size();
    F0R(i,n){
        int cnt1=cross[i][0]/3;
        int cnt2=cross[i][1]/3;

        int tot=cnt1*cnt2;

        int sum1=0;
        int sum2=0;

        int m=cnt[i].size();

        F0R(j,m){
            sum1+=cnt[i][j];
            sum2+=hash_cnt[j]*cnt[i][j];    
        }

        if(sum1<=tot) ans++;
        else if(sum2>cross[i][0]*cross[i][1]) not_valid++;
        else uncertain++;
    }

    cout<<not_valid<<"\n";
    cout<<ans<<"\n";
    cout<<uncertain<<"\n";
    
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
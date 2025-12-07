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

    vs grid;

    while(cin>>s){
        grid.pb(s);
    }

    queue<pair<int,int>> q;

    int n=grid.size();
    int m=grid[0].size();

    vector<vi> vis(n,vi(m));

    F0R(i,n){
        F0R(j,m){
            if(grid[i][j]=='S'){
                q.push({i,j});
                vis[i][j]=1;
                break;
            }
        }
    }

    int ans=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        int nx=x+1;
        if(nx<n && vis[nx][y]==0){
            if(grid[nx][y]=='^'){
                int ny1=y-1;
                int ny2=y+1;
                if(ny1>=0 && vis[nx][ny1]==0){
                    vis[nx][ny1]=1;
                    q.push({nx,ny1});
                }
                if(ny2<m && vis[nx][ny2]==0){
                    vis[nx][ny2]=1;
                    q.push({nx,ny2});
                }
                ans++;
            }
            else{
                vis[nx][y]=1;
                q.push({nx,y});
            }
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
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

    vector<vl> pnts;

    while(cin>>s){
        int n=s.size();

        F0R(i,n){
            if(s[i]==','){
                pnts.pb({stol(s.substr(0,i)),stol(s.substr(i+1))});
                break;
            }
        }
    }

    int n=pnts.size();

    set<int> x_coord,y_coord;

    for(auto &x:pnts){
        x_coord.insert(x[0]);
        y_coord.insert(x[1]);
    }

    map<int,int> mpx,mpy,rmpx,rmpy;

    int curr=0;
    for(auto &x:x_coord){
        mpx[x]=curr;
        rmpx[curr]=x;
        curr+=2;
    }

    curr=0;
    for(auto &x:y_coord){
        mpy[x]=curr;
        rmpy[curr]=x;
        curr+=2;
    }

    vector<vi> npnts(n,vi(2));
    vector<vi> grid(1000,vi(1000));

    F0R(i,n){
        npnts[i][0]=mpx[pnts[i][0]];
        npnts[i][1]=mpy[pnts[i][1]];
    }

    F0R(i,n){
        int nxt=(i+1)%n;
        if(npnts[i][0]==npnts[nxt][0]){
            FOR(j,min(npnts[i][1],npnts[nxt][1]),max(npnts[i][1],npnts[nxt][1])+1){
                grid[npnts[i][0]][j]=1;
            }
        }
        else{
            FOR(j,min(npnts[i][0],npnts[nxt][0]),max(npnts[i][0],npnts[nxt][0])+1){
                grid[j][npnts[i][1]]=1;
            }
        }
    }

    sort(all(npnts));

    int stx=npnts[0][0],sty=npnts[0][1];
    stx++;
    sty++;

    queue<pair<int,int>> q;
    q.push({stx,sty});
    grid[stx][sty]=1;

    vi dx={0,1,0,-1};
    vi dy={-1,0,1,0};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        F0R(i,4){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(grid[nx][ny]==0){
                grid[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }

    vector<vi> pref(1001,vi(1001));

    FOR(i,1,1001){
        FOR(j,1,1001){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            pref[i][j]+=grid[i-1][j-1];
        }
    }

    ll ans=0;

    F0R(i,n){
        FOR(j,i+1,n){
            int x1=npnts[i][0];
            int y1=npnts[i][1];
            int x2=npnts[j][0];
            int y2=npnts[j][1];

            int mnx=min(x1,x2);
            int mxx=max(x1,x2);
            int mny=min(y1,y2);
            int mxy=max(y1,y2);

            ll cnt1=pref[mxx+1][mxy+1]-pref[mnx][mxy+1]-pref[mxx+1][mny]+pref[mnx][mny];
            ll cnt2=(mxx-mnx+1)*(mxy-mny+1);

            if(cnt1==cnt2){
                ll nx1=rmpx[mnx];
                ll ny1=rmpy[mny];
                ll nx2=rmpx[mxx];
                ll ny2=rmpy[mxy];

                ans=max(ans,(nx2-nx1+1)*(ny2-ny1+1));
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
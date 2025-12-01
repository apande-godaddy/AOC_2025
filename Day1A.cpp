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

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

int fib(int n)
{
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}

int phi(int n)
{

    // Initialize result as n
    float result = n;

    // Consider all prime factors of n
    // and for every prime factor p,
    // multiply result with (1 - 1/p)
    for (int p = 2; p * p <= n; ++p)
    {

        // Check if p is a prime factor.
        if (n % p == 0)
        {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;

            result *= (1.0 - (1.0 / (float)p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    // Since in the set {1,2,....,n-1}, all numbers are relatively prime with n
    // if n is a prime number

    return (int)result;
}

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll m)
{
    return binpow(n, m - 2, m);
}

ll nCrMod(ll n, ll r, ll m, vl &fac, vl &ifac)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    return (fac[n] * ifac[r] % m * ifac[n - r] % m) % m;
}

vector<int> z_func(string &s)
{

    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[z[i] + i])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}


void solve(){

    string s;

    int val=50;
    int cnt=0;
    while(cin>>s){
        int turn=stoi(s.substr(1));
        if(s[0]=='L'){
            val=(val-turn%100+100)%100;
        }
        else{
            val=(val+turn)%100;
        }
        if(val==0) cnt++;
    }

    cout<<cnt<<"\n";

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
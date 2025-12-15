#include "ortools/linear_solver/linear_solver.h"
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace operations_research;

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

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define FORl(i, a, b) for (ll i = a; i < (b); i++)
#define F0Rl(i, a) for (ll i = 0; i < (a); i++)
#define FORld(i, a, b) for (ll i = (b) - 1; i >= a; i--)
#define F0Rld(i, a) for (ll i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
const int MOD = 1000000007;
const int MUD = 998244353;

vs pat;
vector<vector<vi>> mark;
vector<vi> jolt;

int helper(int ind) {
  MPSolver solver("ILP", MPSolver::SCIP_MIXED_INTEGER_PROGRAMMING);

  int n = mark[ind].size();
  vector<MPVariable *> var(n);
  F0R(i, n) {
    var[i] = solver.MakeIntVar(0.0, MPSolver::infinity(), to_string(i));
  }

  int m = pat[ind].size();
  vector<MPConstraint *> constraint(m);
  F0R(i, m) {
    constraint[i] = solver.MakeRowConstraint(jolt[ind][i], jolt[ind][i]);
  }

  F0R(i, n) {
    for (auto &x : mark[ind][i]) {
      constraint[x]->SetCoefficient(var[i], 1);
    }
  }

  MPObjective *obj = solver.MutableObjective();
  F0R(i, n) { obj->SetCoefficient(var[i], 1); }
  obj->SetMinimization();

  MPSolver::ResultStatus status = solver.Solve();

  return (int)obj->Value();
}

void solve() {

  string s;

  while (cin >> s) {
    int n = s.size();

    if (s[0] == '[') {
      pat.pb(s.substr(1, n - 2));

      string t;
      vector<vi> mrk;
      while (cin >> t) {
        int m = t.size();

        vi val;
        if (t[0] == '(') {
          string v = "";
          FOR(i, 1, m) {
            if ('0' <= t[i] && t[i] <= '9') {
              v += t[i];
            } else {
              val.pb(stoi(v));
              v = "";
            }
          }
          mrk.pb(val);
        }

        if (t[0] == '{') {
          string v = "";
          FOR(i, 1, m) {
            if ('0' <= t[i] && t[i] <= '9') {
              v += t[i];
            } else {
              val.pb(stoi(v));
              v = "";
            }
          }
          jolt.pb(val);
          break;
        }
      }
      mark.pb(mrk);
    }
  }

  int n = pat.size();
  int ans = 0;

  F0R(i, n) { ans += helper(i); }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t = 1;
  // cin >> t;

  cout << fixed;
  cout.precision(20);

  while (t--) {
    solve();
  }
  return 0;
}
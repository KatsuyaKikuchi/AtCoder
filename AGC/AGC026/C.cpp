#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

typedef pair<string, string> pss;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

map<pss, ll> m;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    ll max = pow(2, N);
    REP(i, max)
    {
        string r, b;
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
                r = r + S[N + j];
            else
                b = S[N + j] + b;
        }
        m[pss(r, b)]++;
    }
    ll ans = 0;
    REP(i, max)
    {
        string r, b;
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
                r = r + S[j];
            else
                b = S[j] + b;
        }
        ans += m[pss(b, r)];
    }
    cout << ans << endl;
    return 0;
}
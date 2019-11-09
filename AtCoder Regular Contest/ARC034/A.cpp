#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N;
    cin >> N;
    double max = 0;
    REP(i, N)
    {
        double s = 0;
        REP(i, 4)
        {
            double a;
            cin >> a;
            s += a;
        }
        double b;
        cin >> b;
        s += b * 110 / 900;
        max = std::max(s, max);
    }
    cout << OF64 << max << endl;
    return 0;
}
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
    ll A, B, X;
    cin >> A >> B >> X;
    if (A * A * B == X)
    {
        cout << 0 << endl;
        return 0;
    }

    if (A * A * B >= 2 * X)
    {
        double t = 2.0 * (double)X / (double)(A * B);
        double theta = std::atan((double)B / t) * 180.0 / M_PI;
        cout << OF64 << theta << endl;
    }
    else
    {

        double t = 2.0 * B - 2.0 * ((double)X / (double)(A * A));

        double theta = std::atan(t / (double)A) * 180.0 / M_PI;

        cout << OF64 << theta << endl;
    }
    return 0;
}
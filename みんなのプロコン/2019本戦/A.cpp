#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;
double solve(double X, double Y)
{
    double Z = X - Y;
    if (Z > Y)
    {
        return (Z * Y * Y - Y * Y * Y / 3) / (Z * Z);
    }
    else
    {
        return Y - Z / 3;
    }
    return 0;
}
int main()
{
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    cout << OF64 << solve(H, A) * solve(W, B) << endl;
    return 0;
}
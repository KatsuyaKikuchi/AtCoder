#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double P;

double calc(double x)
{
    return x + P / (pow(2.0, x / 1.5));
}

int main()
{
    cin >> P;
    double l = 0, r = P;
    REP(i, 1000)
    {
        double a = (2.0 * l + r) / 3.0;
        double b = (l + 2.0 * r) / 3.0;
        if (calc(a) > calc(b))
            l = a;
        else
            r = b;
    }

    cout << OF64 << calc(l) << endl;
    return 0;
}
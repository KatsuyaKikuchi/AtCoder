#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll X[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> X[i].first;
    }
    REP(i, N)
    {
        cin >> X[i].second;
    }
    sort(X, X + N, [](pll a, pll b) { return a.second - a.first < b.second - b.first; });

    ll s = 0;
    REP(i, N)
    {
        ll t = X[i].second - X[i].first;
        if (t < 0)
        {
            s += abs(t);
            continue;
        }

        s -= t / 2;
        if (s <= 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
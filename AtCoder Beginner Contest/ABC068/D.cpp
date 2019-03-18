#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

const ll MAX = (ll)1e16;

int main()
{
    ll K;
    cin >> K;

    ll t = std::max((MAX + K - 1) / MAX, (ll)2);
    ll n = K / t;
    ll m = K % t;
    vector<ll> v(t);
    REP(i, t)
    {
        if (i < m)
            v[i] = t - 1 + n + (t - (m - 1));
        else
            v[i] = t - 1 + n - m;
    }

    cout << t << endl;
    REP(i, t)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
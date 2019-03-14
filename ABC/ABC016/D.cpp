#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll G[105];

bool cross(pll a, pll b, pll c, pll d)
{
    ll u = (c.first - d.first) * (a.second - c.second) + (c.second - d.second) * (c.first - a.first);
    ll v = (c.first - d.first) * (b.second - c.second) + (c.second - d.second) * (c.first - b.first);
    ll w = (a.first - b.first) * (c.second - a.second) + (a.second - b.second) * (a.first - c.first);
    ll x = (a.first - b.first) * (d.second - a.second) + (a.second - b.second) * (a.first - d.first);

    return w * x < 0 && u * v < 0;
}

int main()
{
    pll A, B;
    cin >> A.first >> A.second >> B.first >> B.second;
    int N;
    cin >> N;

    REP(i, N)
    {
        cin >> G[i].first >> G[i].second;
    }

    int s = 0;
    REP(i, N)
    {
        if (cross(A, B, G[i], G[(i + 1) % N]))
            s++;
    }
    cout << s / 2 + 1 << endl;
    return 0;
}
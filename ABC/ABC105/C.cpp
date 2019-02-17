#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! nを-2で割ったあまりと商を計算
ll div(ll n)
{
    n = -1 * (n / abs(n)) * (abs(n - (abs(n) % 2))) / 2;
    return n;
}

int main()
{
    ll N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> t;
    while (N != 0)
    {
        t.push_back(abs(N) % 2);
        N = div(N);
    }

    std::reverse(t.begin(), t.end());
    REP(i, t.size())
    {
        cout << t[i];
    }
    cout << endl;
    return 0;
}
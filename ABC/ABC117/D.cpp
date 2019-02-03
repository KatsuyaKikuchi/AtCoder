#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
    REP(i, N)
    {
        cin >> A[i];
        sum += A[i];
    }

    vector<pll> v;
    //! 各bitを反転させるとどれだけ増える？
    REP(i, 40)
    {
        ll s = 0;
        ll bit = ((ll)1 << i);
        REP(j, N)
        {
            if ((A[j] & bit) > 0)
                s -= bit;
            else
                s += bit;
        }
        if (s > 0)
        {
            v.push_back(pll(bit, s));
        }
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.second == b.second ? a.first > b.first : a.second > b.second; });

    ll n = 0;
    REP(i, v.size())
    {
        if ((n | v[i].first) <= K)
        {
            n |= v[i].first;
            sum += v[i].second;
        }
    }
    cout << sum << endl;
    return 0;
}
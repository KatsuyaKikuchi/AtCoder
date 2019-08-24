#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll T[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> T[i];
    }
    sort(T, T + N);
    vector<pll> v;
    ll s = T[0];
    FOR(i, N, 1)
    {
        if (T[i - 1] + 1 == T[i])
            continue;
        v.push_back(pll(s, T[i - 1] + 1));
        s = T[i];
    }
    v.push_back(pll(s, T[N - 1] + 1));
    vector<ll> S;
    ll sum = 0;
    REP(i, v.size() - 1)
    {
        ll s = v[i + 1].first - v[i].second;
        S.push_back(s);
        sum += s;
    }
    sort(S.begin(), S.end(), [](ll a, ll b) { return a > b; });
    REP(i, std::min((ll)S.size(), K - 1))
    {
        sum -= S[i];
    }
    REP(i, v.size())
    {
        sum += v[i].second - v[i].first;
    }
    cout << sum << endl;

    return 0;
}
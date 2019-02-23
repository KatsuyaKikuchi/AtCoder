#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll T[100005];

int main()
{
    int N;
    ll K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> T[i].first >> T[i].second;
    }
    sort(T, T + N, [](pll a, pll b) { return a.first < b.first; });
    REP(i, N)
    {
        K -= T[i].second;
        if (K <= 0)
        {
            cout << T[i].first << endl;
            break;
        }
    }
    return 0;
}
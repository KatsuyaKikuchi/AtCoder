#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    ll sum = 0;
    REP(i, N)
    {
        ll l, r, s;
        cin >> l >> r >> s;
        sum += s;
        S[--l] += s;
        S[r] -= s;
    }

    REP(i, M)
    {
        if (i > 0)
            S[i] += S[i - 1];
    }

    ll min = INF;
    REP(i, M)
    {
        min = std::min(min, S[i]);
    }
    cout << sum - min << endl;
    return 0;
}
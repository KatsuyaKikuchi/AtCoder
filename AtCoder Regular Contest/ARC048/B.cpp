#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;
pll R[100005];
ll S[100005];
ll P[100005][5];

int main()
{
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    memset(P, 0, sizeof(P));

    REP(i, N)
    {
        ll r, h;
        cin >> R[i].first >> R[i].second;
        R[i].second--;
        P[R[i].first][R[i].second]++;
        S[R[i].first]++;
    }

    REP(i, 100000)
    {
        S[i + 1] += S[i];
    }

    REP(i, N)
    {
        ll l = 0, w = 0, d = 0;
        ll r = R[i].first, h = R[i].second;
        d = P[r][h] - 1;
        w = S[r - 1] + P[r][(h + 1) % 3];
        l = N - (d + w + 1);
        cout << w << " " << l << " " << d << endl;
    }
    return 0;
}
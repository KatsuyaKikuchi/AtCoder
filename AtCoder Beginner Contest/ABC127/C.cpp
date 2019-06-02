#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[100005];

ll T[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> A[i].first >> A[i].second;
        T[A[i].first - 1]++;
        T[A[i].second]--;
    }
    FOR(i, N, 1)
    {
        T[i] += T[i - 1];
    }

    int ans = 0;
    REP(i, N)
    {
        if (T[i] == M)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
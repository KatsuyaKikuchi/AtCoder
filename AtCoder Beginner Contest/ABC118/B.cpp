#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[35];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        T[i] = 0;
    }
    REP(i, N)
    {
        int k;
        cin >> k;
        REP(j, k)
        {
            int a;
            cin >> a;
            T[--a]++;
        }
    }
    int ans = 0;
    REP(i, M)
    {
        if (T[i] == N)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
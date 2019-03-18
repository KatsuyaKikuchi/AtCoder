#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[55];
pll B[55];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
    }
    REP(i, M)
    {
        cin >> B[i].first >> B[i].second;
    }
    REP(i, N)
    {
        int t = 0;
        REP(j, M)
        {
            ll l0 = abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second);
            ll l1 = abs(A[i].first - B[t].first) + abs(A[i].second - B[t].second);
            if (l0 < l1)
                t = j;
        }
        cout << t + 1 << endl;
    }
    return 0;
}
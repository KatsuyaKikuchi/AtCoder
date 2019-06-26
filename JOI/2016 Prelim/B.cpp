#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    FOR(i, M + 1, 1)
    {
        REP(j, N - 1)
        {
            ll a = A[j] % i;
            ll b = A[j + 1] % i;
            if (a <= b)
                continue;
            swap(A[j], A[j + 1]);
        }
    }
    REP(i, N)
    {
        cout << A[i] << endl;
    }
    return 0;
}
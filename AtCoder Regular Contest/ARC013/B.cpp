#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll C;
    cin >> C;
    ll N = 0, M = 0, L = 0;
    REP(i, C)
    {
        ll A[3];
        REP(j, 3)
        {
            cin >> A[j];
        }
        sort(A, A + 3);
        N = std::max(N, A[0]);
        M = std::max(M, A[1]);
        L = std::max(L, A[2]);
    }
    cout << N * M * L << endl;
    return 0;
}
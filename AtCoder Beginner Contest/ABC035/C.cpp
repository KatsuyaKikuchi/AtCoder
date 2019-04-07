#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[200005];

int main()
{
    ll N, Q;
    cin >> N >> Q;
    memset(A, 0, sizeof(A));
    REP(i, Q)
    {
        int l, r;
        cin >> l >> r;
        A[--l]++;
        A[r]--;
    }
    REP(i, N)
    {
        A[i + 1] += A[i];
        cout << A[i] % 2;
    }
    cout << endl;
    return 0;
}
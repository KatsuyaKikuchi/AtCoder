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
    int N, M, X;
    cin >> N >> M >> X;
    REP(i, M)
    {
        int a;
        cin >> a;
        A[a]++;
    }

    int l = 0;
    for (int i = 0; i <= X; ++i)
    {
        l += A[i];
    }
    int r = 0;
    for (int i = X; i <= N; ++i)
    {
        r += A[i];
    }
    cout << std::min(l, r) << endl;
    return 0;
}
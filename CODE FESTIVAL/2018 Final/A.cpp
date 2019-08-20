#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Node
{
    ll A;
    ll B;
    ll L;
};

bool U[100005];
ll A[100005][1005];

int main()
{
    ll N, M;
    cin >> N >> M;
    memset(A, 0, sizeof(A));
    REP(i, M)
    {
        ll a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        A[a][l - 1000]++;
        A[b][l - 1000]++;
    }

    ll ans = 0;
    REP(i, N)
    {
        for (int j = 1000; j < 1270; j++)
        {
            ans += A[i][j - 1000] * A[i][2540 - j - 1000];
        }
        ans += (A[i][270] * (A[i][270] - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
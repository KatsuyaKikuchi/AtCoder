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
    ll N, X, Y;
    cin >> N >> X >> Y;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    ll t = X, a = Y;
    REP(i, N)
    {
        if (i % 2 == 0)
            t += A[i];
        else
            a += A[i];
    }
    if (t > a)
        cout << "Takahashi" << endl;
    else if (t < a)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}
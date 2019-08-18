#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1000005];
string S;

int main()
{
    cin >> S;
    ll N = S.length();
    memset(A, 0, sizeof(A));
    REP(i, N)
    {
        if (i == 0 || S[N - i - 1] != S[N - i])
            A[N - i - 1] = 1;
        else
            A[N - i - 1] += A[N - i] + 1;
    }

    ll ans = 0;
    REP(i, N)
    {
        if (S[i] != 'J')
            continue;
        ll n = A[i];
        ll m = i + n;
        if (m >= N || S[m] != 'O' || A[m] != n)
            continue;
        m += n;
        if (m >= N || S[m] != 'I' || A[m] < n)
            continue;
        ans = std::max(ans, n);
    }
    cout << ans << endl;
    return 0;
}
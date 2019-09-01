#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
ll A[100005];
string solve()
{
    sort(A, A + N);

    ll num = 1;
    FOR(i, N, 1)
    {
        if (A[i] != A[i - 1])
            num++;
    }
    if (num > 2)
        return "No";

    if (num == 1)
    {
        if (N == A[0] + 1 || 2 * A[0] <= N)
            return "Yes";
        return "No";
    }

    if (A[0] + 1 != A[N - 1])
        return "No";

    ll n = 0;
    REP(i, N)
    {
        if (A[0] == A[i])
            n++;
    }
    if (A[0] >= n && 2 * (A[N - 1] - n) <= (N - n))
        return "Yes";
    return "No";
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
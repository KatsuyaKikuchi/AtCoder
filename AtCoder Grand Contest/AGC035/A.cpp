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
    ll n = 1;
    FOR(i, N, 1)
    {
        if (A[i] != A[i - 1])
            n++;
    }
    if (n > 3)
        return "No";
    if (n == 1)
    {
        //! Aが0のみ
        if (A[0] == 0 && A[N - 1] == 0)
            return "Yes";
        else
            return "No";
    }

    if (N % 3 != 0)
        return "No";

    ll x = 0;
    ll f = 1, l = 1;
    FOR(i, N, 1)
    {
        if (A[i] != A[i - 1])
        {
            x = A[i];
            break;
        }
        f++;
    }
    FOR(i, N, 1)
    {
        if (A[N - 1 - i] != A[N - i])
            break;
        l++;
    }

    if (n == 2)
    {
        if (A[0] == 0 && l == 2 * f)
            return "Yes";
        else
            return "No";
    }

    if ((A[0] ^ A[N - 1]) == x && (f == l) && (3LL * f == N))
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
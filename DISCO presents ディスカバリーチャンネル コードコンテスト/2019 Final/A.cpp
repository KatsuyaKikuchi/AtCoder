#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll L[100005];
ll R[100005];

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    REP(i, N - 1)
    {
        if (S[i] == '>')
            L[i + 1] = L[i] + 1;
        if (S[N - 1 - i] == '>')
            R[N - i] = R[N - 1 - i] + 1;
    }

    ll mi = 0;
    REP(i, N)
    {
        if (S[i] == '>')
            continue;
        ll s = L[i] + R[i];
        ll ms = L[mi] + R[mi];
        if (s > ms)
            mi = i;
    }
    S[mi] = '>';
    double ans = 0;
    int k = 0;
    REP(i, N)
    {
        if (S[i] == '-')
        {
            k = 0;
            ans += 1.0;
        }
        else
        {
            ans += 1.0 / (2.0 + k++);
        }
    }
    cout << OF64 << ans << endl;
    return 0;
}
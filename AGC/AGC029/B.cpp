#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
bool U[200005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    ll ans = 0;
    ll max = 1LL << 35;
    for (int i = N - 1; i >= 0; --i)
    {
        if (U[i])
            continue;
        while (A[i] * 2 < max)
            max >>= 1;

        ll ok = i, ng = -1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (A[i] + A[mid] >= max)
            {
                if (A[i] + A[mid] == max && U[mid])
                    ng = mid;
                else
                    ok = mid;
            }
            else
                ng = mid;
        }

        if (ok < i && A[i] + A[ok] == max)
        {
            U[ok] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
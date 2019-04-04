#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
map<ll, bool> M;
int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    ll ans = 0;
    REP(i, N)
    {
        if (M[A[i]])
            continue;
        ans++;
        ll t = A[i];
        while (t <= 1e9)
        {
            M[t] = true;
            t <<= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
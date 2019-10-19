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
ll A[55];

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });

    ll ans = 0;
    vector<ll> v(N, 0);
    while (true)
    {
        ll s = 0;
        REP(i, N)
        {
            //! N-1以下にするのに何回の操作が必要？
            ll a = A[i] + ans - v[i] - (N - 1);
            ll t = (a + N - 1) / N;
            v[i] = t;
            s += t;
        }

        ans = s;
        bool check = true;
        REP(i, N)
        {
            ll b = A[i] + s - v[i] - v[i] * N;
            if (b < 0)
            {
                check = true;
                break;
            }
            if (b >= N)
                check = false;
        }
        if (check)
            break;
    }
    cout << ans << endl;

    return 0;
}
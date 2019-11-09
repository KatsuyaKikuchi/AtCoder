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
    ll T;
    ll N;
    cin >> T >> N;
    memset(A, 0, sizeof(A));
    REP(i, N)
    {
        ll a;
        cin >> a;
        A[a]++;
    }
    ll M;
    cin >> M;
    bool can = true;
    REP(i, M)
    {
        ll b;
        cin >> b;
        bool e = false;
        FOR(t, b + 1, std::max(0LL, b - T))
        {
            if (A[t] > 0)
            {
                A[t]--;
                e = true;
                break;
            }
        }
        can &= e;
    }
    if (can)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
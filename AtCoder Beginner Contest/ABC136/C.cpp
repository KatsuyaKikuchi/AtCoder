#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i];
    }

    bool f = true;
    REP(i, N - 1)
    {
        if (i == 0 || H[i - 1] < H[i])
            H[i]--;
        if (H[i] > H[i + 1])
            f = false;
    }

    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[200005];
ll Y[200005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(Y, Y + N);
    ll L = Y[N / 2 - 1];
    ll R = Y[N / 2];

    REP(i, N)
    {
        if (X[i] <= L)
            cout << R << endl;
        else
            cout << L << endl;
    }
    return 0;
}
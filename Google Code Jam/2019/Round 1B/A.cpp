#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[100005];
ll Y[100005];

int main()
{
    int T;
    cin >> T;
    REP(cs, T)
    {
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        ll P, Q;
        cin >> P >> Q;
        Q++;
        REP(i, P)
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            switch (c)
            {
            case 'N':
                Y[y + 1]++;
                Y[Q]--;
                break;
            case 'S':
                Y[0]++;
                Y[y]--;
                break;
            case 'E':
                X[x + 1]++;
                X[Q]--;
                break;
            case 'W':
                X[0]++;
                X[x]--;
                break;
            default:
                break;
            }
        }
        FOR(i, Q, 1)
        {
            X[i] += X[i - 1];
            Y[i] += Y[i - 1];
        }
        ll mx = 0, my = 0;
        REP(i, Q)
        {
            if (X[i] > X[mx])
                mx = i;
            if (Y[i] > Y[my])
                my = i;
        }
        cout << "Case #" << cs + 1 << ": " << mx << " " << my << endl;
    }
    return 0;
}
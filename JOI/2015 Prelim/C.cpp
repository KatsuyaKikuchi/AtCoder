#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[105];
ll A[105][105];

int main()
{
    ll H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> M[i];
    }

    memset(A, -1, sizeof(A));
    REP(i, H)
    {
        REP(j, W)
        {
            for (int k = j; k >= 0; --k)
            {
                if (M[i][k] == 'c')
                {
                    A[i][j] = j - k;
                    break;
                }
            }
        }
    }
    REP(i, H)
    {
        cout << A[i][0];
        FOR(j, W, 1)
        {
            cout << " " << A[i][j];
        }
        cout << endl;
    }
    return 0;
}
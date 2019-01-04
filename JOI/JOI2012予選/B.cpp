#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int S[205][5];
int T[205];
int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        REP(j, 3)
        {
            cin >> S[i][j];
        }
    }

    REP(k, 3)
    {
        REP(i, N)
        {
            int s = false;
            REP(j, N)
            {
                if (i == j)
                    continue;
                if (S[i][k] == S[j][k])
                    s = true;
            }
            if (s)
                continue;
            T[i] += S[i][k];
        }
    }

    REP(i, N)
    {
        cout << T[i] << endl;
    }
    return 0;
}
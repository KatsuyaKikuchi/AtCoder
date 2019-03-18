#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int H, W;
string A[105];
bool B[105], C[105];

int main()
{
    cin >> H >> W;
    REP(i, H)
    {
        cin >> A[i];
    }

    REP(i, H)
    {
        bool t = true;
        REP(j, W)
        {
            if (A[i][j] == '#')
            {
                t = false;
                break;
            }
        }
        B[i] = t;
    }
    REP(i, W)
    {
        bool t = true;
        REP(j, H)
        {
            if (A[j][i] == '#')
            {
                t = false;
                break;
            }
        }
        C[i] = t;
    }

    REP(h, H)
    {
        REP(w, W)
        {
            if (B[h] || C[w])
                continue;
            cout << A[h][w];
        }
        cout << endl;
    }
    return 0;
}
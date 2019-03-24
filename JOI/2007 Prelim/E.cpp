#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Test
{
    int p[3];
    int r;
};

Test T[1005];
int D[310];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    REP(i, a + b + c)
    {
        D[i] = 2;
    }
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i].p[0] >> T[i].p[1] >> T[i].p[2] >> T[i].r;
        T[i].p[0]--;
        T[i].p[1]--;
        T[i].p[2]--;
    }
    sort(T, T + N, [](Test a, Test b) { return a.r > b.r; });
    REP(i, N)
    {
        if (T[i].r == 1)
        {
            REP(j, 3)
            {
                D[T[i].p[j]] = 1;
            }
            continue;
        }

        int n = 0;
        REP(j, 3)
        {
            if (D[T[i].p[j]] == 1)
                n++;
        }
        if (n == 2)
        {
            REP(j, 3)
            {
                if (D[T[i].p[j]] != 1)
                    D[T[i].p[j]] = 0;
            }
        }
    }

    REP(i, a + b + c)
    {
        cout << D[i] << endl;
    }
    return 0;
}
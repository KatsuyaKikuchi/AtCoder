#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char C[4] = {'U', 'D', 'L', 'R'};
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};

int main()
{
    string S;
    int T;
    cin >> S >> T;
    pll g(0, 0);
    ll num = 0;
    REP(i, S.length())
    {
        if (S[i] == '?')
            num++;
        else
        {
            REP(j, 4)
            {
                if (S[i] == C[j])
                {
                    g.first += x[j];
                    g.second += y[j];
                }
            }
        }
    }

    if (T == 1)
    {
        cout << abs(g.first) + abs(g.second) + num << endl;
    }
    else if (T == 2)
    {
        ll dx = std::min(num, abs(g.first));
        num -= dx;
        g.first = abs(g.first) - dx;
        ll dy = std::min(num, abs(g.second));
        num -= dy;
        g.second = abs(g.second) - dy;
        cout << g.first + g.second + num % 2 << endl;
    }
    return 0;
}
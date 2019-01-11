#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int Y, M, D;
    cin >> Y >> M >> D;
    string a = "Yes";
    if (Y > 2019 || Y < 1988)
        a = "No";
    if (Y == 2019)
    {
        if (M > 4)
        {
            a = "No";
        }
    }
    else if (Y == 1989)
    {
        if (M == 1)
        {
            if (D < 8)
                a = "No";
        }
    }
    cout << a << endl;
    return 0;
}
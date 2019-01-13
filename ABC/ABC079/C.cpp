#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int T[5];
char C[2] = {'+', '-'};

int main()
{
    string S;
    cin >> S;
    REP(i, S.length())
    {
        T[i] = (int)(S[i] - '0');
    }

    for (int i = 0; i < 8; ++i)
    {
        int sum = T[0];
        REP(j, 3)
        {
            sum += (T[j + 1] * pow(-1, (i >> j) & 1));
        }
        if (sum == 7)
        {
            cout << T[0];
            REP(j, 3)
            {
                cout << C[(i >> j) & 1] << T[j + 1];
            }
            cout << "=7" << endl;
            break;
        }
    }
    return 0;
}
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
    string T;
    cin >> T;

    int max = 0;
    {
        //! 偶数を2
        int n = 0;
        REP(i, T.length())
        {
            if (i % 2 == 0 && (T[i] == '2' || T[i] == '?'))
                n++;
            else if (i % 2 == 1 && (T[i] == '5' || T[i] == '?') && n > 0)
                n++;
            else
                n = 0;
            max = std::max(max, n);
        }
    }
    {
        //! 偶数を2
        int n = 0;
        REP(i, T.length())
        {
            if (i % 2 == 1 && (T[i] == '2' || T[i] == '?'))
                n++;
            else if (i % 2 == 0 && (T[i] == '5' || T[i] == '?') && n > 0)
                n++;
            else
                n = 0;
            max = std::max(max, n);
        }
    }
    cout << (max / 2) * 2 << endl;
    return 0;
}
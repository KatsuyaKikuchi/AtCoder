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
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T = "b";
    if (S == T)
    {
        cout << 0 << endl;
        return 0;
    }
    int i = 1;
    while (S.length() > T.length())
    {
        if (i % 3 == 1)
            T = 'a' + T + 'c';
        else if (i % 3 == 2)
            T = 'c' + T + 'a';
        else
            T = 'b' + T + 'b';

        if (S == T)
        {
            cout << i << endl;
            return 0;
        }
        ++i;
    }
    cout << -1 << endl;
    return 0;
}
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
    string S;
    cin >> S;

    int a = (S[0] - '0') * 10 + (S[1] - '0');
    int b = (S[2] - '0') * 10 + (S[3] - '0');

    if (a <= 12 && 0 < a)
    {
        if (0 < b && b <= 12)
        {
            cout << "AMBIGUOUS";
        }
        else
        {
            cout << "MMYY" << endl;
        }
    }
    else
    {
        if (0 < b && b <= 12)
        {
            cout << "YYMM";
        }
        else
        {
            cout << "NA";
        }
    }
    cout << endl;

    return 0;
}
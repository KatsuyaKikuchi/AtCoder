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

    int low = 0, up = N;
    string lowS;
    cout << low << endl;
    cout << flush;
    cin >> lowS;
    while (true)
    {
        if (lowS == "Vacant")
            break;

        ll mid = (low + up) / 2;
        string s;
        cout << mid << endl;
        cout << flush;
        cin >> s;
        if (s == "Vacant")
            break;

        if ((mid - low) % 2 == 0)
        {
            if (lowS == s)
            {
                low = mid;
                lowS = s;
            }
            else
                up = mid;
        }
        else
        {
            if (lowS != s)
            {
                low = mid;
                lowS = s;
            }
            else
                up = mid;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int c[5] = {8, 9, 10, 11, 12};

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    REP(i, 10)
    {
        cout << "?";
        REP(j, N)
        {
            if (5 * i <= j && j < 5 * (i + 1))
                cout << pow(10, j - 5 * i) << " ";
            else
                cout << "0 ";
        }
        cout << endl;
        ll sum;
        cin >> sum;
        while (sum > 0)
        {
            REP(i, 5)
            {
                if ((sum - c[i]) % 10 == 0)
                {
                    if (i % 2 == 1)
                        v.push_back(1);
                    else
                        v.push_back(0);
                    sum = (sum - c[i]) / 10;
                    break;
                }
            }
        }
    }
    cout << "!";
    REP(i, N)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
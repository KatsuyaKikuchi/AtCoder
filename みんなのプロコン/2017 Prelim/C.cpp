#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
string S[100005];
bool U[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, K)
    {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N)
    {
        cin >> S[i];
    }
    if (N == K)
    {
        cout << "" << endl;
        return 0;
    }
    vector<string> v, u;
    sort(A, A + K);
    int index = 0;
    REP(i, N)
    {
        if (index < K && A[index] == i)
        {
            v.push_back(S[i]);
            index++;
        }
        else
        {
            u.push_back(S[i]);
        }
    }

    string s = "";
    REP(n, v[0].length())
    {
        bool e = true;
        REP(i, v.size())
        {
            if (v[i].length() <= n || v[0][n] != v[i][n])
            {
                e = false;
                break;
            }
        }
        if (!e)
            break;
        s.push_back(v[0][n]);
    }
    ll max = 0;
    REP(i, u.size())
    {
        ll m = u[i].size() + 1;
        REP(j, s.size())
        {
            if (u[i].size() <= j || u[i][j] != s[j])
            {
                m = j + 1;
                break;
            }
        }
        max = std::max(max, m);
    }

    if (max > s.length())
        cout << -1 << endl;
    else
    {
        REP(i, max)
        {
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}
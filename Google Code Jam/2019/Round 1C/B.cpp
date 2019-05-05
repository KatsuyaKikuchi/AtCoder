#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;
const int SIZE = 5;

int S[SIZE] = {119, 23, 5, 1, 0};
//int S[SIZE] ={23,5,1,0};
//int S[SIZE] = {5, 1, 0};
string dfs(vector<int> v, int t = 0)
{
    string ret = "";
    int n = 0;
    REP(i, SIZE)
    {
        if (((t >> i) & 1) == 1)
            n++;
    }
    if (n == SIZE - 1)
    {
        REP(i, SIZE)
        {
            if (((t >> i) & 1) == 0)
            {
                ret.push_back('A' + i);
                return ret;
            }
        }
    }
    vector<int> s[SIZE];
    REP(i, v.size())
    {
        cout << v[i] * SIZE + n + 1 << endl;
        char c;
        cin >> c;
        s[c - 'A'].push_back(v[i]);
    }
    REP(i, SIZE)
    {
        if (s[i].size() == S[n + 1] && ((t >> i) & 1) == 0)
        {
            ret.push_back('A' + i);
            t |= (1 << i);
            ret += dfs(s[i], t);
            break;
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    int F;
    cin >> F;
    REP(cs, T)
    {
        vector<int> v;
        REP(i, S[0])
        {
            v.push_back(i);
        }
        string ans = dfs(v);
        cout << ans << endl;

        char a;
        cin >> a;
        if (a == 'N')
            break;
    }
    return 0;
}
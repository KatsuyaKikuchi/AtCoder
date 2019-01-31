#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Map
{
    string R[55];
};
int N, K, H, W, T;
Map M[105];
char C[4] = {'U', 'D', 'L', 'R'};
int y[4] = {0, 0, -1, 1};
int x[4] = {-1, 1, 0, 0};

int simulate(int id, string Com)
{
    pll s(0, 0);
    REP(h, H)
    {
        REP(w, W)
        {
            if (M[id].R[h][w] == '@')
            {
                s = pll(h, w);
                break;
            }
        }
    }

    int score = 0;
    bool U[55][55] = {false};
    U[s.first][s.second] = true;
    REP(i, T)
    {
        int n = 0;
        REP(j, 4)
        {
            if (C[j] == Com[i])
            {
                n = j;
                break;
            }
        }
        int nx = s.first + x[n];
        int ny = s.second + y[n];
        if (M[id].R[nx][ny] == '#')
            continue;
        if (M[id].R[nx][ny] == 'x')
            break;
        if (M[id].R[nx][ny] == 'o')
        {
            if (!U[nx][ny])
            {
                U[nx][ny] = true;
                score++;
            }
        }
        s = pll(nx, ny);
    }
    return score;
}

int main()
{
    cin >> N >> K >> H >> W >> T;
    REP(i, N)
    {
        REP(h, H)
        {
            cin >> M[i].R[h];
        }
    }

    string maxCom = "";
    vector<int> maxMap(8);
    ll maxScore = 0;
    REP(k, 4000)
    {
        string Com = "";
        REP(i, T)
        {
            Com += C[rand() % 4];
        }
        vector<pll> m(N);
        REP(i, N)
        {
            int s = simulate(i, Com);
            m[i] = pll(i, s);
        }
        sort(m.begin(), m.end(), [](pll a, pll b) { return a.second > b.second; });
        vector<int> map(8);
        ll score = 0;
        REP(i, 8)
        {
            map[i] = m[i].first;
            score += m[i].second;
        }
        if (score > maxScore)
        {
            maxScore = score;
            maxMap = map;
            maxCom = Com;
        }
    }

    REP(i, 8)
    {
        cout << maxMap[i] << " ";
    }
    cout << endl;
    cout << maxCom << endl;
    return 0;
}
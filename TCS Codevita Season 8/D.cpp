#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<ll> input;
    ll x, total = 0;
    while(cin >> x){
        input.pb(x);
        total += x;
    }

    ll n = input.size();
    bool dp[n+1][total+1];
    for(ll i = 0; i <= n; i++) dp[i][0] = true;
    for(ll j = 1; j <= total; j++) dp[0][j] = false;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= total; j++){
            dp[i][j] = dp[i-1][j];
            if(j-input[i-1] >= 0) dp[i][j] |= dp[i-1][j-input[i-1]];
        }
    }

    ll answer = INT_MAX;
    for(ll j = 0; j <= total; j++){
        if(dp[n][j]){
            // cout << j << " " << total-j << endl;
            answer = min(answer, max(j, total-j));
        }
    }
    cout << answer << endl;
}

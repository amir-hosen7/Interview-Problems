#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

class Job {
public:
	ll id, deadline, profit;
};

bool cmp(Job &a, Job &b) {
	return a.profit > b.profit;
}

int main() {
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    vector<Job> jobs = {
    	{1, 2, 20}, {2, 1, 10}, {3, 2, 30}, {4, 2, 16}, {5, 2, 38} //id, deadline, profit
    };
    sort(jobs.begin(), jobs.end(), cmp);  //decreasing order by profit
    vector<ll> schedule;
    unordered_map<ll, bool> slot;
    ll siz = jobs.size(), maxProfit = 0;
    for (ll i = 0; i < siz; i++) {
    	for (ll j = min(siz, jobs[i].deadline); j >= 1; j--) {
    		if (slot[j] == false) {
    			slot[j] = true;
    			maxProfit += jobs[i].profit;
    			schedule.push_back(jobs[i].id);
    			break;
    		}
    	}
    }
    cout << "profit = " << maxProfit << "\n";
    cout << "Total completed job = " << schedule.size() << "\n";
    cout << "Sequence -> ";
    for (auto i : schedule) {
    	cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}




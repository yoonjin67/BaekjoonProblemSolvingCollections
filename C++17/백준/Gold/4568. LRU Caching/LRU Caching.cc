#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cache_len = 1;
    int simulation_num = 0;
    while(true) {
        string task;
        cin >> cache_len;
        if(cache_len == 0) break;
        simulation_num++;
        cout << "Simulation " << simulation_num << '\n';
        cin >> task;
        vector<char> cache = vector<char>();
        for(int i = 0; i < task.length(); i++) {
            if(task[i] == '!') {
                for(auto c:cache) {
                    cout << c;
                }
                cout << '\n';
                continue;
            }
            for(int j = 0; j < cache.size(); j++) {
                if(cache[j] == task[i]) {
                    cache.erase(cache.begin()+j);
                    break;
                }
            }
            if(cache.size() >= cache_len) cache.erase(cache.begin());
            cache.push_back(task[i]);
        }
    }
    return 0;
}
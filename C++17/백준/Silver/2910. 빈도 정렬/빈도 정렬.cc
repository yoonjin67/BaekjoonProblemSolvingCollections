#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,pair<int,int>> piii;
bool comp(piii a, piii b) {
    if(a.first!=b.first) return b.first<a.first;
    else return a.second.second<b.second.second;

}

int main() {
    int n, c;
    cin >> n >> c;
    piii arr[n];
    fill(arr,arr+n,make_pair(0,make_pair(0,0)));
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num--;
        int found = false;
        for(int j = 0; j < i; j++) {
            if(arr[j].second.first == num+1) {
                arr[j].first++;
                found = true;
                break;
            }
        }
        if(!found) {
            arr[i].first++;
            arr[i].second.first = num+1;
            arr[i].second.second = i;
        }
    }
    sort(arr,arr+n,comp);
    for(int i = 0; i < n; i++) {
        if(arr[i].first) {
            for(int j = 0; j < arr[i].first; j++) {
                cout << arr[i].second.first;
                cout << ' ';
            }
        }
    }
    return 0;
}
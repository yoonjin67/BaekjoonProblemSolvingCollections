#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int celebLen;
    cin >> celebLen;
    vector<pair<int,int>> v;
    int popularity = 0;
    for(int i = 0; i < celebLen; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    for(auto itm:v) {
        if(abs(itm.first - popularity) <= itm.second) popularity++;
        else continue;
    }
    cout << popularity;
   return 0;
}
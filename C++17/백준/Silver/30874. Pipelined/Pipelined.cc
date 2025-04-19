#include<iostream>
#include<vector>
#include<algorithm>

/*
    풀이는 간단하지만 어려운 문제! 파이프라이닝에서 각각의 프로세스가 겹치는 경우는 1번인데,
    첫번째로 들어간 것을 제외한 모든 프로세스는 파이프라인에 들어가지 못하고 1초 대기.
    가장 오래 걸리는 것부터 가장 짧은 것까지 동시처리, 1번 걸릴 때에 하나하나 대기하는 시간은
    전체 개수 -1
    그러므로
    제일 길게 걸리는 프로세스 + 프로세스 개수 -1
*/



using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    vector<int> v;
    for(auto i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    cout << v.back()+v.size()-1;
    
   return 0;
}
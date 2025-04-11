#include<iostream>
#include<climits>
#include<stack>
using namespace std;
int main() {
        stack<pair<int,int>> st;
        int n;
        cin >> n;
        int arr[n];
        st.push(make_pair(INT_MAX,0));
        for(int i = 0; i < n; i++) {
                cin >> arr[i];
        }
        for(int i = 0; i < n; i++) {
                while(st.size()) {
                        if(arr[i]<st.top().first) {
                                cout << st.top().second;
                                if(i<n) cout << " ";
                                st.push(make_pair(arr[i],i+1));
                                break; //지금까지 기록된 것들 중에 도달하는 탑이 있으면
                                //혹은 앞서 넣은 끝점에 도달하면 그 점을 출력하고, 현재 점을 다음 점 을 위해 넣고 루프 종료
                        } else if(st.top().first<arr[i]) {
                                if(st.size()) {
                                        st.pop(); //나올때까지 다음 기록으로 넘어감
                                }
                        }
                }
        }
        while(st.size()) st.pop(); //혹시 모르니까 마지막은 정리해두자
        return 0;
}
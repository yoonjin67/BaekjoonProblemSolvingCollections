#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	queue<int> q;
	string cmd;
	int repeat;
	cin >> repeat;
	for(int i=0;i<repeat;i++) {
		cin >> cmd;
		if(!cmd.compare("push")) {
			int item;
			cin >> item;
			q.push(item);
		} else if(!cmd.compare("pop")) {
			if(q.size()) {
				cout << q.front() << endl;
				q.pop();
			} else {
				cout << "-1" << endl;
			}
		} else if(!cmd.compare("size")) {
			cout << q.size() << endl;
		} else if(!cmd.compare("empty")) {
			cout << q.empty() << endl;
		} else if(!cmd.compare("front")) {
			if(q.empty()) {
				cout << "-1" << endl;
			} else {
				cout << q.front() << endl;
			}
		} else if(!cmd.compare("back")) {
			if(q.empty()) {
				cout << "-1" << endl;
			} else {
				cout << q.back() << endl;
			}
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}

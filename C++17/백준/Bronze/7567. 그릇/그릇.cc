#include<iostream>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	char prev = '\0';
	int i;
	int len = 0;
	for(int i=0;i<s.length();i++) {
		static char x;
		x = s[i];
		if(x==')' and prev != ')') {
			len+=2;	
		} else if(x=='(' and prev != '(') {
			len+=2;
		} else {
			len+=1;
		}
		prev=x;
	}
	len*=5;
	cout << len;
	return 0;
}
		

#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int n,gabg;
    cin >> n;
    for(auto i = 0; i < n*n; i++) {
        cin >> gabg;
    }
    for(int i = 0; i < n ; i++) {
        for(int j = 0 ; j < n; j++) {
            cout << i+1;
            if(j != n-1) cout << " ";
        }
        cout << '\n';
    }
   return 0;
}
#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;
class errorHandler {
        public:
                string s;
                bool is_java();
                bool is_cpp();
                void to_cpp();
                void to_java();
                void check_unavail();
                void print_err();
                void check_conflict();
                void success();
};


bool errorHandler::is_java() {
        for(auto c:s) {
                if(isupper(c)) return true;
        }
        return false;
}
bool errorHandler::is_cpp() {
        for(auto c:s) {
                if(c=='_') return true;
        }
        return false;
}
void errorHandler::print_err() {
        cout << "Error!";
        exit(0);
}
void errorHandler::check_unavail() {
        check_conflict();
        if(s[0]=='_') print_err();
        if(isupper(s[0])) print_err();
        if(s[s.length()-1]=='_') print_err();
}

void errorHandler::success() {
        exit(0);
}

void errorHandler::to_cpp() {
        for(auto c:s) {
                if(isupper(c)) {
                        cout << "_";
                }
                printf("%c",tolower(c));
        }
        success();
}
void errorHandler::to_java() {
        string tmp;
        int i = 0;
        istringstream s_stream(s);
        while(getline(s_stream,tmp,'_')) {
                if(i>0) tmp[0] = toupper(tmp[0]);
                        cout << tmp;
                i++;
        }
        success();
}

void errorHandler::check_conflict() {
        if(is_cpp() and is_java()) print_err();
        for(int i = 0; i < s.length()-1; i++) {
                if(s[i] == s[i+1] and s[i] == '_') print_err();
        }
}


int main() {
        errorHandler err;
        cin >> err.s;
        err.check_unavail();
        if(err.is_java()) {
                err.to_cpp();
        } else {
                err.to_java();
        }
        return 0;

}
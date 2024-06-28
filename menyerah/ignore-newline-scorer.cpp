#include <bits/stdc++.h>
using namespace std;

int wa() {
    cout << "WA" << endl;
    return 0;
}

int ac() {
    cout << "AC" << endl;
    return 0;
}

int main(int argc, char* argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);
    ifstream con_out(argv[3]);

    string tc_ans;
    tc_out >> tc_ans;

    string con_ans;
    con_out >> con_ans;

    return tc_ans == con_ans ? ac() : wa();
}

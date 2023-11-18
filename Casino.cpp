#include <iostream>
#include <cassert>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 2) {
        cout << "Please only include starting money in declaration!";
        return -1;
    }
    int const startingMoney = stoi(argv[1]);
    
    cout << "Enter 1 for Blackjack\n";
    cout << "Select which game you want to play: ";
    int gamenum = -1;
    cin >> gamenum;
    return 0;
};

// ./Casino.exe 10000
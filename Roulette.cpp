#include <iostream>
#include <string>
#include <map>
using namespace std;

class Roulette {
    public: 
        Roulette();
        bool play(int &money);
    private:
        string bet;
        std::map<string, string> my_map;
        
};

Roulette::Roulette() {
    my_map = {
        {"00", "g"},
        {"1","r"},
        {"2","b"},
        {"3","r"},
        {"4","b"},
        {"5","r"},
        {"6","b"},
        {"7","r"},
        {"8","b"},
        {"9","r"},
        {"10","b"},
        {"11","b"},
        {"12","r"},
        {"13","b"},
        {"14","r"},
        {"15","b"},
        {"16","r"},
        {"17","b"},
        {"18","r"},
        {"19","r"},
        {"20","b"},
        {"21","r"},
        {"22","b"},
        {"23","r"},
        {"24","b"},
        {"25","r"},
        {"26","b"},
        {"27","r"},
        {"28","b"},
        {"29","b"},
        {"30","r"},
        {"31","b"},
        {"32","r"},
        {"33","b"},
        {"34","r"},
        {"35","b"},
        {"36","r"},
        {"0","g"}
    };
}

bool Roulette::play(int &money) {
    cout << "Place your bet: ";
            cin >> bet;
            cout << endl;
    int num = rand() % 38;
    string number;
    if(num == 37) {
        number = "0";
    } else if(num == 38) {
        number = "00";
    } else {
        number = to_string(num);
    }
    string color = my_map[number];

            if (bet == "r/b") {
            // red or black
            // double the money
            } else if (bet == "o/e") {
            // odd or even
            // double the money
            } else if (bet == "h/l") {
            // high or low
            // - number 1 - 18
            // - number 19 - 36
            // double the money
            } else {
                cout << "This is not a valid type of bet!" << endl;
                cout << "Try again" << endl;
                return false;
            }

}

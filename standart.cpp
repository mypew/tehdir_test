#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>

#define ll long long int

using namespace std;

//Костыль, чтобы определять, что хранит в себе строка(число или не число)
struct int_string {
    string str;
    ll index;
    bool type; // false - число, true - строка
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string input_string;
    vector<int_string> vec;
    vector<string> vec_standart;

    getline(cin, input_string);

    ll index = 0;
    while (input_string.find(" ", index) != string::npos) {
        if (input_string[index] >= 48 && input_string[index] <= 57) vec.push_back({ input_string.substr(index,input_string.find(" ",index) - index),vec.size(),false });
        else vec.push_back({ input_string.substr(index,input_string.find(" ",index) - index),vec.size(),true });
        vec_standart.push_back({input_string.substr(index,input_string.find(" ",index) - index)});

        index = input_string.find(" ", index) + 1;
    }
    if (index < input_string.size()) {
        if (input_string[index] >= 48 && input_string[index] <= 57) vec.push_back({ input_string.substr(index,input_string.size() - index),vec.size(),false });
        else vec.push_back({ input_string.substr(index,input_string.size() - index),vec.size(),true });
        vec_standart.push_back({ input_string.substr(index,input_string.find(" ",index) - index) });
    }

    sort(vec.begin(), vec.end(), [](const int_string& p1, const int_string& p2) {
        int result = 0;
        if (p1.type > p2.type || p1.str < p2.str && p1.type == p2.type) {
            result = 1;
        }
        return result;
        });

    for (int i = 0; i < vec.size()/2; i++) {
        cout << i + 1 << " Step: ";
        for (int j = i; j >= 0; j--) cout << vec[j].str << " ";

        for (int j = 0; j < vec_standart.size(); j++) {
            if (vec[i].str == vec_standart[j] || vec[vec.size()-1-i].str == vec_standart[j]) vec_standart[j] = "DROP TABLE Users;";
            if (vec_standart[j] != "DROP TABLE Users;") cout << vec_standart[j] << " ";
        }

        for (int j = vec.size() - 1; j >= vec.size() - 1 - i; j--) cout << vec[j].str << " ";
        cout << endl;
    }
}
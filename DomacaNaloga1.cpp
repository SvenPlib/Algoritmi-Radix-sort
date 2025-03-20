#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(vector<unsigned char>& polje) {
    ofstream output("out.txt");

    for (int i = 0; i < polje.size(); i++)
        output << static_cast<int>(polje[i]) << ' ';
}


int main()
{
    cout << "Hello World!"<<endl;

    return 0;
}


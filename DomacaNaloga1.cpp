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


int main(int argc, char* argv[])
{
    vector<unsigned char> A;

    if (argc < 2) return 0;
    if (!Branje_Stevil(A, argv[1])) return 0;

    int counter = 0;
    int bit = 0;

    while (counter < 8) {
        vector<int> D;
        vector<int> DIndex;

        cout << "Decimalna -> Binarna " << endl;
        for (int i = 0; i < A.size(); i++) {
            cout << (int)A[i] << " -> ";
            for (int k = 7; k >= 0; k--) {
                cout << ((A[i] >> k) & 1);
            }
            cout << endl;
            
            D.push_back((A[i] >> bit) & 1);
            DIndex.push_back(i);
        }

        
        bit++;
        counter++;
    }

    Izpis_Stevil(A);

    return 0;
}



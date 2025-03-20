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

int getMinValue(vector<int> A) {
    int minVal = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] < minVal)
        {
            minVal = A[i];
        }
    }
    return minVal;
}

int getMaxValue(vector<int> A) {
    int maxVal = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > maxVal)
        {
            maxVal = A[i];
        }
    }
    return maxVal;
}

void countingSort(vector<int>& A, vector<int>& Index) {
    int minVal = getMinValue(A);

    for (int i = 0; i < A.size(); i++)
    {
        A[i] = A[i] - minVal;
    }

    int maxVal = getMaxValue(A);
    vector<int> C(maxVal + 1, 0);

    for (int i = 0; i < A.size(); i++)
    {
        C[A[i]]++;
    }

    for (int i = 1; i < C.size(); i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    vector<int> B(A.size());
    vector<int> IndexD(A.size());

    for (int i = A.size() - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        IndexD[C[A[i]] - 1] = Index[i];
        C[A[i]] = C[A[i]] - 1;
    }

    for (int i = 0; i < B.size(); i++)
    {
        B[i] = B[i] + minVal;
    }

    for (int i = 0; i < B.size(); i++)
    {
        A[i] = B[i];
        Index[i] = IndexD[i];
    }
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

        cout << endl << "Izbrani biti iz vsake stevilke (bit " << bit << "):" << endl;
        for (int i = 0; i < D.size(); i++) {
            cout << "Index:" << DIndex[i] << " " << D[i] << " ";
        }

        cout << endl;
        
        countingSort(D, DIndex);

        cout << endl << "Izbrani biti iz vsake stevilke (bit " << bit << "):" << endl;
        for (int i = 0; i < D.size(); i++) {

            cout << "Index:" << DIndex[i] << " " << D[i] << " ";
        }

        cout << endl;

        vector<unsigned char> A_sorted(A.size());
        for (int i = 0; i < A.size(); i++) {
            A_sorted[i] = A[DIndex[i]];
        }

        A = A_sorted;

        cout << endl << "Urejeno A po bitu " << bit + 1<< ":" << endl;
        for (int i = 0; i < A.size(); i++) {
            cout << (int)A[i] << " ";
        }

        cout << endl << endl;
        
        bit++;
        counter++;
    }

    Izpis_Stevil(A);

    return 0;
}



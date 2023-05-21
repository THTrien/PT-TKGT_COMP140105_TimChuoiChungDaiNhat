#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dodaichuoichung(const string& a, const string& b) {
    int n = a.length();
    int m = b.length();
    int L[1001][1001] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    return L[n][m];
}

string chuoichung(const string& a, const string& b) {
    int n = a.length();
    int m = b.length();
    int L[1001][1001] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    string chuoiChung = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            chuoiChung = a[i - 1] + chuoiChung;
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return chuoiChung;
}

int main() {
    string a, b;
    
    
    getline(cin, a);

    
    getline(cin, b);

    int dodaichuoiChung = dodaichuoichung(a, b);
    string chuoiChung = chuoichung(a, b);

    cout << "Do chuoi chung: " << dodaichuoiChung << endl;
    cout << "Chuoi chung: " << chuoiChung << endl;

    return 0;
}



#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int _m, _n;
    vector<vector<int>> _data;

public:
    Matrix(int m, int n) : _m(m), _n(n) {
        _data.reserve(m);
        for (int i = 0; i < m; i++) {
            _data[i].reserve(n);
        }
    }

    void emplace(int x, int y, int value) {
        _data[x][y] = value;
    }

    Matrix operator+(const Matrix& other) {
        Matrix c(_m, _n);

        for(int i = 0; i < _m; ++i) {
            for (int j = 0; j < _n; ++j) {
                int sum = _data[i][j] + other._data[i][j];
                c.emplace(i, j, sum);
            }
        }

        return c;
    }

    friend ostream& operator<<(ostream& out, const Matrix& c) {
        for (int i = 0; i < c._m; i++) {
            for (int j = 0; j < c._n; j++) {
                cout << c._data[i][j] << " ";
            }
            cout << endl;
        }

        return out;
    }
};

int main() {
    int m, n, v;
    cin >> m >> n;

    Matrix a(m, n);
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v;
            a.emplace(i, j, v);
        }
    }

    Matrix b(m, n);
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v;
            b.emplace(i, j, v);
        }
    }

    Matrix c = a + b;
    cout << c;

    return 0;
}
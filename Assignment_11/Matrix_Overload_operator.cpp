#include<iostream>
using namespace std;

class Matrix {
public:
    int mat[3][3];

    void getMatrix() {
        cout << "Enter elements of the matrix(3x3):" << endl;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> mat[i][j];
    }

    Matrix operator + (Matrix const &obj) {
        Matrix res;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                res.mat[i][j] = mat[i][j] + obj.mat[i][j];
        return res;
    }

    void display() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix OBJ1, OBJ2, OBJ3;

    cout << "Enter matrix for OBJ1:" << endl;
    OBJ1.getMatrix();

    cout << "Enter matrix for OBJ2:" << endl;
    OBJ2.getMatrix();

    //displaying the entered matrices
    cout << "The entered matrices are:" << endl;

    OBJ1.display();
    cout << endl;

    OBJ2.display();
    cout << endl;

    OBJ3 = OBJ1 + OBJ2;

    cout << "The sum of the matrices is:" << endl;
    OBJ3.display();

    return 0;
}

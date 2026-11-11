
#include <iostream>
#include <iomanip>
using namespace std;

// Створення матриці
int** makeMatrix(int rows, int cols) {
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];
    return a;
}

// Введення матриці
void inputMatrix(int** a, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
}

// Виведення матриці
void printMatrix(int** a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
}

// Кількість стовпців з нулями
int countColumnsWithZero(int** a, int rows, int cols) {
    int count = 0;

    for (int j = 0; j < cols; j++) {
        bool hasZero = false;

        for (int i = 0; i < rows; i++) {
            if (a[i][j] == 0)
                hasZero = true;
        }

        if (hasZero)
            count++;
    }
    return count;
}

// Найдовша серія однакових чисел у рядку
int longestRun(int* a, int n) {
    int best = 1;
    int current = 1;

    for (int j = 1; j < n; j++) {
        if (a[j] == a[j - 1])
            current++;
        else
            current = 1;

        if (current > best)
            best = current;
    }
    return best;
}

// Пошук рядка з найдовшою серією
int findRow(int** a, int rows, int cols) {
    int row = 0;
    int maximum = longestRun(a[0], cols);

    for (int i = 1; i < rows; i++) {
        int length = longestRun(a[i], cols);

        if (length > maximum) {
            maximum = length;
            row = i;
        }
    }
    return row;
}

int main() {
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    if (!cin || rows < 1 || cols < 1 ||
        rows > 40 || cols > 40)
        return 1;

    int** a = makeMatrix(rows, cols);

    cout << "Enter matrix elements:\n";
    inputMatrix(a, rows, cols);

    if (!cin) {
        for (int i = 0; i < rows; i++)
            delete[] a[i];
        delete[] a;
        return 1;
    }

    cout << "Matrix:\n";
    printMatrix(a, rows, cols);

    cout << "Columns with zero = "
        << countColumnsWithZero(a, rows, cols) << endl;

    int row = findRow(a, rows, cols);

    cout << "Row number = " << row + 1 << endl;
    cout << "Longest run = "
        << longestRun(a[row], cols) << endl;

    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

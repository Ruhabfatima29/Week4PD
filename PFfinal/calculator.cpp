#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void matrixAddition(int A[][3], int B[][3], int C[][3], int rows, int cols);
void matrixSubtraction(int A[][3], int B[][3], int C[][3], int rows, int cols);
void scalarMultiplication(int A[][3], int value, int rows, int cols);
void matrixMultiplication(int A[][3], int B[][3], int C[][3], int rows1, int cols1, int rows2, int cols2);
bool isIdentity(int A[][3], int rows, int cols);
void matrixTranspose(int A[][3], int B[][3], int rows, int cols);
bool isDiagonal(int matrix[][3], int size);
bool isSymmetric(int matrix[][3], int size);
string printMenu();
main()
{
    string choice;
    choice = "0";
    int size = 3;
    int matrixA[3][3] ={
                       {4,9,7},
                       {3,7,2},
                       {1,3,9}
    };
    string input1;
    string input2;
    int matrixB[3][3] = {
                       {5,2,7},
                       {3,7,0},
                       {1,3,9}
    };
    int matrixC[size][3];
    while (choice != "9")
    {
        system("cls");
        choice = printMenu();
        if (choice == "1")
        {
            cout << ">> print MatrixA: " <<endl << endl;
            for (int idx = 0; idx < 3; idx++)
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << matrixA[idx][i] << "\t" ;
                }
                cout << endl;
            }
            cout << endl;
            cout << ">> print MatrixB: "<<endl << endl;
            for (int idx = 0; idx < 3; idx++)
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << matrixB[idx][i] << "\t";
                }
                cout << endl;
            }
            cout << endl;
            matrixAddition(matrixA, matrixB, matrixC, 3, 3);
            cout << ">> Sum of Matrices is: " << endl;
            for (int idx = 0; idx < 3; idx++)
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << matrixC[idx][i] << "\t";
                }
                cout << endl;
            }
        }
        if (choice == "8")
        {
            bool check;
            check = isSymmetric(matrixA, 3);
            cout << "You entered matrixA: " << endl;
            for (int idx = 0; idx < 3; idx++)
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << matrixA[idx][i] << "\t";
                }
                cout << endl;
            }
            if(check)
            {
                cout << "Matrix is symmetric"<< endl;
            }
            else
            cout << "Matrix is not symmetric" << endl;
        }
        getch();
    }
}
void matrixAddition(int A[][3], int B[][3], int C[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
string printMenu()
{
    string option;
    cout << "*************************************" << endl;
    cout << "         MATRIX  CALCULATOR" << endl;
    cout << "*************************************" << endl;
    cout << "  1. Add Matrices: " << endl;
    cout << "  2. Subtract Matrices: " << endl;
    cout << "  3. Multipy Matrices: " << endl;
    cout << "  4. Scalar Multiplication: " << endl;
    cout << "  5. Matrix Transpose: " << endl;
    cout << "  6. Check IsIdentity Matrix: " << endl;
    cout << "  7. Check IsDaigonal Matrix: " << endl;
    cout << "  8. Check IsSymmetric Matrix: " << endl;
    cout << "  9. Exit: " << endl;
    cout << "Enter your option: ";
    cin >> option;
    return option;
}
void matrixSubtraction(int A[][3], int B[][3], int C[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void matrixMultiplication(int A[][3], int B[][3], int C[][3], int rows1, int cols1, int rows2, int cols2)
{
    if (cols1 != rows2)
    {
        cout << "Error: Number of columns in matrix A must be equal to number of rows in matrix B." << endl;
        return;
    }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void scalarMultiplication(int A[][3], int value, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            A[i][j] *= value;
        }
    }
}
bool isIdentity(int A[][3], int rows, int cols)
{
    if (rows != cols)
    {
        return false;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                if (A[i][j] != 1)
                {
                    return false;
                }
            }
            else
            {
                if (A[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void matrixTranspose(int A[][3], int B[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            B[j][i] = A[i][j];
        }
    }
}
bool isDiagonal(int matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSymmetric(int matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
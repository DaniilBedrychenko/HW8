#include <iostream>
using namespace std;

void swapEvenOddIndices(int* arr, int size) {
    for (int* ptr = arr; ptr < arr + size - 1; ptr += 2) {
        int temp = *ptr;
        *ptr = *(ptr + 1);
        *(ptr + 1) = temp;
    }
}

void mergeSortedArrays(int* A, int n, int* B, int m, int* C) {
    int* ptrA = A;
    int* ptrB = B;
    int* ptrC = C;
    
    while (ptrA < A + n && ptrB < B + m) {
        if (*ptrA <= *ptrB) {
            *ptrC = *ptrA;
            ptrA++;
        } else {
            *ptrC = *ptrB;
            ptrB++;
        }
        ptrC++;
    }
    
    while (ptrA < A + n) {
        *ptrC = *ptrA;
        ptrA++;
        ptrC++;
    }
    
    while (ptrB < B + m) {
        *ptrC = *ptrB;
        ptrB++;
        ptrC++;
    }
}

void combineArrays(int* A, int n, int* B, int m, int* C, int& sizeC) {
    int* ptrC = C;
    
    for (int* ptrA = A; ptrA < A + n; ptrA++) {
        *ptrC = *ptrA;
        ptrC++;
    }
    for (int* ptrB = B; ptrB < B + m; ptrB++) {
        *ptrC = *ptrB;
        ptrC++;
    }
    sizeC = (ptrC - C);
}

void commonElements(int* A, int n, int* B, int m, int* C, int& sizeC) {
    int* ptrC = C;
    for (int* ptrA = A; ptrA < A + n; ptrA++) {
        for (int* ptrB = B; ptrB < B + m; ptrB++) {
            if (*ptrA == *ptrB) {
                *ptrC = *ptrA;
                ptrC++;
            }
        }
    }
    sizeC = (ptrC - C);
}

void uniqueToA(int* A, int n, int* B, int m, int* C, int& sizeC) {
    int* ptrC = C;
    for (int* ptrA = A; ptrA < A + n; ptrA++) {
        bool found = false;
        for (int* ptrB = B; ptrB < B + m; ptrB++) {
            if (*ptrA == *ptrB) {
                found = true;
                break;
            }
        }
        if (!found) {
            *ptrC = *ptrA;
            ptrC++;
        }
    }
    sizeC = (ptrC - C);
}

void uniqueToB(int* A, int n, int* B, int m, int* C, int& sizeC) {
    int* ptrC = C;
    for (int* ptrB = B; ptrB < B + m; ptrB++) {
        bool found = false;
        for (int* ptrA = A; ptrA < A + n; ptrA++) {
            if (*ptrB == *ptrA) {
                found = true;
                break;
            }
        }
        if (!found) {
            *ptrC = *ptrB;
            ptrC++;
        }
    }
    sizeC = (ptrC - C);
}

void nonCommonElements(int* A, int n, int* B, int m, int* C, int& sizeC) {
    int tempC[100];
    int tempSizeC;
    
    uniqueToA(A, n, B, m, tempC, tempSizeC);
    for (int* ptr = tempC; ptr < tempC + tempSizeC; ptr++) {
        *C = *ptr;
        C++;
    }
    
    uniqueToB(A, n, B, m, tempC, tempSizeC);
    for (int* ptr = tempC; ptr < tempC + tempSizeC; ptr++) {
        *C = *ptr;
        C++;
    }
    sizeC = (C - (C - tempSizeC * 2));
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int n = 5;
    int B[] = {2, 4, 5, 6, 8};
    int m = 5;
    
    cout << "Task 1: Swap even and odd indices\n";
    cout << "Original array A: ";
    for (int* ptr = A; ptr < A + n; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    swapEvenOddIndices(A, n);
    cout << "After swapping: ";
    for (int* ptr = A; ptr < A + n; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    int C[100];
    int sizeC;
    
    cout << "\nTask 2: Merge sorted arrays\n";
    mergeSortedArrays(A, n, B, m, C);
    cout << "Merged array C: ";
    for (int* ptr = C; ptr < C + n + m; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    cout << "\nTask 3.1: Combine all elements\n";
    combineArrays(A, n, B, m, C, sizeC);
    cout << "Combined array: ";
    for (int* ptr = C; ptr < C + sizeC; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    cout << "\nTask 3.2: Common elements\n";
    commonElements(A, n, B, m, C, sizeC);
    cout << "Common elements: ";
    for (int* ptr = C; ptr < C + sizeC; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    cout << "\nTask 3.3: Elements unique to A\n";
    uniqueToA(A, n, B, m, C, sizeC);
    cout << "Unique to A: ";
    for (int* ptr = C; ptr < C + sizeC; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    cout << "\nTask 3.4: Elements unique to B\n";
    uniqueToB(A, n, B, m, C, sizeC);
    cout << "Unique to B: ";
    for (int* ptr = C; ptr < C + sizeC; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    cout << "\nTask 3.5: Non-common elements\n";
    nonCommonElements(A, n, B, m, C, sizeC);
    cout << "Non-common elements: ";
    for (int* ptr = C; ptr < C + sizeC; ptr++)
        cout << *ptr << " ";
    cout << endl;
    
    return 0;
}

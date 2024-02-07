#include <iostream>
using namespace std;
const int CEO = 1;
const int CTO = 2;
const int CFO = 3;
const int VP = 4;
const int MGR = 5;
const int EMP = 6;


void insertionSort(int *array, int size) {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printDesignation(int designation) {
    switch (designation) {
        case CEO:
             cout << "CEO (Chief Executive Officer)";
            break;
        case CTO:
             cout << "CTO (Chief Technology Officer)";
            break;
        case CFO:
             cout << "CFO (Chief Financial Officer)";
            break;
        case VP:
             cout << "VP (Vice President)";
            break;
        case MGR:
             cout << "Manager";
            break;
        case EMP:
             cout << "Employee";
            break;
        default:
             cout << "Unknown Designation";
    }
}

int main() {
    int desks[] = {EMP ,CFO, MGR, EMP, VP, CTO, MGR, CEO};
    int numDesks = sizeof(desks) / sizeof(desks[0]);

     cout << "Before sorting:\n";
    for (int i = 0; i < numDesks; ++i) {
        printDesignation(desks[i]);
         cout << " ";
    }
     cout <<  endl;

    insertionSort(desks, numDesks);

     cout << "\nAfter sorting:\n";
    for (int i = 0; i < numDesks; ++i) {
        printDesignation(desks[i]);
         cout << " ";
    }
     cout <<  endl;

    return 0;
}


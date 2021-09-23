#include <iostream>
using namespace std;

template<class myT>
class SorthingAlgorithm {
    public:
    
    static void bubbleSort(myT *Arr ,const unsigned int size , bool (*passFunc)(myT , myT)) {
        bool sorting;

        do {
            sorting = false;
            for (unsigned int i = 0 ; i < size - 1 ; i++) {
                if (passFunc(Arr[i] , Arr[i+1])){
                    swap(Arr[i] , Arr[i+1]);
                    sorting = true;
                }
            }
        } while(sorting);
    }

    static void selectionSort(myT *Arr , const unsigned int size , bool (*passFunc)(myT , myT)) {
        myT selectedElementIndex;
        for (unsigned int sortSpot = 0 ; sortSpot < size - 1; sortSpot++){
            selectedElementIndex = sortSpot;
            for (unsigned int i = sortSpot + 1 ; i < size ; i++) {
                if (passFunc(Arr[selectedElementIndex] , Arr[i]))
                    selectedElementIndex = i;
            }

            if (sortSpot != selectedElementIndex)
                swap(Arr[sortSpot] , Arr[selectedElementIndex]);
        }
    }

    static void insertionSort(myT *Arr , const unsigned int size , bool (*passFunc)(myT , myT)) {
        for (unsigned int sortSpot = 1 ; sortSpot < size ; sortSpot++)
            for (unsigned int i = sortSpot ; i > 0 ; i--)
                if (passFunc(Arr[i-1] , Arr[i]))
                    swap(Arr[i] , Arr[i-1]);
                else
                    break;
    }

};

template<class myT>
bool LowToHigh(myT CurValue , myT NextValue) {
    return CurValue > NextValue;
}


template<class myT>
bool HighToLow(myT CurValue , myT NextValue) {
    return CurValue < NextValue;
}

template<class myT>
void printArr(myT *Arr , const unsigned int size) {
    for (unsigned int i = 0 ; i < size; i++) {
        cout << Arr[i] << ' ';
    }

    cout << endl;
}


int main(int argc, char** argv) {
    try {
        int Arr[] = {1,5,2,3};

        SorthingAlgorithm<int>::insertionSort(Arr , 4 , LowToHigh<int>);
        printArr<int>(Arr , 4);
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}


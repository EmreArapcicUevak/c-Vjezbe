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
        int Arr[] = {6 , 4 , 3 , 1};

        SorthingAlgorithm<int>::bubbleSort(Arr , 4 , HighToLow<int>);

        printArr<int>(Arr , 4);
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}


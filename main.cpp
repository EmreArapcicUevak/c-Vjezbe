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

    static void quickSort(myT *Arr , const unsigned int size , bool (*passFunc)(myT , myT)) {
        unsigned int pivitPoint = 0;

        for (unsigned int i = 1 ; i < size ; i++) {
            if (  passFunc(Arr[pivitPoint] , Arr[i])  ) {
                swap(Arr[pivitPoint] , Arr[i]);
                if (i - pivitPoint > 1)
                    swap(Arr[pivitPoint + 1] , Arr[i]);

                pivitPoint++;
            }
        }

        if (pivitPoint > 1)
            quickSort(Arr , pivitPoint , passFunc);

        const unsigned int rightSize = size - 1 - pivitPoint;

        if (rightSize > 1)
            quickSort( Arr + pivitPoint + 1 , rightSize , passFunc);
    }

    static void mergeSort(myT *Arr , const unsigned int size , bool (*passFunc)(myT , myT)) {
        if (size == 1)
            return;
        
        const unsigned int midPoint = size / 2; // velicina lijevog niza je midPoint a velicina desnog je size - midPoint
        const unsigned int rightArrSize = size - midPoint;

        mergeSort(Arr , midPoint , passFunc); // Lijevi niz
        mergeSort(Arr + midPoint , rightArrSize , passFunc); // Desni niz

        myT leftArr[midPoint] ,  rightArr[rightArrSize];
		
        for (unsigned int i = 0 ; i < midPoint ; i++)
            leftArr[i] = Arr[i];


        for (unsigned int i = 0 ; i < rightArrSize ; i++)
            rightArr[i] = Arr[midPoint + i];

        unsigned int L , R , C ;
        L = R = C = 0;

        while (L < midPoint && R < rightArrSize) {
            if (passFunc(leftArr[L] , rightArr[R])) { // Upisi elemenat sa desnog niza kada bude true a obrnuto kada bude false
                Arr[C] = rightArr[R];
                R++;
            } else {
                Arr[C] = leftArr[L];
                L++;
            }
            C++;
        }

        while (L < midPoint){
            Arr[C] = leftArr[L];
            L++;
            C++;
        }

        while (R < rightArrSize){
            Arr[C] = rightArr[R];
            R++;
            C++;
        }
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
        int Arr[] = {1,2,3,3,5,6,12};

        printArr<int>(Arr , sizeof(Arr) / sizeof(Arr[0]));
        SorthingAlgorithm<int>::mergeSort(Arr , sizeof(Arr) / sizeof(Arr[0]) , HighToLow<int>);
        printArr<int>(Arr , sizeof(Arr) / sizeof(Arr[0]));
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}

#include <iostream>
using namespace std;

template <class myT>
struct Node{
    myT Data;
    Node<myT> *Previous;
    Node<myT> *Next;
};

template <class myT>
class List{
    private:
        Node<myT> *Start;
        Node<myT> *End;
        unsigned int Size;

        void AddToEmpty(myT Data) {
            this->Start = this->End = new Node<myT>;
            this->Start->Next = this->Start->Previous = NULL;
            this->Start->Data = Data;
            this->Size = 1;
        }

        void CopyList(const List<myT> &objToCopy) {
            cout << "Copy list" << endl;
            const unsigned int size = objToCopy.GetSize();
            this->Size = 0;

            for (unsigned int i = 0 ; i < size ; i++)
                this->Push(objToCopy[i]);
        }

        void DeleteEntireList() {
            cout << "Delete list" << endl;
            Node<myT> *CurPointer = Start;

            while(CurPointer->Next != NULL) {
                CurPointer = CurPointer->Next;
                delete CurPointer->Previous;
            }
 
            delete CurPointer;
        }
    public:
        List(){
            this->Start = this->End = NULL;
            this->Size = 0;
        }

        List(myT Data){
            AddToEmpty(Data);
        }

        List(const List<myT> &objToCopy) {
            CopyList(objToCopy);
        }

        ~List(){
            DeleteEntireList();
        }

        unsigned int GetSize()const{return this->Size;}

        void Shift(myT Data) {
            if (this->Size == 0){
                AddToEmpty(Data);
                return;
            }


            this->Start->Previous = new Node<myT>;
            this->Start->Previous->Data = Data;

            this->Start->Previous->Next = this->Start;
            this->Start = this->Start->Previous;

            this->Start->Previous = NULL;
            this->Size++;
        }


        void Push(myT Data) {
            if (this->Size == 0){
                AddToEmpty(Data);
                return;
            }

            this->End->Next = new Node<myT>;
            this->End->Next->Data = Data;
            this->End->Next->Previous = this->End;
            this->End = this->End->Next;

            this->End->Next = NULL;
            this->Size++;
        } 


        void Insert(myT Data, unsigned int index){
            if(index > this->Size)
                throw "Index error (stavi to malo man je Bgt)";
            else if (index == 0)
                Shift(Data);
            else if (index == this->Size )
                Push(Data);
            else {
                Node<myT> *CurPointer = Start;

                for(unsigned int i = 0; i < index; i++)
                    CurPointer = CurPointer->Next;

                CurPointer->Previous->Next = new Node<myT>;
                CurPointer->Previous->Next->Previous = CurPointer->Previous;
                CurPointer->Previous->Next->Next = CurPointer;
                CurPointer->Previous = CurPointer->Previous->Next;

                CurPointer->Previous->Data = Data;
                this->Size++;
            }    
        }

        myT operator[](const unsigned int &Index) const{
            if(Index >= this->Size)
                throw "Index prevelk";

            Node<myT> *CurPointer;

            if(Index <= this->Size/2){
                CurPointer = Start;
                for(unsigned int i=0; i < Index; i++)
                    CurPointer = CurPointer->Next;
            }else {
                CurPointer = End;
                for(unsigned int i=0; i < this->Size - 1 - Index; i++)
                    CurPointer = CurPointer->Previous;
            }

            return CurPointer->Data;
        }

        const List<myT> &operator=(const List<myT> &objToCopy) {
            DeleteEntireList();
            CopyList(objToCopy);
        }
};

int main(int argc, char** argv) {
    List<int> a;
    List<int> b;
    b.Push(9);

    a.Push(1);
    a.Push(3);
    a.Insert(2 , 1);
    a.Shift(0);
    a.Insert(-1 , 0);
    b = a;
    
    for (unsigned int i = 0 ; i < b.GetSize() ; i++)
        cout << b[i] << endl;
    return 0;
}


#include <iostream>
using namespace std;

template <class myT>
struct Node{
    myT Data;
    Node<myT> *Previous = NULL;
    Node<myT> *Next = NULL;
};

template <class myT>
class ListIterator;

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
            const unsigned int size = objToCopy.GetSize();
            ListIterator<myT> objIt = objToCopy;
            this->Size = 0;

            for (unsigned int i = 0 ; i < size ; i++){
                this->Push(objIt.getValue());
                if (i != size - 1)
                    objIt++;
            }
        }

        void DeleteEntireList() {
            Node<myT> *CurPointer = Start;

            while(CurPointer->Next != NULL) {
                CurPointer = CurPointer->Next;
                delete CurPointer->Previous;
            }
 
            delete CurPointer;
        }

        friend ListIterator<myT>;
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


        void Delete(unsigned int index) {
            if(index >= this->Size)
                cout << "Index to big for deleting";
            
            Node<myT> *CurPointer = Start;

            for(unsigned int i = 0; i < index; i++)
                CurPointer = CurPointer->Next;


            if (CurPointer->Previous != NULL)
                CurPointer->Previous->Next = CurPointer->Next;
            else
                this->Start = CurPointer->Next;
            

            if (CurPointer->Next != NULL) 
                CurPointer->Next->Previous = CurPointer->Previous;
            else
                this->End = CurPointer->Previous;
            
                
            this->Size--;
            delete CurPointer;
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

            return *this;
        }
};

template<class myT>
class ListIterator {
    private:
        Node<myT> *CurNode;
    public:
        ListIterator() {
            CurNode = NULL;
        }

        ListIterator(const Node<myT> *CurNode) {
            this->CurNode = CurNode;
        }

        ListIterator(const List<myT> &ListObj) {
            this->CurNode = ListObj.Start;
        }

        ListIterator(const ListIterator<myT> &ListIteratorObj) {
            this->CurNode = ListIteratorObj.CurNode;
        }

        ~ListIterator(){}

        void operator++(int increment){
             if (this->CurNode->Next == NULL)
                    throw "End reached";
                else
                    this->CurNode = this->CurNode->Next;
        }

        void operator--(int decrement){
            if (this->CurNode->Previous == NULL)
                    throw "Beggining reached";
                else
                    this->CurNode = this->CurNode->Previous;
        }

        const ListIterator<myT> &operator=(const List<myT> &ListObj) {
           this->CurNode = ListObj.Start;
            return *this;
        }

        const ListIterator<myT> &operator=(const ListIterator<myT> &ListIteratorObj) {
            this->CurNode = ListIteratorObj.CurNode;
            return *this;
        }

        bool AtTheEnd() const {return this->CurNode->Next == NULL;}
        myT getValue() const {return this->CurNode->Data;}

        friend ostream &operator<<(ostream &out ,const ListIterator<myT> &obj) {
            out << obj.CurNode->Data;
            return out;
        }
};

int main(int argc, char** argv) {
    try {
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

        cout << endl;
        b.Delete(0);
        b.Delete(b.GetSize() - 1);
        cout << endl;


        for (ListIterator<int> be = b ; !be.AtTheEnd(); be++) {
            cout << be << endl;
        }
        cout << b[b.GetSize() - 1] << endl << endl;


        ListIterator<int> be = a;
        be = b;
        be++;
        be++;
        be--;
        cout << be;
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}


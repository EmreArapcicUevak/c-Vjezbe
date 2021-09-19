#include <iostream>
using namespace std;

template <class myT>
struct Node {
    myT Data;
    Node<myT> *Next;
};

template <class myT>
class Stack {
    private:
        Node<myT> *CurrentNode;

        void DeleteStack() {
            while (this->CurrentNode != NULL)
                Pop();
        }

        void CopyStack(const Stack<myT> &objToCopy){
            Node<myT> *CopyPointer = objToCopy.CurrentNode;
            Node<myT> *CurPointer = NULL;

            while (CopyPointer != NULL) {
                CurPointer = new Node<myT>;
                CurPointer->Data = CopyPointer->Data;

                if (this->CurrentNode == NULL)
                    this->CurrentNode = CurPointer;
                
                CurPointer = CurPointer->Next;
                CopyPointer = CopyPointer->Next;
            }

            if (CurPointer != NULL)
                CurPointer->Next = NULL;

        }
    public:
        Stack() {
            this->CurrentNode = NULL;
        }

        Stack(myT Data) {
            Push(Data);
        }

        Stack(const Stack<myT> &objToCopy) {
            this->CurrentNode = NULL;
            CopyStack(objToCopy);
        }
        
        ~Stack(){DeleteStack();}

        //Stavi tanjir
        void Push(myT Data){
            if(this->CurrentNode == NULL){
                this->CurrentNode = new Node<myT>;
                this->CurrentNode->Next = NULL;
            }else {
                Node<myT> * NewNode = new Node<myT>;
                NewNode->Next = this->CurrentNode;
                this->CurrentNode = NewNode;
            }

            this->CurrentNode->Data = Data;
        }


        //Uzmi tanjir odozgo
        myT Pop(){
            if (this->CurrentNode == NULL)
                throw "No stack to pop from";
            
            const myT DataToReturn = this->CurrentNode->Data;
            const Node<myT> *NodePointer = this->CurrentNode;
            this->CurrentNode = this->CurrentNode->Next;
            
            delete NodePointer;
            return DataToReturn;
        }

        const Stack<myT> &operator=(const Stack<myT> &objToCopy){
            DeleteStack();
            CopyStack(objToCopy);
            return *this;
        }

        bool AtTheEnd() {return this->CurrentNode == NULL;}
};

int main(int argc, char** argv) {
    try {
        Stack<int> Ocjene;

        Ocjene.Push(1);
        Ocjene.Push(2);
        Ocjene.Push(3);

        while (!Ocjene.AtTheEnd())
            cout << Ocjene.Pop() << endl;

        Stack<int> Augustus = Ocjene;
        Augustus.Pop();
        
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}


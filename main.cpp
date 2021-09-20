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
            this->CurrentNode = NULL;
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


template<class myT>
class Que {
    private:
        Node<myT> *LastNode;
        Node<myT> *FirstNode;

        void CopyQue(const Que<myT> &objToCopy) {
            Node<myT> *HelpNode = this->FirstNode;

            while(HelpNode != NULL) {
                Push(HelpNode->Data);
            }
        }

        void DeleteQue() {
            Node<myT> *DeleteNode;

            while(this->FirstNode != NULL){
                DeleteNode = this->FirstNode;
                this->FirstNode = this->FirstNode->Next;

                delete DeleteNode;
            }
        }
    public:
        Que() {
            this->LastNode = this->FirstNode = NULL;
        }

        Que(myT Data) {
            this->LastNode = this->FirstNode = NULL;
            Push(Data);
        }

        Que(const Que<myT> &objToCopy) {
            this->LastNode = this->FirstNode = NULL;
            CopyQue(objToCopy);
        }

        ~Que() {
            DeleteQue();
        }
        void Push(myT Data) { // O(1)
            if (this->FirstNode == NULL) // 1
            {
                this->LastNode = this->FirstNode = new Node<myT>; // 3
                this->FirstNode->Data = Data; // 1
            }else {
                this->LastNode->Next = new Node<myT>; // 2
                this->LastNode = this->LastNode->Next; // 1
                this->LastNode->Data = Data; // 1
            }

            this->LastNode->Next = NULL;// 1
        }

        myT Pop() {
            if (this->FirstNode == NULL)
                throw "No Que to pop from";

            const myT ReturnData = this->FirstNode->Data;
            Node<myT> *DeleteNode = this->FirstNode;
            this->FirstNode = this->FirstNode->Next;

            delete DeleteNode;
            return ReturnData;
        }


        const Que<myT> &operator=(const Que<myT> &objToCopy) {
            DeleteQue();
            CopyQue(objToCopy);
            return *this;
        }

        bool AtTheEnd() {return this->FirstNode == NULL;}
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
        //Augustus.Pop();
        
        Que<int> Ocjene2;

        cout << endl;
        Ocjene2.Push(1);
        Ocjene2.Push(2);
        Ocjene2.Push(3);

        while (!Ocjene2.AtTheEnd())
            cout << Ocjene2.Pop() << endl;
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}


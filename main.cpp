#include <iostream>
using namespace std;

template<class myT>
struct Node{
  myT Data;
  Node<myT> *Parent;
  Node<myT> *Left;
  Node<myT> *Right;
};

template<class myT>
class BinaryTree {
    private:
        Node<myT> *MainNode;
        bool (*passFunc)(myT , myT);
        
        void DeleteTree(){
          //
        }


        void InitCopy(const Node<myT> *nodeToCopy) {
            if (nodeToCopy == NULL)
                return;

            Add(nodeToCopy->Data);

            InitCopy(nodeToCopy->Left);
            InitCopy(nodeToCopy->Right);
        }
        
        void CopyTree(const BinaryTree &objToCopy){
          this->passFunc = objToCopy.passFunc;
          InitCopy(objToCopy.MainNode);
        }
    public:
        BinaryTree(bool (*passFunc)(myT, myT)){
          this->MainNode = NULL;
          this->passFunc = passFunc;
        }

        BinaryTree(myT Data, bool (*passFunc)(myT, myT)){
          Add(Data);
          this->passFunc = passFunc;
        }

        BinaryTree(const BinaryTree &objToCopy){
          this->MainNode = NULL;
          CopyTree(objToCopy);
        }

        ~BinaryTree(){
          DeleteTree();
        }

        void Add(myT Data){
          if(MainNode == NULL){
            this->MainNode = new Node<myT>;
            this->MainNode->Parent = this->MainNode->Left = this->MainNode->Right = NULL;
            this->MainNode->Data = Data;
          }else {
            /*
              1. Pogledaj da li se uslov ispunjava
              2. (Da uslov se ispunio)
                  {
                    Provjeravamo da li je mjesto ULJEVO slobodno ako jeste upisujemo ako nije prebacujemo se na to mjesto
                    i ponovo radimo korak 1
                  } inace {
                    Provjeravamo da li je mjesto UDESNO slobodno ako jeste upisujemo ako nije prebacujemo na to mjesto i 
                    ponovo radimo korak 1
                  }
            */
                Node<myT> *Current = this->MainNode;

                while(true) {

                    if(passFunc(Data, Current->Data)){

                        if(Current->Left == NULL) {
                        Current->Left = new Node<myT>;
                        Current = Current->Left;
                        break;
                        }else
                        Current = Current->Left;

                    } else{

                        if(Current->Right == NULL){
                        Current->Right = new Node<myT>;
                        Current = Current->Right;
                        break;
                        }else
                        Current = Current->Right;
                    }
                }

                Current->Left = Current->Right = NULL;
                Current->Data = Data;
            }
        }


        const BinaryTree &operator=(const BinaryTree &objToCopy) {
          DeleteTree();
          CopyTree(objToCopy);
          return *this;
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

int main(int argc, char** argv) {
    try {
        //
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}
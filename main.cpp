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
        
        void DeleteInit(Node<myT> *Node) {
          if (Node == NULL)
            return;

          DeleteInit(Node->Left);
          DeleteInit(Node->Right);

          delete Node;
        }

        void DeleteTree(){
          DeleteInit(this->MainNode);
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

        void printInit(ostream &out , Node<myT> *Node) const{
           if (Node == NULL)
            return;

          printInit(out , Node->Left);

          out << Node->Data << ", ";


          printInit(out , Node->Right);
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

                    if(Current->Data > Data){

                      if(Current->Left == NULL) {
                        // cout << "Add " << Data << " to left from parent node "<< Current->Data << "\n";
                        Current->Left = new Node<myT>;
                        Current = Current->Left;
                        break;
                      }else
                        Current = Current->Left;

                    } else{

                      if(Current->Right == NULL){
                        // cout << "Add " << Data << " to right from parent node "<< Current->Data << "\n";
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


        friend ostream &operator<<(ostream &out , const BinaryTree &obj){
          obj.printInit(out , obj.MainNode);
          return out;
        }

        bool searchBinaryTree(const myT &Data) {
          Node<myT> *curNode = this->MainNode;
          while (curNode != NULL){
            if (Data > curNode->Data){
              curNode = curNode->Right;
            }else if (Data < curNode->Data){
              curNode = curNode->Left;
            }else {
              return true;
            }
          }

          return false;
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
        BinaryTree<int> Nesto = LowToHigh<int>;

        Nesto.Add(90);

        for (unsigned int i = 0 ; i <= 800 ; i++)
          Nesto.Add(i);

        cout << Nesto.searchBinaryTree(800) << " " << Nesto.searchBinaryTree(805);
    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}
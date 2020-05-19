#include <iostream>
using namespace std;
struct Node{
    char color;
    struct Node* c1,*c2,*c3,*c4;
    Node():color(' '),c1(NULL),c2(NULL),c3(NULL),c4(NULL){}
};
int main(){
    struct Node* p=new Node();
    delete p;
    cout<<(p==NULL)<<endl;
    return 0;
}
#include<iostream>
#include"BinarySearchTree.h"
using namespace std;


int main(){
    BinarySearchTree b1;
    b1.insert(1);
    b1.insert(2);
    b1.insert(3);
    b1.insert(4);
    b1.insert(5);
    b1.print();
    cout<<"\n"<<b1.search(4);
    
}
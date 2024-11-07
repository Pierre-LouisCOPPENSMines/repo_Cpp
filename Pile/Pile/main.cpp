//
//  main.cpp
//  Pile
//
//  Created by Pierre-Louis Coppens on 07/11/2024.
//

#include <iostream>
struct IntStack10 {
    int size;
    int tab[10];
    void init(){
        size = 0;
        for (int i = 0; i < 10; i++){
            tab[i] = 0;
        }
    }
    void push(int a){
        tab[size] = a;
        size = size + 1;
    }
    int pop(){
        int out = tab[size - 1];
        tab[size - 1] = 0;
        size = size - 1;
        return out;
    }
    void print(){
        std::cout << "[";
        for (int i = 0; i < size - 1; i++){
            std::cout << tab[i] << " ";
        }
        std::cout << tab[size - 1] << "]" << std::endl;
    }
};
        
int main(){
    IntStack10 pile;
    pile.init();
    //pile.print();
    pile.push(1);
    //pile.print();
    pile.push(2);
    pile.push(4);
    pile.push(7);
    pile.print();
    pile.pop();
    pile.print();
}
        

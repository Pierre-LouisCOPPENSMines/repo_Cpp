//
//  main.cpp
//  Pile
//
//  Created by Pierre-Louis Coppens on 07/11/2024.
//

#include <iostream>
struct IntStack {
    int top;
    int size;
    int *tab;
    void init(int new_size){
        size = new_size;
        tab = new int[size];
        top = 0;
    }
    void push(int a){
        tab[top] = a;
        top = top + 1;
    }
    int pop(){
        int out = tab[top - 1];
        tab[top - 1] = 0;
        top = top - 1;
        return out;
    }
    void print(){
        std::cout << "[";
        for (int i = 0; i < top - 1; i++){
            std::cout << tab[i] << " ";
        }
        std::cout << tab[top - 1] << "]" << std::endl;
        std::cout << "Top : " << top << std::endl;
    }
    void free(){
        delete[] tab;
    }
};
        
int main(){
    IntStack pile;
    pile.init(30);
    for (int i = 0; i < 18 ; i++){
        pile.push(i);
    }
    pile.print();
    pile.pop();
    pile.print();
    pile.free();
}
        

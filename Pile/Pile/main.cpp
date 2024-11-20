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
    IntStack(int new_size){
        size = new_size;
        tab = new int[size];
        top = 0;
    }
    IntStack(const IntStack & intStack){
        size = intStack.size;
        tab = new int [size];
        top = intStack.top;
        for (int i = 0; i <= top; i++) {
            tab[i] = intStack.tab[i];
        }
    }
    ~IntStack(){
        delete[] tab;
    }
    IntStack & operator= (const IntStack & auxStack) {
        if (this == &auxStack) {
            return *this;
        }
        delete [] tab;
        tab = new int [size];
        top = auxStack.top;
        for (int i = 0; i <= top; i++){
            tab[i] = auxStack.tab[i];
        }
        return *this;

        
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
};
        
int main(){
    IntStack pile1 (30);
    IntStack pile2 (20);
    IntStack pile3 (pile1);
    for (int i = 0; i < 18 ; i++){
        pile1.push(i);
    }
    pile2 = pile1;
    IntStack pile4 (pile1);
    pile1.print();
    pile2.print();
    pile3.print();
    pile4.print();
    pile1 = pile1;
}
        

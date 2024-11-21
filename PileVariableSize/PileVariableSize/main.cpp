//
//  main.cpp
//  PileVariableSize
//
//  Created by Pierre-Louis Coppens on 20/11/2024.
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
    void change(int new_size){
        IntStack stock_pile (*this);
        delete [] tab;
        size = new_size;
        tab = new int [size];
        for (int i = 0; i <= top; i++) {
            tab[i] = stock_pile.tab[i];
        }
    }
    void push(int a){
        if (top < size){
            tab[top] = a;
            top = top + 1;
        }
        else {
            (*this).change(size*2);
            (*this).push(a);
        }
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
        std::cout << "Size : " << size << std::endl;
        std::cout << "Loc : " << &tab << std::endl;
    }
    //Getter
    int & get_value(int a){
        if (a < top){
            return tab[a];
        }
        else{
            std::cout << "Index out of range" << size << std::endl;
            return tab[0];
        }
    }
    int get_top(){
        return top;
    }
};
        
int main(){
    IntStack pile1 (10);
    for (int i = 0; i < 10 ; i++){
        pile1.push(i);
    }
    pile1.print();
    pile1.push(42);
    pile1.print();
}
        

//
//  main.cpp
//  ChainList
//
//  Created by Pierre-Louis Coppens on 20/11/2024.
//

#include <iostream>
struct Maillon {
private :
    int value;
    Maillon * link; // important d'être privé
    
public:
    Maillon(int new_value = 0,  Maillon * back_link = nullptr){
        value = new_value;
        link = back_link;
    }
    Maillon(const Maillon & aux_maillon){
        value = aux_maillon.value;
        link = aux_maillon.link;
    }
    Maillon & operator= (const Maillon & aux_maillon) {
        if (this == &aux_maillon) {
            return *this;
        }
        value = aux_maillon.value;
        link = aux_maillon.link;
        return *this;
    }
    //Getter
    int get_value(){
        return value;
    }
    Maillon * get_link(){
        return this->link;
    }
    //Setter
    void set_value(int val){
        value = val;
    }
    void set_link(Maillon * maille){
        link = maille;
    }
    void display_maillon(){
        std::cout << "[value : " << value << ", ancêtre : " << link << "]" << std::endl;
    }
};

struct ChainList {
private:
    Maillon * last_maillon_p;
    int Size;
public:
    ChainList(int init_value = 0){
        last_maillon_p = new Maillon;
        (*last_maillon_p).set_value(init_value);
        Size = 1;
    }
    ~ChainList(){
        while (Size > 1){
            (*this).delete_maillon();
        }
        delete last_maillon_p;
    }
    Maillon * get_last_pointer() {
        return last_maillon_p;
    }
    Maillon * get_maillon_pointeur(int a) {
        Maillon * current_maillon_p = last_maillon_p;
        int j = Size-1 - a;
        for (int i = 0; i < j; i++){
            current_maillon_p = (*current_maillon_p).get_link();
        }
        return current_maillon_p;
    }
    int get_maillon_value(int a) {
        Maillon * maillon_p = (*this).get_maillon_pointeur(a);
        return (*maillon_p).get_value();
    }
    void add_maillon(int value){
        Maillon * new_maillon_p = new Maillon;
        (*new_maillon_p).set_value(value);
        (*new_maillon_p).set_link(last_maillon_p);
        last_maillon_p = new_maillon_p; //Attention à l'opérateur copy
        Size += 1;
    }
    void delete_maillon(){
        Maillon * pre_last_maillon_p = (*last_maillon_p).get_link();
        Maillon * old_maillon =  last_maillon_p;
        last_maillon_p = pre_last_maillon_p;
        delete old_maillon;
        Size = Size - 1;
    }
    void set_maillon(int a, int value){
        Maillon * current_maillon_p = ((*this).get_maillon_pointeur(a));
        (*current_maillon_p).set_value(value);
    }
    void display_chaine(){
        for (int i = 0; i < Size-1; i++){
            int current_value = get_maillon_value(i);
            std::cout << current_value << " < ";
        }
        int current_value = get_maillon_value(Size-1);
        std::cout << current_value << "| Size : " << Size << std::endl;
    }
};

int main(){
    ChainList chaine (42);
    chaine.add_maillon(12);
    chaine.add_maillon(52);
    chaine.add_maillon(72);
    chaine.add_maillon(92);
    chaine.display_chaine();
    chaine.set_maillon(2, 18);
    chaine.display_chaine();
}

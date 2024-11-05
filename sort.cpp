//Premier programme de tri sur CPP

#include <iostream>
int main(){
    cout << 'my sort algorithm' << endl;
    int tab[] = {1,4,3,5,2,6} //taille du tableau : 6
    for (int i = 0, i < 7, i = i + 1) {
        int max = tab[i]
        int jmax = i
        for (int j = i, j < 7, j = j + 1) {
            if (tab[j] < max){
                max = tab[j]
                jmax = j
            }}
        int inter = tab[jmax]
            tab[jmax] = tab[i]
            tab[i] = inter
            }
    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
            std::cout << tab[i] << std::endl;
        }
    
        

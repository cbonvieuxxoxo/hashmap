#include "hash.h"




int main(){
    Hashmap* martini =createHM();









    addHM(martini, "liam", 10);
    addHM(martini, "mail", 31);
    addHM(martini, "a", 140);
    addHM(martini, "b", 200);
    addHM(martini, "c", 17);
    addHM(martini, "d", 75);
    display(martini);


    removeHM(martini, "mail");
    display(martini);





    removeHM(martini, "liam");
    display(martini);


    removeHM(martini, "a");
    removeHM(martini, "b");
    removeHM(martini, "c");
    removeHM(martini, "d");

    printf("L'abr est vide !!!");
    display(martini);




    freeHM(martini);
    return 0;
}
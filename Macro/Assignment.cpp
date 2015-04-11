#include <iostream>

// Uzrakstīt #define "funkciju" PrintMax kura no diviem parametriem izvada uz ekrānu maksimālo.  

#define PrintMax(a,b) {if(a<b) printf("%i",b); else printf("%i",a);}

int main(){
    PrintMax(3,2);
    system("PAUSE");
    return 0;}

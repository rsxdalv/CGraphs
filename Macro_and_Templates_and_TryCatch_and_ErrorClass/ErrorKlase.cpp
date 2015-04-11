#include <iostream>
#include <string>

class Errorr {
    public:
        Errorr(int a, std::string b){
            try{
                checkAge(a);
                checkName(b);
            }
            catch(int a)
            {
                switch(a){
                    case 1: {std::cout<<"Nepareizs vecums"<<std::endl;break ;}
                    case 2: {std::cout<<"Kludains vards"<<std::endl;break ;}
                }
            }
        }    
        ~Errorr() {}
        int checkAge(int a){
            if(a>120||a<0) throw 1;}
        int checkName(std::string a){
            if(a.length()<4) throw 2;}
};

int main(){
    std::string abc="aewe";
    Errorr err(200,abc);
    system("PAUSE");
    return 0;}

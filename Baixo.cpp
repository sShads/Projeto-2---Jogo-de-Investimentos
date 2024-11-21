#pragma once
#include <iostream>
#include <fstream>
#include "Rendimento.cpp"
using namespace std;

class Baixo: public Rendimento{
    
    public:

        virtual void atualizar(int max,int risco,ofstream& log){
            rendimento=-(risco) + (rand()%(max));
            cout<<"Rendimento Baixo: "<<rendimento<<"%"<<endl;
            log<<"Rendimento Baixo: "<<rendimento<<"%"<<endl;
        }
        
};
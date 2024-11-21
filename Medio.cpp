#pragma once
#include <iostream>
#include <fstream>
#include "Rendimento.cpp"
using namespace std;

class Medio: public Rendimento{
    
    public:

        virtual void atualizar(int max,int risco,ofstream& log){
            rendimento=-1+(-(risco*2) + (rand()%(max*3)));
            cout<<"Rendimento Medio: "<<rendimento<<"%"<<endl;
            log<<"Rendimento Medio: "<<rendimento<<"%"<<endl;
        }

};
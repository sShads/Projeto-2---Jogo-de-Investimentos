#pragma once
#include <iostream>
#include <fstream>
#include "Rendimento.cpp"
using namespace std;

class Alto: public Rendimento{

    public:
    
        virtual void atualizar(int max,int risco,ofstream& log){
            rendimento=-2+(-(risco*4) + (rand()%(max*7)));
            cout<<"Rendimento Alto: "<<rendimento<<"%"<<endl;
            log<<"Rendimento Alto: "<<rendimento<<"%"<<endl;
        }

};
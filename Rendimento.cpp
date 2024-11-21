#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Rendimento{
    protected:

        float rendimento;
    
    public:

    Rendimento();

    float getRendimento(){
      return rendimento;
    }

    virtual void atualizar(int max, int risco, ofstream& log){

    }    
/*
    int getValor(){
      this -> valor = valor + rand() %4-2;
      cout << nivel << ": Valor lido = " << this->valor << endl;
      return this -> valor;
    }

    virtual void print(){
      cout << nivel << ": Valor atual = " << valor << endl;
    }*/
        
};
#pragma once
#include <iostream>
#include <fstream>
#include "Rendimento.cpp"
#include "Baixo.cpp"
#include "Medio.cpp"
#include "Alto.cpp"
using namespace std;

class Banco{

    protected:

        Rendimento* rends[3];
        Alto a;
        Medio m;
        Baixo b;
        string nomedobanco;
        int max,risco;

    public:

        Banco(string nomedobanco,int max,int risco):
            nomedobanco{nomedobanco},a{a},m{m},b{b},max{max},risco{risco}{
            rends[0]=&b;
            rends[1]=&m;
            rends[2]=&a;
            }

        void atualizarbanco(int i,ofstream& log){
            cout<<"Opcao "<<i<<" - Risco "<<risco<<" - Banco "<<nomedobanco<<endl;
            log<<"Opcao "<<i<<" - Risco "<<risco<<" - Banco "<<nomedobanco<<endl;
            for(int i=0;i<3;i++){
                rends[i]->atualizar(max,risco,log);
            }
            cout<<endl;
            log<<endl;
        }

        string verificarrendimento(int n){
            if(n==0)
                return "Baixo";
            else if(n==1)
                return "Medio";
            else
                return "Alto";
        }

        int investir(int n, int dinheiro,ofstream& log){
            cout<<endl<<"-------------------------------"<<endl;
            cout<<"Banco : "<<nomedobanco<<endl<<"Rendimento: "<<verificarrendimento(n)<<endl;
            cout<<"Valor atual do rendimento: "<<rends[n]->getRendimento()<<"%"<<endl;
            cout<<"-------------------------------"<<endl;
            log<<endl<<"-------------------------------"<<endl;
            log<<"Banco : "<<nomedobanco<<endl<<"Rendimento: "<<verificarrendimento(n)<<endl;
            log<<"Valor atual do rendimento: "<<rends[n]->getRendimento()<<"%"<<endl;
            log<<"-------------------------------"<<endl;
            dinheiro=(dinheiro*((rends[n]->getRendimento())+100))/100;
            return dinheiro;
        }

        void tabeladerendimentos(int i,ofstream& log){
            cout<<"Opcao "<<i+1<<" - Risco "<<risco<<" - Banco "<<nomedobanco<<endl;
            cout<<"Rendimento Baixo:\t"<<-risco<<"%"<<"\t---\t"<<-risco + max<<"%"<<endl;
            cout<<"Rendimento Medio:\t"<<-(risco*2)-1<<"%"<<"\t---\t"<<-1 -(risco*2) + (max*3)<<"%"<<endl;
            cout<<"Rendimento Alto:\t"<<-(risco*4)-2<<"%"<<"\t---\t"<<-2 -(risco*4) + (max*7)<<"%"<<endl<<endl;
            log<<"Opcao "<<i+1<<" - Risco "<<risco<<" - Banco "<<nomedobanco<<endl;
            log<<"Rendimento Baixo:\t"<<-risco<<"%"<<"\t---\t"<<-risco + max<<"%"<<endl;
            log<<"Rendimento Medio:\t"<<-(risco*2)-1<<"%"<<"\t---\t"<<-1 -(risco*2) + (max*3)<<"%"<<endl;
            log<<"Rendimento Alto:\t"<<-(risco*4)-2<<"%"<<"\t---\t"<<-2 -(risco*4) + (max*7)<<"%"<<endl<<endl;
        }
};
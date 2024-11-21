#pragma once
#include <iostream>
#include <fstream>
#include "Banco.cpp"
#include "Rendimento.cpp"
using namespace std;

class Jogo{
    protected:

        Banco* bancos[4];
        string dificuldade;
        int dinheiro,rodada;
    
    public:

        Jogo(string dificuldade,int dinheiro,int rodada):
        dificuldade{dificuldade},dinheiro{dinheiro},rodada{rodada}{
                bancos[0]=new Banco("Itau",19,9);
                bancos[1]=new Banco("Santader",14,5);
                bancos[2]=new Banco("Bradesco",7,2);
                bancos[3]=new Banco("Nubank",4,1);
            }

        Banco* bank(int n){
            return bancos[n];
        }
        
        void DefinirDificuldade(int dif){
            if(dif==1){
                dificuldade="Facil";
                this->rodada=20;
            }
            if(dif==2){
                dificuldade="Medio";
                this->rodada=15;
            }
            if(dif==3){
                dificuldade="Dificil";
                this->rodada=10;
            }
        }

        void setDificuldade(int dif){
            this->dinheiro=dif;
        }

        int getDificuldade(){
            return dinheiro;
        }

        int getRodada(){
            return rodada;
        }

        void PassarRodada(){
            this->rodada=rodada-1;
        }

        string getNome(){
            return dificuldade;
        }

        void fimdejogo(ofstream& log){
            cout<<endl<<"Dinheiro Final: "<<dinheiro<<endl;
            log<<endl<<"Dinheiro Final: "<<dinheiro<<endl;
            if(dinheiro>=100000){
                cout<<"Você ganhou!"<<endl;
                log<<"Você ganhou!"<<endl;
            }else{
                cout<<"Você perdeu :("<<endl;
                log<<"Você perdeu :("<<endl;
            }
        }
};
#include <iostream>
#include <fstream>
#include "Jogo.cpp"
#include "Banco.cpp"
using namespace std;

int banco,n,dif=4,rod;
string confirmacao;
ofstream log;

void verificarbanco(){
    cout<<"Escolha o Banco para investir: ";
    log<<"Escolha o Banco para investir: ";
    cin>>banco;
    log<<banco<<endl;
    if(banco<0 || banco>4){
        cout<<"Nao existe essa opcao"<<endl;
        log<<"Nao existe essa opcao"<<endl;
        verificarbanco();
    }
}

void verificarrendimento(){
    cout<<"Escolha o rendimento: ";
    log<<"Escolha o rendimento: ";
    cin>>n;
    log<<n<<endl;
    if(n<0 || n>3){
        cout<<"Nao existe essa opcao"<<endl;
        log<<"Nao existe essa opcao"<<endl;
        verificarrendimento();
    }
    cout<<endl;
    log<<endl;
}



int main(){

    log.open("log.txt");

    srand(time(NULL));

    //escolha da dificuldade do jogo
    cout<<"Começo do jogo"<<endl<<endl<<"Escolha a dificuldade"<<endl;
    log<<"Começo do jogo"<<endl<<endl<<"Escolha a dificuldade"<<endl;
    cout<<"1-Facil"<<endl<<"2-Medio"<<endl<<"3-Dificil"<<endl<<"0-Sair"<<endl<<endl;
    log<<"1-Facil"<<endl<<"2-Medio"<<endl<<"3-Dificil"<<endl<<"0-Sair"<<endl<<endl;
    do{
    cin>>dif;
    log<<dif<<endl;
    if(dif==0)
        return 0;
    }while(dif<1 || dif>3);

    Jogo J("Facil",10000,10);
    J.DefinirDificuldade(dif);
    rod=J.getRodada();
    cout<<endl<<"Dificuldade escolhida: "<<J.getNome()<<endl;
    log<<endl<<"Dificuldade escolhida: "<<J.getNome()<<endl;

    cout<<"Invista nos bancos disponiveis para ganhar dinheiro"<<endl;
    cout<<"Escolha o numero da opcao banco e depois o tipo de rendimento"<<endl;
    cout<<"1 - Baixo"<<endl<<"2 - Medio"<<endl<<"3 - Alto"<<endl;
    cout<<"Seu objetivo e chegar a 100000"<<endl<<"Boa Sorte!"<<endl;
    cout<<endl<<"Digite qualquer coisa para continuar"<<endl;
    log<<"Invista nos bancos disponiveis para ganhar dinheiro"<<endl;
    log<<"Escolha o numero da opcao banco e depois o tipo de rendimento"<<endl;
    log<<"1 - Baixo"<<endl<<"2 - Medio"<<endl<<"3 - Alto"<<endl;
    log<<"Seu objetivo e chegar a 100000"<<endl<<"Boa Sorte!"<<endl;
    log<<endl<<"Digite qualquer coisa para continuar"<<endl;
    
    cin>>confirmacao;
    log<<confirmacao<<endl;

    //comeco do jogo
    for(int j=0;j<rod;j++){
        cout<<endl<<"=================================="<<endl;
        cout<<"Rodadas Restantes "<<J.getRodada()<<" - Dinheiro atual = "<<J.getDificuldade()<<endl;
        cout<<"=================================="<<endl<<endl;
        log<<endl<<"=================================="<<endl;
        log<<"Rodadas Restantes "<<J.getRodada()<<" - Dinheiro atual = "<<J.getDificuldade()<<endl;
        log<<"=================================="<<endl<<endl;

        cout<<endl<<"Mostrando os rendimentos maximos e minimos de cada banco"<<endl<<endl;
        log<<endl<<"Mostrando os rendimentos maximos e minimos de cada banco"<<endl<<endl;

        for(int i=0;i<4;i++){
            J.bank(i)->tabeladerendimentos(i,log);
        }

        verificarbanco();
        verificarrendimento();

        if(n==0 || banco==0)
            break;

        for(int i=0;i<4;i++){
            J.bank(i)->atualizarbanco(i+1,log);
        }

        J.setDificuldade(J.bank(banco-1)->investir(n-1,J.getDificuldade(),log));
        J.PassarRodada();

        cout<<endl<<"Digite qualquer coisa para continuar"<<endl;
        log<<endl<<"Digite qualquer coisa para continuar"<<endl;
        cin>>confirmacao;
        log<<confirmacao<<endl;
    }
    
    J.fimdejogo(log);
    log.close();

    return 0;
}

#include "incsys.h"
using namespace std;

class ArquivoLoad{
    public:
    //construtores
    ArquivoLoad(const string& nomeArquivo): nome(nomeArquivo){}

    //metodos
    //====================================================================================================

    string getNome(){
        return nome;
    }

    //====================================================================================================
    void abrir(){
        try{
            cout<<"Abrindo arquivo..."<<endl;
            arquivo.open(nome);

            if(arquivo.is_open()){
                cout<<"Arquivo aberto com sucesso"<<endl;
            }
            else{
                cout<<"Arquivo nao foi aberto"<<endl;
            }
        }
        catch (exception& e) {
        // Captura e trata uma exceção do tipo std::exception
            cout << "Erro: " << e.what() << endl;
        }
        catch (...) {
        // Captura e trata qualquer outra exceção não tratada anteriormente
            cout << "Erro desconhecido" << endl;
        } 
    }
    //====================================================================================================
    void fechar() {
        if (arquivo.is_open()) {
            arquivo.close();
            cout<<"Arquivo fechado com sucesso"<<endl;
        }
        else{
            cout<<"Arquivo esta fechado"<<endl;
        }
    }
    //====================================================================================================
    bool estaAberto() const {
        if(arquivo.is_open()){
            cout<< "Arquivo esta aberto"<<endl;
        }
        else{
            cout<< "Arquivo esta fechado"<<endl;
        }
        return arquivo.is_open();
    }
    //====================================================================================================
    void lerConteudo() {
        string linha;
        if(arquivo.is_open()){
            while (getline(arquivo, linha)) {
                conteudo += linha + "\n";
            }

            if (!conteudo.empty()) {
                cout << "Conteúdo do arquivo:\n" << conteudo << endl;
            } else {
                cout << "O arquivo está vazio." << endl;
            }
        }
        else{
            cout << "Arquivo esta fechado" << endl;
        }
    }

    //====================================================================================================
    



    private:
    string nome;
    ifstream arquivo;
    string conteudo;
};
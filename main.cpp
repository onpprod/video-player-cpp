//para compilar no linux:
//g++ main.cpp -o main -lavformat -lavcodec -lavutil -lswresample

#include "imports.h"
#include "video.cpp"

using namespace std;

string nomeArquivo;
int sel;
bool executar = true;
string play = "ffplay x";

int main() {
    Video arquivoVideo;

    while (executar)
    {
        cout<<"==========================="<<endl;
        cout<<"Op 1: Inserir nome"<<endl;
        cout<<"Op 2: Checar codec do video"<<endl;
        cout<<"Op 3: Executar video"<<endl;
        cout<<"Op 4: Sair"<<endl;;
        cout<<"==========================="<<endl;
        cout<<"Sel:";
        cin >> sel;

        switch (sel)
        {
        case 1:
            cout<<"Insira o nome do arquivo: ";
            cin >> nomeArquivo;
            arquivoVideo.setName(nomeArquivo);
            break;

        case 2:
            if(arquivoVideo.arquivoExiste()){
                cout<<"==========================="<<endl;
                arquivoVideo.getCodec();
                sleep(1);
            }else{
                cout<<"==========================="<<endl;
                cout<<"Nome do arquivo invalido."<<endl;
                sleep(1);
            }
            break;

        case 3:
            if(arquivoVideo.arquivoExiste()){
                string texto =  play.replace(play.find("x"), 1, nomeArquivo);
                system(texto.c_str());
            }else{
                cout<<"==========================="<<endl;
                cout<<"Nome do arquivo invalido."<<endl;
                sleep(1);
            }
            break;
            
        case 4:
            executar = false;
            cout<<"Saindo..."<<endl;
            break;        
        default:
            cout<<"==========================="<<endl;
            cout<<"Opcao invalida"<<endl;
            sleep(2);
            break;
        }
    }
    return 0;
}
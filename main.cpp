#include <iostream>
#include <string>

#include <libavformat/avformat.h>

//using namespace ffmpegcpp;


int main() {
    std::string nomeArquivo = "video.mp4";
    
    avformat_network_init();
    
    AVFormatContext* formatoContexto = avformat_alloc_context();
    if (avformat_open_input(&formatoContexto, nomeArquivo.c_str(), nullptr, nullptr) != 0) {
        std::cout << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return -1;
    }
    
    if (avformat_find_stream_info(formatoContexto, nullptr) < 0) {
        std::cout << "Erro ao obter informações do arquivo: " << nomeArquivo << std::endl;
        avformat_close_input(&formatoContexto);
        return -1;
    }
    
    std::cout << "Informações do arquivo de vídeo:" << std::endl;
    std::cout << "Formato: " << formatoContexto->iformat->name << std::endl;
    std::cout << "Duração (segundos): " << formatoContexto->duration / AV_TIME_BASE << std::endl;
    std::cout << "Número de fluxos: " << formatoContexto->nb_streams << std::endl;
    
    avformat_close_input(&formatoContexto);
    avformat_free_context(formatoContexto);
    
    return 0;
}
#include "imports.h"

/// @brief 
class Video
{
private:
    std::string nameVideo;
public:

void setName(const std::string& newName){
    nameVideo = newName;
}

int getCodec(){
    avformat_network_init();
    const char* video_path = nameVideo.c_str();

    AVFormatContext* formatContext = avformat_alloc_context();
    if (avformat_open_input(&formatContext, video_path, nullptr, nullptr) != 0) {
        std::cerr << "Erro ao abrir o arquivo de vídeo." << std::endl;
        return 1;
    }
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        std::cerr << "Erro ao encontrar informações do fluxo." << std::endl;
        avformat_close_input(&formatContext);
        return 1;
    }
    AVCodecParameters* codecParameters = formatContext->streams[0]->codecpar;
    AVCodec* codec = avcodec_find_decoder(codecParameters->codec_id);
    if (codec == nullptr) {
        std::cerr << "Codec não encontrado." << std::endl;
        avformat_close_input(&formatContext);
        return 1;
    }

    std::string codecName = avcodec_get_name(codec->id);
    std::cout << "Informações do arquivo de vídeo:" << std::endl;
    std::cout << "O codec de vídeo é: " << codecName << std::endl;

    std::cout << "Formato: " << formatContext->iformat->name << std::endl;
    std::cout << "Duração (segundos): " << formatContext->duration / AV_TIME_BASE << std::endl;
    std::cout << "Número de fluxos: " << formatContext->nb_streams << std::endl;

    avformat_close_input(&formatContext);
    return 0;
    }

bool arquivoExiste() {
    std::ifstream arquivo(nameVideo);
    return arquivo.good();
}

void play(){
    std::string play = "ffplay x";
    std::string texto =  play.replace(play.find("x"), 1, nameVideo);
    system(texto.c_str());
}

};


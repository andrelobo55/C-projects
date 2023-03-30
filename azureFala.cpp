#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <stdbool.h>
#include <locale.h>


using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

auto autenticacao = SpeechConfig::FromSubscription("8462efa8a357463eb3275157e86bd99d", "southcentralus"); // DECLARAÇÃO DA AUTENTICAÇÃO DO RECURSO
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao); // DECLARAÇÃO DO OBJETO DE REQUISIÇÃO DE TEXTO EM FALA DO RECURSO
auto audio_config = AudioConfig::FromDefaultMicrophoneInput(); // DECLARAÇÃO DA ENTRADA DO MICROFONE
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config); // DECLARAÇÃO DO OBJETO DE REQUISIÇÃO DE FALA EM TEXTO DO RECURSO

// PROCEDIMENTO QUE REQUISITA DA API A TRANSFORMAÇÃO DE UM TEXTO EM FALA
void texto_em_fala(string Texto)
{
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get(); // REQUISIÇÃO DA SINTETIZAÇÃO DE TEXTO EM FALA
}
// FUNÇÃO QUE REQUISITA DA API O RECONHECIMENTO DE UMA FALA E A TRANSFORMAÇÃO DESSA FALA EM UM TEXTO
string fala_em_texto() {
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get(); // REQUISIÇÃO DO RECONHEIMENTO DE FALA EM TEXTO
    cout << resultado->Text + "\n";
    return resultado->Text; //CONVERSÃO DO RESULTADO DO RECONHECIMENTO EM TEXTO
}

// PROCEDIMENTO QUE EXECUTA MENSAGENS DE AVISO AO USUÁRIO, SOBRE INFORMAÇÕES DO JOGO.
void aviso() {
    texto_em_fala("O jogador que fizer 500 pontos sem errar vence o jogo.");
    texto_em_fala("Cada pergunta respondida corretamente equivale a 100 pontos. Sendo assim, 5 perguntas que deverão ser respondidas.");
    texto_em_fala("Quanto mais avançado o jogo estiver, mais difíceis serão as perguntas.");
    texto_em_fala("Boa sorte!");
}

//PRIMEIRA FASE DO JOGO.
void fase1() {

    texto_em_fala("Primeira pergunta: Além de ser o nome de um tapete e de uma civilização,'Persa' também é uma raça de qual animal?");
    texto_em_fala("Alternativa 1: Cachorro; Alternativa 2: Gato; Alternativa 3: Urso; Alternativa 4: Pássaro.");
    string resp1 = fala_em_texto();

    //SE A RESPOSTA DO JOGADOR FOR VERDADEIRA O JOGO CONTINUA;
    if (resp1 == ("Alternativa 2.") || resp1 == ("2.") || resp1 == ("Gato.")) {
        texto_em_fala("Isso mesmo! Resposta correta!");

    }

    //SENÃO O  JOGO ACABA E ENCERRA O PROGRAMA;
    else {
        texto_em_fala("Que pena! Você errou!");
        exit(0);
    }

}

//SEGUNDA FASE DO  JOGO;
void fase2() {
    texto_em_fala("Segunda pergunta: A placa de trânsito PARE de cor vermelha é representada por qual figura geométrica?");
    texto_em_fala("Alternativa 1: Octógono; Alternativa 2: Pentágono; Alternativa 3: Losango; Alternativa 4: Hexágono.");

    string resposta2 = fala_em_texto();

    if (resposta2 == ("Alternativa um.") || resposta2 == ("1.") || resposta2 == ("Um.")) {
        texto_em_fala("Muito bom! Resposta correta!");
    }
    else {
        texto_em_fala("Que pena! Você errou!");
        exit(0);
    }

}

//TERCEIRA FASE
void fase3() {
    texto_em_fala("Terceira pergunta: Qual destas usinas do Brasil é de energia nuclear?");
    texto_em_fala("Alternativa 1: Angra 1; Alternativa 2: Igarapava; Alternativa 3: Fundão; Alternativa 4: Furnas.");

    string resposta3 = fala_em_texto();

    if (resposta3 == ("Alternativa um.") || resposta3 == ("Um.")) {
        texto_em_fala("Excelente! Resposta correta!");
    }
    else {
        texto_em_fala("Que pena! Você errou!");
        exit(0);
    }

}

//QUARTA FASE
void fase4() {
    texto_em_fala("Quarta pergunta: Como as cobras não possuem audição, o que faz com que percebam a aproximação de outros animais?");
    texto_em_fala("Alternativa 1: O cheiro deles; Alternativa 2: O calor dos corpos; Alternativa 3: As cores de pelos ou penas; Alternativa 4: A vibração do  solo.");

    string resposta4 = fala_em_texto();

    if (resposta4 == ("4.") || resposta4 == ("Quatro.") || resposta4 == ("Alternativa 4.")) {
        texto_em_fala("Você está indo bem! Resposta correta!");
    }
    else {
        texto_em_fala("Que pena! Você errou!");
        exit(0);
    }

}

//QUINTA FASE
void fase5(string nome) { //Recebe a string nome;
    texto_em_fala("Quinta e última pergunta: Quem sucedeu Fidel Castro na Presidência de Cuba, em 2008?");
    texto_em_fala("Alternativa 1: Raúl Castro; Alternativa 2: Alejandro Castro; Alternativa 3: Cesário Castro; Alternativa 4: Miguel Castro.");

    string resposta5 = fala_em_texto();

    if (resposta5 == ("Um.") || resposta5 == ("1.") || resposta5 == ("Alternativa um.")) {
        texto_em_fala("Resposta correta!");
        texto_em_fala("Parabéns " + nome + "! Você venceu o jogo!");
    }
    else {
        texto_em_fala("Que pena! Você errou!");
        exit(0);
    }

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string escolha;
    autenticacao->SetSpeechRecognitionLanguage("pt-BR");                //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA O RECONHECIMENTO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");                  //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA A SINTETIZAÇÃO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-FranciscaNeural"); //pt-BR-AntonioNeural  |CONFIGURAÇÃO DE UMA VOZ ESPECÍFICA
    //  OBS: A CONFIGURAÇÃO DA VOZ NÃO É OBRIGATÓRIA. SE A LINHA ACIMA FOR COMENTADA, O SERVIÇO ASSUMIRÁ UMA VOZ POR DEFAULT.
    //  O NOME DAS VOZES PODEM SER ALTERADOS COM O TEMPO. CASO SEU PROGRAMA NÃO ESTEJA SINTETIZANDO A VOZ ESCOLHIDA, TENTE COMENTAR A CONFIGURAÇÃO
    //  OU PESQUISE NA DOCUMENTAÇÃO DA MICROSOFT POR VOZES DISPONÍVEIS: https://docs.microsoft.com/pt-br/azure/cognitive-services/speech-service/language-support
    requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao); //  REDEFINIÇÃO DO OBJETO REQUISICAO_TEXTOFALA COM AS NOVAS CONFIGURAÇÕES 
    requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config); //  REDEFINIÇÃO DO OBJETO REQUISICAO_FALATEXTO COM AS NOVAS CONFIGURAÇÕES

    //EXECUTA O JOGO ATÉ QUANDO O JOGADOR RESPONDER NÃO AO FINAL DO JOGO OU ERRAR UMA PERGUNTA ;
    do {
        try
        {
            texto_em_fala("SISTEMA LIGADO");
            texto_em_fala("Qual e o seu nome?");
            string nome = fala_em_texto();
            texto_em_fala("Ola " + nome + "! Informe a sua senha: ");
            string senha = fala_em_texto();
            texto_em_fala("Verificando. . .");

            //SE A SENHA FOR RESPONDIDA CORRETAMENTE, O JOGO INICIARÁ E VAI EXECUTAR CADA PROCEDIMENTO DAS FASES QUE ELE POSSUI;
            if (senha == ("525405.")) {
                texto_em_fala("ACESSO CONCEDIDO");
                texto_em_fala("Bem-vindo ao jogo de Perguntas e respostas!");
                aviso();
                printf("\n");
                fase1();
                printf("\n");
                fase2();
                printf("\n");
                fase3();
                printf("\n");
                fase4();
                printf("\n");
                fase5(nome); //Passo a string nome para o procedimento fase5();
                printf("\n");
            }
            else {
                texto_em_fala("ACESSO NEGADO");
            }
        }
            catch (exception e)
            {
                cout << e.what();
            }
            texto_em_fala("Deseja jogar novamente?");
            escolha = fala_em_texto();
    } while (escolha != ("Não."));
    return 0;
}
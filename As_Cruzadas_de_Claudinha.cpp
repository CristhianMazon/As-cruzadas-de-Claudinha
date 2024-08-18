#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "stringTransform.h"

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;208m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define LIGHT_BLUE "\033[94m"
#define WHITE   "\033[37m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDGREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"

using namespace std;

const int SIZEH = 7;
const int SIZEV = 12;
bool certo;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void inicializarMatriz(char matriz[SIZEH][SIZEV]) {
    for (int i = 0; i < SIZEH; i++) {
        for (int j = 0; j < SIZEV; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void exibirMatriz(char matriz[7][12]) {
    for (int i = 0; i < SIZEH; i++) {
        for (int j = 0; j < SIZEV; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void preencherPalavraHorizontal(char matriz[7][12], string palavra, int linha, int coluna) {
    for (int i = 0; i < palavra.length(); i++) {
        matriz[linha][coluna + i] = palavra[i];
    }
}

void preencherPalavraVertical(char matriz[7][12], string palavra, int linha, int coluna) {
    for (int i = 0; i < palavra.length(); i++) {
        matriz[linha + i][coluna] = palavra[i];
    }
}

struct PalavraPontuacao {
    string palavra;
    int pontuacao;
};

int main() {
    system("chcp 65001");
    char matriz[SIZEH][SIZEV];
    inicializarMatriz(matriz);
    
    // Título e instruções
    cout << BOLDCYAN"\n\n ===> AS CRUZADAS DE CLAUDINHA <=== \n";
    cout << "\n\n Claudinha estava ministrando sua aula de programação em C++ com tranquilidade, até que foi surpreendida por um golpe certeiro na cabeça: uma placa de vídeo, lançada por sua rival implacável, AHNIDUALC (A professora de banco de dados, sua contraparte reversa).\n\nAgora, Claudinha se vê diante de um grande desafio: ela precisa preparar uma lição para seus queridos e leais alunos, mas sua memória falha em recordar conceitos fundamentais da programação. Para recuperar o que esqueceu, ela embarca em uma jornada através de uma cruzada de palavras em sua mente. Você poderia auxiliá-la nessa empreitada? Que a sorte esteja a seu favor! Aqui estão algumas dicas sobre cada palavra. Responda-as e permita que Claudinha retome suas aulas com alegria e sabedoria! :)\n\nPS.: Escreva sem acentos ou \"Ç\". \n\n\n"<<RESET;

    
    // Dicas e palavras
    string dica0 = "Processo sistemático de decomposição de algo complexo em partes menores para compreender melhor suas características e funcionamento";
    string dica1 = "Uma linguagem de programação popular, frequentemente usada para desenvolvimento de aplicativos, sistemas web e dispositivos móveis";
    string dica2 = "Uma linguagem de programação de alto nível, conhecida por sua simplicidade e versatilidade. É amplamente utilizada em ciência de dados, automação, desenvolvimento web e muito mais";
    string dica3 = "Refere-se a progresso, melhoria ou movimento para frente. Pode ser usado em diferentes contextos";
    string dica4 = "O dispositivo de entrada que usamos para digitar em computadores e dispositivos móveis. Possui várias teclas, incluindo letras, números e símbolos";
    string dica5 = "A capacidade de aprender, raciocinar e resolver problemas";
    string dica6 = "Um conjunto organizado de componentes interconectados que trabalham juntos para realizar uma função específica";
    string dica7 = "Uma avaliação formal para testar o conhecimento ou habilidades de alguém em uma determinada área";
    
    string palavra0, palavra1, palavra2, palavra3, palavra4, palavra5, palavra6, palavra7;
    
    // Armazenar palavras e pontuações associadas
    vector<PalavraPontuacao> palavrasPontuacao = {
        {"ANALISE", 10},
        {"JAVA", 8},
        {"PYTHON", 8},
        {"AVANCO", 7},
        {"TECLADO", 9},
        {"INTELIGENCIA", 11},
        {"SISTEMA", 7},
        {"EXAME", 6}
    };
    
    int pontuacaoTotal = 100; // Pontuação inicial
    
    // Loop para verificar respostas e ajustar a pontuação
    for (int i = 0; i < palavrasPontuacao.size(); ++i) {
        certo = false;
        while (!certo) {
            string resposta;
            switch (i) {
                case 0:
                    cout << BLUE "\nDica 0 \n" << dica0 << ": "<<RESET;
                    break;
                case 1:
                    cout << GREEN "\nDica 1 \n" << dica1 << ": "<<RESET;
                    break;
                case 2:
                    cout << BOLDMAGENTA "\nDica 2 \n" << dica2 << ": "<<RESET;
                    break;
                case 3:
                    cout << YELLOW "\nDica 3 \n" << dica3 << ": "<<RESET;
                    break;
                case 4:
                    cout << ORANGE "\nDica 4 \n" << dica4 << ": "<<RESET;
                    break;
                case 5:
                    cout << MAGENTA "\nDica 5 \n" << dica5 << ": "<<RESET;
                    break;
                case 6:
                    cout << CYAN "\nDica 6 \n" << dica6 << ": "<<RESET;
                    break;
                case 7:
                    cout << LIGHT_BLUE "\nDica 7 \n" << dica7 << ": "<<RESET;
                    break;
                default:
                    break;
            }
            
            cin >> resposta;
            if (toUpperCase(resposta) == palavrasPontuacao[i].palavra) {
                certo = true;
            } else {
                cout << RED"Errado"<<RESET;
                pontuacaoTotal -= 10; // Deduz 10 pontos por palavra errada
                if (pontuacaoTotal < 0) {
                    pontuacaoTotal = 0; // Limita a pontuação mínima em 0
                }
                // Mostra apenas a quantidade de pontos perdidos
                cout << RED "\n Pontos perdidos: 10\n" << RESET;
            }
        }
    }
    
    // Preencher a matriz com as palavras corretas
    preencherPalavraVertical(matriz, palavrasPontuacao[0].palavra, 0, 5);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[1].palavra, 0, 4);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[2].palavra, 1, 0);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[3].palavra, 2, 5);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[4].palavra, 3, 2);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[5].palavra, 4, 0);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[6].palavra, 5, 5);
    preencherPalavraHorizontal(matriz, palavrasPontuacao[7].palavra, 6, 5);
    
    // Exibir matriz e mostrar pontuação final
    cout << BOLDGREEN "\n\n ===> AS CRUZADAS DE CLAUDINHA <=== \n" << endl <<RESET;
    exibirMatriz(matriz);
    
cout << "..........--....--..............--......--....................        ..      ..                      ..                          ..--  ........  ........................................    ..    --  \n";
cout << "..............--............................--................          ..    --..  ..                ..                    ....  ..--........................--..--------------------------------::++::\n";
cout << "............--....::------------..----..--....--............................--------::..----------..................................--mmmmMM@@@@@@@@------........--....................................\n";
cout << "........----::::::::::++::::--------------------::------..----..............--....................------::::--::::::::::::::++++++++::::::::::::++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
cout << "mmmmmmMMMMMM++::::::++++mm++++++++mmmmmmmmmmmmmmmmmmmmmmmm++mmmm++mm++mm++++++++mm::mm++::++::::++mm::::++++++++::::++::::++::++::++++++++mmmm++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
cout << "++++mmmmmmmmmmmmmmmmmmmmmm++mmmm++++++++++++++++++++++++++++++++++++++++++++::++++--::..  ::++----::++--++::::::::::::::::::::::::++++++++++++++++++++++++++++++++++++++++++++++++++++++++++::++::::::++\n";
cout << "++++mmmmmmmmmm++++++++++++++++++++++++++++++++++++++++++++++++++++++++::::::....  ++----##--::MM++@@--::@@::++::::::::::::::::::::::++++++++++++++++++++++++++++++++++++++++++::::::::::----............\n";
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++::::::  ..--    --mm----MMmmMMmm##::MM@@##@@....--::::::::::::::::::::::++::++++++::::::++::++::::::::::::::::::----....                \n";
cout << "::::::::++++++++++++++++++++++++++++++++++++++++++++++::::::::--..      ..::  --MMMM..mmmm++mm::mm@@######@@mm----@@@@++--::::::::::::::::::::::::::::::::::::::::::::------....                        \n";
cout << "::::++++++++++++++++++++++++++++++++++++++++++++++++++++::::::::::--....--  ....--..mm..@@++@@MM####++######MM++----::::::::::::::::::::::::::::::::::::::::::::::::::::::::----....                    \n";
cout << "----::::::::::::++++++++++++++++++++++++++++::++::::::::::----..      ++  ++mm  ++--::--::--mm++MM@@MM######@@@@##mmMMMM..  --::::::::::::::::::::::::::::::::----------....                            \n";
cout << "  ....----::::::::::++++++++++++++++++++++::::::::::::------          ..::mm      --..--++--::::::::mmMMmm######mm@@--..@@------::::::::::::::::::::::::::::----------....                              \n";
cout << "      ..------::::::::::::::++++::++::::::::::::::::----..        --  --mm        --------::::::--::::++::MM######MM++MM--------------::--::::::::::::------------......                                \n";
cout << "        ....----::::::::::::::::::::::::::::::::----....          mm++--      ----::::--::--::::::::::::::::::####@@##++##..--------------------::::----..----......                                    \n";
cout << "          ....------::::::::::::::::::::::::--------....        MM..::..--    --..--::--::::::----::--::++::..--##++######@@..--..------------::++::--    --....                                        \n";
cout << "            ......----------::::::::------------....            --mm::....----  --....----::::::------::::--::::@@##::++##--##  --..----------::::::::..  ....::----......    ..                        \n";
cout << "                ....------------------------......            @@::  ------------  ....--::::::--::::::::--::..  ..########@@MM::..........----::::::--......  ..##mmmm--MM                              \n";
cout << "                  ......------------------......              ##::--------..--....--..----::::::::::::mm::--......mm######MM@@MM--..........----::::--....    ..::MM@@::MM                              \n";
cout << "                    ........----------........                @@++....------..--..------..::--::::::::--..--------::####@@++@@++::....................        ..++                                      \n";
cout << "                        ....................                ::@@::----::--........--------::::::::::::::--::  ..--::MM####@@##  ..  ..............                                                      \n";
cout << "                          ..............                    --mm..--::::--------::----::----::::++++::::::----  ::--MM##@@@@MM++@@                                                          ----  ::    \n";
cout << "                              ........                  mm::mm++--..--..--..--::::::--::----++++mmmm++++mmMM::..--++mmMM####mm::..--                                                        ++::++++++  \n";
cout << "                                                          --MM++--..----++mmmm@@@@mm++++::::++mmMM@@####@@MM@@mm--++mm######++++++++                                              ..::  ::@@mm++++mm    \n";
cout << "                                        --####@@    ..  ##  MMmm::--::mmMM##########mm++::++mmMM######@@MMMM@@@@::::mm@@@@##@@##--mm                                              ::mm@@MM++  --++      \n";
cout << "                                      ..######--##      ----::mm  MMMM++mmmmMMMM@@##@@++--::++MM@@@@mmmmmm++++@@++::mm++MM@@--####::..MM                                          MM##@@MM              \n";
cout << "                                      ############--      MMmm##--::mm++++++MM####::mm::..--++mm@@####@@##mm++mmMMMMmm######MM..--MMMM@@++                                      ++@@##@@MM              \n";
cout << "                    --@@MM::          ######@@@@@@--  --  ::mm++--mmMMmm@@##########MMmmmmmm..MM############@@MMMMmmmm--##@@@@@@--@@::++                                      ..++++MMmm....            \n";
cout << "                  ::######@@@@::      ######mm::++::  mm  ####::--MMmm####@@@@@@@@##mm@@--++++MMMMMM@@MM@@####@@MMmm..++##@@######++mm..                                      --::++++::--..            \n";
cout << "                  ########@@##@@--      ####MMmmMMMM    ##mm@@::::mm@@MMmmmmmmMMMMMM--..::::mmMM@@##MMmmMMMMMM##@@mmmmMM########MM--MM....                                  ..--::::::..--....          \n";
cout << "                  ##############@@      ##@@MM##@@++::  ++MMmm##mm::mm++mmmm@@MMMMmmmm--::::mmmmmm++mm@@MMmm::::::MM############mmMMmm..                            ..  ..------..--........            \n";
cout << "                  ########@@####@@        @@@@MM::MM  ..++MMmmmm--++..--++mmmm::::::..------mmMM++::::------::++MMMM::..##MM@@##@@@@mm--  ++                              ..--..--        ..            \n";
cout << "                  MMmm##@@MM##MM--        MM@@##@@--  ++----MMMM------............++----------MM::::::--------mm++--::@@##@@####MM##++                                  ..............    ..            \n";
cout << "                    MM@@mm--MM::          @@MM##::      ..@@@@::----      ....--mm--::--..----++MMMM::....----++  --::##@@@@######::++--  mm++                            ....            ..            \n";
cout << "                      MMmmmm++++          ::##@@    ::  ++@@MM....::++mmMMMMMMMM----::::++mmmmmm++@@@@MMMMMMmm--..::::@@##@@##@@@@::++--..--                                                            \n";
cout << "                      @@MMmmmm##        ....--::--....mmMM@@##--..::--::::mmMM##@@####mm@@MMmm######MMmm++++--::++--::####@@##MM@@@@++::--                                                              \n";
cout << "                    ..MM@@@@mm::      ....      ..mm--++++####::::::::++++MM####@@@@##@@@@@@MM@@##MM##MMmmmmmmmm++++::####@@::##@@mmMM--::--                                                            \n";
cout << "                    ::mm@@@@mm      ....  ----    ..++++::@@##::::++++mmmmMM##@@mm::++++##@@mmmmmmMM@@@@MMmmMMmmmmmm++########mm@@##mm::::------                                                        \n";
cout << "                      ..mmMMMMmm++  --..++--..--::--++mmmm@@##::++++mmmmMM@@##mm++::::++++MMmmmmmmMMMM##MMMMMMMMMMmm++####@@@@mm@@mmmm####--::@@..                                                      \n";
cout << "            ......--..----::MMMMmm::..------::----::mmMMmm@@##MM::mmmmmm@@##@@++::::----::::mmmmmmmmMM##@@MMMMMMMMMMmm######--++##mm@@++mm@@####..                                                      \n";
cout << "          MMmm++++......----::++++mm++++MM++::--::::        @@##++mmmmMM@@##@@mm##@@##@@@@@@@@####MMMMMM@@MMMMMMMMmmmm######--##++mmmmMMmm::####....                                                    \n";
cout << "          ++MM++..............----::mm++MM++++++      ..  --..##mm++++MM########MM++--..++--##########@@@@MMMMmmMMMMmm######::@@mm##++MM@@::..::++--                                                    \n";
cout << "          ++mm::--..--------..----::##++MM++::++    ..::--::++mmmmmmmmmmMMMM@@@@######  ::..MMmm@@######MMMM++MMMMmm@@########@@MMmmMM@@MM::--::--::                                                    \n";
cout << "          ++mmmmmm::--------------MMmm++MM++++::  ..----::++MMMM@@mm++++mmmm++::MMmm--mm::++mmMMMM@@MMMMMM++mmmmMMmm############MM++mmMMmmmm##::--..                                                    \n";
cout << "          ++MM@@++++--::--::::MM@@@@MM++mm++::  ..------::::mmMM##MMmmmmmmmm::::::++mmMMMMMM@@@@MMMMmmmm@@mmMMmmMMMM############MM++mmMMmmMM--::--..                                          ++        \n";
cout << "          ::MM@@++------::--::..::##mm++++::++..--------++++mmmm##@@mmmmmm++++::::mmmmmmMMMMMMMMMMMM++mmMMMMmmmmmm##############MMmmmmmmmm  --++@@::--                                                  \n";
cout << "        ..::MM##mm::--::::----::--##----@@mm##....::::++++mm++######MMMMMMmm::::++::++++mmmmmmmmmmmm++mmmmMMMMmmMM##@@##########MMMM##MMMM##--++@@++                                        --::        \n";
cout << "          ::..##MM::--::----::++::##MMMMMM####  ----::++++mmmm######@@MMMMmm++::--::--------::mm++++++mmMMMMMMMM@@##################MMMM@@mm--@@MMmm                                                    \n";
cout << "##mm@@mm++MM++::MM--MMMM++::::++mm##mm--@@####..::::::--++::mm############MMmm::----------::mm++--::++mmMMMMMMMM##@@############@@MM@@mm::++@@@@MM@@                                                    \n";
cout << "######----####@@######@@..@@@@mmMM####@@@@##            ++++mm++######--::++mmmm::::::--::::::mm::++mmMMmmMMmmMM##################++mm##MM++####@@MM                                                    \n";
cout << "MM@@##....############mmmm##@@MMmm@@########  ----::    --      ####..----++::mmmm++++mmmmmmMM++mmmmMMMMmmMMMM@@################@@######MM########::                                                    \n";
cout << "  ....    ..----mmmm@@@@mmMM++mmmmMM@@@@##--                              ::++++@@@@@@MMMMMMMMMMMMMMMMmmMMMMMM@@################################@@mm@@####..                                            \n";
cout << "....          ++++++####@@MMmm++MMmm--                                      ++++++####@@@@@@@@####MMMMMMMMMM@@######################################++MM####MMmm++                                      \n";
cout << "####@@          ..MM++mmMMMMmm::                                    --          ::++########@@MMMMMMMMMMMMMM@@############################@@@@######MMmmMMMMMMmmmmmm++--                                \n";
cout << "########        ----MM@@MMmm          ..    ######      ..      ..                  ..::####@@@@MMMMMMMMMMMM@@##############################@@######@@@@@@@@MM@@mmmmmm++  ------                        \n";
cout << "@@mm####::--mm++--::--@@##            --  ####@@##    ..    --::--  --                    ####@@@@@@MMMM@@@@##############@@######@@@@##############@@####@@@@MMMMMMmm++++--........--                  \n";
cout << "##::############----::mm        ..        ######          ----..::::          ..      ..    ######@@@@@@@@##############@@##..######@@@@##MM@@@@##########@@@@@@++mmMMmmmm::++......                    \n";
cout << "################--::      @@##........                ....                ..  --            --######@@@@##@@##########MM####::MM##@@@@@@MM@@MM@@##########@@MM##MMMMmmmm##MMmm++....                    \n";
cout << "################++            ##..    ..        ......        ....----..  ..  ..    ####        ########@@@@########@@####  ..######@@MMmmMMMM########@@####@@@@mmMM@@@@@@MM++mmmm..                    \n";
cout << "################    MM++..          ......----..--  ----..mm######....  ----....    ######      ..##MM@@@@########@@####..    @@@@@@mmmmmmMM++@@########@@####@@MMMMMM@@@@@@mm++mm++                    \n";
cout << "##############        ..      ##@@..........--....--------##########........--..    ######    ....--@@@@########@@##MM  ..--..@@MM@@@@MMmmMMmmmmMM@@########@@MMMMMMMMmm::MMmmmmmm++mm                  \n";
cout << "############        ....    ::##......--------  ----------::######@@..----------..                ----######@@@@##@@    ....    @@@@@@MMMM@@++mmMMMM##@@mmMM##MM@@@@MM@@MMMM++++MM++mmmm                \n";
cout << "##########      ....mm####        ........  ......------------  ..------------..--          --......--##@@@@@@@@@@..  ....      @@##MMMM++mmmm@@mmmm@@@@@@@@mmMM@@mm@@@@MM@@mmmmmmmmmmMM++              \n";
cout << "########      ::##      ..  ......  ....--..  ----..--------........::--------------..    ..  ....----::@@####::        ....    MMMM@@mmmm++mm@@MMMMMM@@@@MM@@MM@@MM@@MMmm##@@@@mmmmmmMMmm              \n";
cout << "######          ..--..--......    --....----##--..----::--------------------------------....--######::::##--                    mmMMmm@@@@@@mm++MM++mmmmMM++MMMM@@@@mm@@MM++MMmmMMMMMM++mm++            \n";
cout << "####      ............--................--::  ----------::----::----::--++++::::##----  ..--..++      --mmMM::                  MMMMMMmmmmMMMMMM@@++mmMMMM@@MM@@MMMM++@@##@@@@mm@@MM++mmmmmm@@          \n";
cout << "::..  ..--------  ....--....--..----..--------  ##::----::::::::::::::::@@##------..--..----    ..##..::::++mm--    ....          @@MMMMMMMMmmmmMMMM++mmMMmmmmMM@@MM@@MMmmMM##MMMMMMMMmmMMmmMM          \n";
cout << "    --..--  ....----  --------------------------..##mm::--::::++::::::::######......------..--::  --  ::--mmMM--                  MMmm++MM@@MMMM::@@mmMMmmmm@@MM@@MM@@MM@@mm##MMmm@@@@@@++mmmmMM        \n";
cout << "::    ..  ......--------..------------..--------------  ####::++----mm####  ::------::------....  ..----@@--MM--..    ..          MMmmmmMMMMMMMMMMmmmmMMmmMM@@@@MMmm@@MMMMMMmmMMMMMM@@MMMM++mmmm        \n";
cout << "##  ..........----..------------------..--..----::----::::..--....--::::::++::::--::----::--::--..  --..  ..++----..              MM@@MMMM@@@@mmmm@@@@@@MMMMMMMMMM@@@@mm@@MM::@@MMMMMM@@mmMMMMmmmm      \n";
cout << "--........--..----------..--::--::--------------::::::::::::::::::++++++::++++::::::::::----::------..::  ..mm::......            ++::MMMMMMMMmmmmMMMM@@MMMMmmmm@@@@++mmMMmmmm@@@@@@++@@mmMMMMmm++      \n";
cout << "    ....--..------....----------------..----::----::::--++++::++::::::++++++::++++::::::--::--::..::  ..++--..--      ..            mm@@MMMMMM@@MM@@MMMMMM@@@@mmMM@@MMMMMM++@@mmMMMMMM@@MMMM++mmmm      \n";
cout << "  ....  ------::::--------::--::----::--::--::::--::::::::::::::::::++++++++++++::++++++::::::------..--  ------  ..----            MMmmMMmmMMmm@@MM++MM##@@MMmm++MMMMMM++@@@@MMmmMMMMMM@@@@mmMMMM::    \n";
cout << "....  ..----::::::::--------::--::--::::::--::::::::++::++::::::++::++++++++::::++++++::::::++::..--..----........  ..----  ..      mm++mm@@@@MMmmmm@@MM@@@@MM@@MMmmMM@@MMMMMM++@@##MM@@mm@@++@@mm::    \n";
cout << "........--::----::::::::::::::::::++::::++::++----++::++++++::::::::mm++++++++++++::++::----::----------::----..    --::::          @@@@@@mmMMMMmmmm@@@@MM@@@@@@MM@@@@mmMM@@MMMM####MMMMMMMM@@MMmm::--  \n";
cout << "....  ------::::::----::::::::::::::::::::::::++++++++::++++++++++++::++++mm++++++++++++++::mm::++++::--::..----  ..----++            MM@@++@@@@@@MM@@MM##MM@@@@MMmmMMmmMM@@MMmmMMMM@@mmMMmmMMMM++::::  \n";
cout << "----------..::::::::----::::::::::::::::++--::::++++++++++mm++mm++mm++++++mmmmmmmmmmmm++++mm::++++++::::::----....--++++::....        mm@@MMMMmmMM@@@@MMMM@@@@@@MM@@@@##MM@@MMMMMM@@##MMMMMMMM@@MM----::\n";
cout << "..--------::::....--::::----::::::::--::--::::++++++++++mm::mmmmmmmmmmmmmm++mm++++mm++++++++::++::::::++--::----  ----::++::          mmMMMMMMMMmm@@mm@@mm@@++MMMMMM@@@@@@@@@@mmMM##@@MM@@MM@@MMMM----::\n";
cout << "------::::::--::..--::----::--::                      ::++++mmmmmmmmmmmm++mmmmmm++mm++mm++::::::++::::::--::--..  --++++++++          MMMMMMmmMMMMmm@@++MMMMMM##MM##mmMM@@@@MM@@mmmm##@@MMmmMM##mm----::\n";
cout << "::--::..----------::::                                        ::mmmm++++++++mmmmmm++++::::....::::::::----------  ::::::::++..        @@@@@@@@@@@@@@##@@@@MM@@MMMMMMmm@@MM@@@@MMmmmm@@@@MMMMmm##::--::--\n";
cout << "..----------::--                                                    ++mmmm++mm++++++::::::....::--::--::::++::--@@--++----::..          MM@@@@@@MMMMMMMM@@MM@@@@##MMMMmmMM++MM++++::####MMmm@@##::::::::\n";
cout << "--------..                                                              ::++++++++::--::--::....----::..::::----@@::::::++++..          @@MM@@MM@@@@mmMMMM@@MM@@MM@@@@@@@@MMmmMMmmMM##@@MM####++------::\n";
cout << "--------                                                                    --++::::--::::----..--------::::----@@++::::mm::..          mm@@MM@@mmMM@@@@MM@@@@mm@@@@##mmmm@@..MMmmMM##@@######::--::::::\n";
cout << "--::--                                                                          ::--::++++++++::::------------..@@++++++++++--          @@mmMMMMMM@@##MM@@@@MM@@@@@@@@mm@@@@mm--mmmm########++::::::::++\n";
cout << "--                                                                                ..MM@@MMmmmm++::::------..--..@@::::mmmm::            MMmmMM##@@mm@@MMMM@@MMMM@@@@@@@@mm##MM++@@++MM##MM++++::::::::::\n";
cout << "                                                      ....::--                ..    ..  --::::::++::----------..MM::++mmmm::          ..  @@@@MMMM@@++@@MMMMMMMM##mmmmMMMM--MM++mmMM@@MMmm++++::++++++::\n";
cout << "                                                  ..::@@@@MM----    ......    --        ----::++::::::::----  ..MM::mmmm++++..            ##@@MM@@@@mmMMmmMMmm@@@@##@@@@MMmmmm##@@MM@@MMMMmm++++++mm++++\n";
cout << "                                                  ::++      ..MM::............--  ..      --::----::::------..  mm--::MMmm....          ..MM@@mmMMMMMMMM@@@@@@mmmmmmMMMM..MMmmMMMMmm@@@@MMmmmmmm++++++::\n";
cout << "                                                                mm      ....--++@@          ------::--::::--::##MM::mmmm++....  ..        @@MM@@mmMMMMMMmmMMmmMMMMMM@@MMMM..::::mmMM@@@@@@MMmmmm++++++::\n";
cout << "                        ::mmmm                                            ..--mm::            --::::----::++::MM++  MMmm::--              --MMMMMM@@mm@@++MM@@MM@@MM@@MMmmmmmmmm++MM####@@MMmm++++++::++\n";
cout << "                      ++    ++@@MM                ..  ..                  --MM..--            ::..::::::----::@@mm..mm++::--..    ..  ..    MMMMMMMMMM@@MMMMMM##@@MM@@++--mmMMmmmm######@@MMmm++::++++::\n";
cout << "                                ++++                ......              ..mm::..++              ::::::::::++::mm::--MMmm--..                MMMMMMmmmmMMMM@@MM@@MMMM@@++++--MMMM@@######@@@@mm++++++++++\n";
cout << "                                                                      ..++::....                ----++::::++MMmm++--@@----  ..  ....        @@@@mmmmmmMMmm@@MM@@++@@::mmmm@@@@MM##########@@MM++++++mm++\n";
cout << "                                                  ..  ..            ::::----..                    ::++::++::mmmm----++::--....              @@mmMM++MMMM@@mmMMmmMM@@mm  mm++MMMM##########@@MMmmmmmm++++\n";
cout << "                                                              --++::----::..--                    ::mm--mm@@MMmm::--mm--..  ..  --            @@MM@@mmMM@@mmMM@@MM--MMmmmmMMMM@@############MMMMmmmmmmmm\n";
cout << "                                                    ..::@@##@@::--........++                    ::++++MM++MMmm++--##::--....  ..            ..MM@@MM@@MM@@@@MMmmmm----mm@@MM################@@MMmmmmmmmm\n";
cout << "                                      ----::++++@@@@++------..............                  ..  mm::mmmm@@mmMM++::MM::::--                    @@MMMMMM@@MM@@MMMMmmmmmmmmMM@@@@##############@@@@@@@@@@MM\n";
cout << "                            ......----..--::##mm--..........--::::::::                      ..--mmmmMM++##mmMM++::mm::::..--  --              MMMM@@@@MMMM++mmmm::++MMMM@@####@@################@@mm::::\n";
cout << "                          ..----....mm##MM::----......  ....----..@@--        ........------++++++@@MM####mm++mm++::::......                  @@MM@@@@MMMMMMMMmm    MM@@@@####MM##############@@mm::::::\n";
cout << "                    ....--..--++::MMMM::..  ....  ..................................--::..::::::++MM########mmmm::++..::::..  ..                @@MMmm@@@@@@@@      ..######@@@@##############mm++++::--\n";
cout << "          ..  ..    --::--::--@@mm--......  ........................--........--------::::::++++MMmm@@@@@@++::::++--::::..          ....  ..    MMMM@@##@@##@@    ..##########@@  ########----..mm::::--\n";
cout << "##    ..      ----::--::::MMmm..............    ..........................--::::::::::mm++++++mmMMMMMMmm++++++++--::::::          ..  ..  ....  @@MM##@@##@@    --..############    ##::::----......--::\n";
cout << "####..        ..--++MMMM##::..........    ........................--::::::++++++++++++MMMMMM@@mmmmMM++mm::++--::::::::--..  ....    ......      @@@@@@@@@@        ..@@######@@@@    ++::++----  ......--\n";
cout << "##                  ..--::--..........    ............  ......::++++++++mmmmmm++++++MMMMMM::MMmmmmmmmmmm++mm::--::++::--    ..--..--....              mm--        ..##@@##@@####    ++::--..    ------::\n";
cout << "  ..........----------::--..........................--  ....------mmMMMMMMMM@@@@@@++--  ::MMmmmmMMmm++mmmm++mmmmmm++..--....                                        ##@@##@@####  ::mm----......--------\n";
cout << "  --......--..------::##----..........--..........--::::--..--::::mmmm++++mm@@@@mm++mmMMMMMMmmmm++mm::++++++mmMM++::--                                ::      --        ..####    ++++::::----..--------\n";
cout << "  ..........--..--::MMMM::------..--..----..------::::::::::------::::::::--::::++mmmmmmMMmmmmmmmmmmmmmm++MMMMmm::                                  ..--              ......  mm++++++::::::++::::::::::\n";
cout << "##........----::mmMM##++::::------..----------------::::--------....--::++++::----::::++::mmmmmmMMMMmmMMMMMMMMMM                                    ....        ..  --::::..      ++++++::--++++++++++::\n";
cout << "##----..::::++MM::####++::--::::--::::------..------::::::::::------::++++mmmmmmmmmmmmmm++MMMMMM@@mm@@MM@@MM                                      --..              --::::..    ..--++++::----MM@@@@--..\n";
cout << "################mm##@@++::::::++++::::::::----::::----++::::::----++++mmmmMMmmMM@@MMMMmmmm@@@@MM@@@@@@@@MM                                        --                ::::::..      ..++++++++::MM::------\n";
cout << "##############--mm##MMmm++++++++::::::--++++::++++++++mm++::::++mmMM@@MMMMMMMMMMMMMM@@@@@@MM@@MM@@@@@@@@mm                                      --    ..  ::@@@@mm  --::::          mmmmmm++++++++::::++\n";
cout << "##############--mm@@MMmmmm++::++++mm++::++mmmmmmmmmmmm++++mm++MM@@MM@@@@@@MMMMMM@@MMMM@@MMMM@@MM@@@@@@MM                                            ##  ++##mm######mm::::          ..mmmmmm::..::::mm++\n";
cout << "##############::mmMMMMmmmm++::mm++++mm++++++mmmmmmmmmmMMMMmm++mmmmMMMMMMMMMMMMMM@@@@@@@@@@@@@@@@@@@@@@                                        ....  ::##::mm########@@::::        ..    ----        mmMM\n";
cout << "@@@@@@####@@##++mmmmMMmmmm++++++++++++mmmm++++mmmmmmmmmmmmmmmm::mmMMMMMM@@@@MMMM@@@@@@MMMMMM@@@@@@@@MM                                          ..::  @@##########mm##@@::              ..          ++MM\n";
cout << "@@@@##@@@@####++mmmmMMMMMMMMmmmm++++::++::mmmmmmmmmmmmmmmmmmmmMMMMMM@@##########MM@@@@@@@@@@@@@@@@@@@@                                        ++####MM::MM##########    ++--..            ..          MM\n";
cout << "@@##@@@@MM####mmmmMMmmMMMMMMMMMMmmMMMMmmmmMMMMmmMMmmmmmmmmmmMM@@@@MM############MM@@@@@@@@@@@@@@@@MMMM                                  ..    ######################    ::----      ....      ..      ..\n";
cout << "##MMMMMMMM####mmmmmmMMMMMMMMMM@@MMMMMM@@######MMMMMMMMmmmmMMMM@@@@##############@@@@@@@@MM@@@@@@MMMMMM                                      ####@@######@@########  ..++::::--..    ..    ..            \n";
cout << "MMMMMMMMmm####MMmmMMmmMMMMMMMMMMMMMMMM@@##########----++@@@@@@##################MM@@MM@@@@MM@@@@MMMMMM                                      ++::##@@########@@####  --##MM--..  ....                    \n";
cout << "MMMMmmmmmm####mmMMMMMMMMMMMM@@@@MMMMMMMM##########----..##########################@@MM@@@@@@@@MM@@MMmm                                    --  ####--############      ..@@--      ..                    \n";
cout << "mmmmmmmm++####mm++MMMMMMMMMMMM@@MMMMMM@@@@######..------##########################@@@@@@MMMMMMMM@@@@mm                                    --@@MM  ######MM##MMmm####@@  --                    ..        \n";
cout << "mm++++++++####++++MMMMMMMMMMMMMMMMMM@@MM@@####@@..----..##########################MMMM@@MM@@MMMMMMMMMM::                                    ..########@@MM@@++MM::                        ..::..        \n";
cout << "++++++++::####::::::MMMMMMMMMMmmMMmmMMMM@@####..------..##########################MMMMMMMMMMMMmmMMmmmmmm                                      ..++--------::--                                          \n";
cout << "::::::::::####++::::::mmmmMMMMmmMMMMMMMMMM++++------....##########################MMMMmmMMMMMMmmmmmmmmmmmm                                    ..    ::    mm@@..                        ..              \n";
cout << "::::::++::####::::::--####@@@@@@@@@@..........::--......##########################mmmmmmmmmmmmmmmmMMMMmmmm..                                    --....                  ##mm--    ..                    \n";
cout << "::::::++::####::::::::@@##@@--++::..........----..      ############################mm++mmmmmmmmmmmmmmmmmm::                                      ..::::mm            MM##mm                            \n";
cout << "++++++++++####::::::::--####mm++--........--::--..      ############################mm++++mmmmmmmmmm++mm++::::..                        ..    mm@@MMMM@@@@@@--                                    ::    \n\n";


cout << "                                                                        ##                    ##                                                                                                ####                                                                                  ####                                                                                                                      \n";
cout << "                  ##########                                            ##                  ##                                                                                                MMmm++mm                                                                                ####                  ##--                                                                                                \n";
cout << "                  ##      ####                                          ##                                                                                                                                                                                                            ####                  ##--                                                                                                \n";
cout << "                  ##      mm##  ########      ##..####  ##########      ##########      ########      ##::######      ########                  ##++      ##::    ########      ########      ########              ########++    ########      ########@@..######      ##########    ####    ::######@@  MM########    ########    ####      ##                                                                \n";
cout << "                  ##      ####          ##    ####              ##      ##      ##    @@##      ##    ##@@    ##@@  ##::                        ..##      ##    ##      ##    ####          ##mm    @@##          ++##          ##@@    ####    ##      ####    ##--    ##      ##    ####    ##      ##    ##--      ##      ##..  ####      ##                                                                \n";
cout << "                  ##########      mm######    ##--        --########    ##      ####  ##        ##    ##      ####  ####                          ##    ####    ##      @@##  ##            ##        ##          ##--          ##        ##    ##      ##      ####    ##      ####  ####  ####      ##MM  ##--      ##      MM##  ####      ##                                                                \n";
cout << "                  ##            ##--    ##    ##..      ####    ####    ##      ::##  ############    ##      ####    --######                    ####  ##      ##      mm##  ##            ############          ##            ##        ##    ##      ##      ####    ##      ####  ####  ##############  ##--      ##      mm##  ####      ##                                                                \n";
cout << "                  ##          ##@@      ##    ##..      ##      ####    ##      ####  ##--            ##      ####          ##..                    ##  ##      ##      ####  ##++          ##                    ####          ##        ##    ##      ##      ####    ##      ##MM  ####  ####            ##--      ##      ####  ####      ##                                                                \n";
cout << "                  ##          mm##    ####    ##..      ##::  ::####    ####    ##      ##      ##    ##      ####  ##      ##    ####              ####@@      ####  ..##      ##          ####      ##            ##--    ++  ####    ##++    ##      ##      ####    ####  --##    ####    ##mm    ::    ####      ####    ##      ##    ####                                                                \n";
cout << "                  ##            ######  ##    ##..        ####MM####    ##..####          ######++    ##      ####  ::######      ##@@              MM##          ######          ######      ::######..              ######      mm####::      ##      ##      ####    ##--####      ####      ########      @@####    ######        ++####  ##                                                                \n";
cout << "                                                                                                                                  ##                                                                                                                                    ##                                                                                                                                      \n";
cout << "                                                                                                                                                                                                                                                                        ##                                                                                                                                      \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                  ##                                                ######  ##                                                                  ####++##                                            ##              ::                                                                                                                                                          \n";
cout << "                                                  ##                                                ##                                                                          ..                                                  ##            --##                                                                                                                                                          \n";
cout << "                    ######                --####  ##      --####        ######mm      ######    ++######@@  ##      @@####                  ####++              ##  ####        ######          ######                  ####        ##  ####      ########      ####      ##        ####    --####                ######          ######                                                                        \n";
cout << "                  ####  @@##            ####    ####    ####    ##    ####    ##    ##    ####      ##      ##    ####  ::##              ##    ####            ####  ::##    ..mm    ##--    ####  mm##            mm##    ##--    ####  ..##    --##      --##    ####  ####      ##    ####    ##            ++--    ##      ##    mm                                                                        \n";
cout << "                  ##      ####          ##      MM##    ##      ::##  ##                    ##      ##      ##    ##      ####          ##        ##            ##      ##              ##    ##      ####          ##        ##    ##      ####  --##      ##        ##    ##    ..##    ##      --##                  ::##  MM##                                                                              \n";
cout << "                mm##      MM##          ##        ##    ############    ######      ##########      ##      ##    ##      ..##          ############            ##      ##      ##########  ++##      MM##          ##        ##    ##      --##  --##      ############    ##    ##++    ############            ##########    ######                                                                          \n";
cout << "                ::##      ####          ##        ##    ##                  @@##  ..##      ##      ##      ##    ##      mm##          ##                      ##      ##    ##..      ##  ..##      ####          ##        ##    ##      ++##  --##      ##              --##  ##      ##                    ##      ++##          ##::                                                                      \n";
cout << "                  ##      ##..          ##++    ####    ##                    ##  ..##      ##      ##      ##    ##      ##mm          ####                    ##      ##    ##      ####    ##      ##            ##MM    ####    ##      ##++    ##      ##@@              ##@@##      ##                    ##      ####          ####                                                                      \n";
cout << "                  mm########              ######::##      ##########  ##########    ##########      ##      ##      ########              ##########            ##      ##    ::######..##    --########              ########      ##########      ######    ##########      ####          ##########          MM######  ##  ##########                                                                        \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                                                                                                                                                                                                                                                                                                                \n";
cout << "                                                                                                                            ####                                    ##                                                                                                                                                                                                                                          \n";
cout << "                                                                                                                          ##  ::@@                                  ##                                  ##                                                                                                                                                                                                      \n";
cout << "                                                                                                                                                                                                        ##                                                                                                                                                                                                      \n";
cout << "                  ..########    ########..    ##--######      ########      ########      ##########    ##@@      ##      ########      ##########      ########    ##      ########      ########      ##                                                                                                                                                                                                      \n";
cout << "                  ##          --##      ##    ####    ####  ####          ##::    ++##    ##      ##    ##@@      ##    ##..    @@##    ##      ##    ####          ##            @@##  --##            ##                                                                                                                                                                                                      \n";
cout << "                --##          ##@@      ##    ##      --##    ##MM        ##        ##  ####      ##    ##@@      ##    ##        ##    ##      ##    ##            ##        ########    ####          ##                                                                                                                                                                                                      \n";
cout << "                mm##          ##mm      ##    ##      ..##      ######    ##MMMMMMMMMM  ##MM      ##    ##@@      ##    ##MMMMMMMMMM    ##      ##    ##            ##    ####      ##      ######      ##                                                                                                                                                                                                      \n";
cout << "                  ##          ####      ##    ##      ..##          ####  ##            ####      ##    ####      ##    ##              ##      ##    ##..          ##    ##      MM##          ####                                                                                                                                                                                                            \n";
cout << "                  ####    ##    ##--  ####    ##      ..##  ##..    ##    @@##      ##    ##    ####      ##    ####    ####      ##    ##      ##      ##          ##    ####    ####  --mm    ##MM    ##                                                                                                                                                                                                      \n";
cout << "                    @@####::      ####@@      ##      ..##    ######          ######        ####  ##      --####  ##        ######      ##      ##        ######    ##      ####@@  ##    ######::      ##                                                                                                                                                                                                      \n";
cout << "                                                                                                  ##                                                                                                                                                                                                                                                                                                            \n";
cout << "                                                                                                  ##                                                                                                                                                                                                                                                                                                            \n";

    cout << BOLDGREEN "\n Aqui está sua pontuação total: " << pontuacaoTotal << "\n" <<RESET;
    cout << BOLDGREEN "\n Afaste um pouco para ver melhor ;)\n\n\n";

    return 0;
}

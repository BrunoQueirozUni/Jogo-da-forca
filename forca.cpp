#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int numeroAleatorio, tentativas;
    char l1, l2, l3, l4, l5, l6;
    char oc1, oc2, oc3, oc4, oc5, oc6;
    char opcao;
    bool ganhou, acertou;

    do {
        system("cls");
        // Angelo: Reset de jogo
        ganhou = false;
        acertou = false;
        numeroAleatorio = rand()%10 + 1;
        tentativas = 10;
        oc1 = '_', oc2 = '_', oc3 = '_', oc4 = '_', oc5 = '_', oc6 = '_';

        // Menu de opções
        cout << "-------------------------------\n";
        cout << "| Bem-vindo ao jogo da forca! |\n";
        cout << "-------------------------------\n";
        cout << "| Escolha uma opcao:          |\n";
        cout << "| 1 - Jogar                   |\n";
        cout << "| 2 - Sobre                   |\n";
        cout << "| 3 - Fim                     |\n";
        cout << "-------------------------------\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            // Angelo: Logica do jogo
            case '1': {
                // Angelo: Seleciona aleatoriamente a palavra do secreta
                switch (numeroAleatorio) {
                    case 1: 
                        l1 = 'a', l2 = 'n', l3 = 'g', l4 = 'e', l5 = 'l', l6 = 'o';
                        break;
                    case 2:
                        l1 = 'b', l2 = 'r', l3 = 'a', l4 = 's', l5 = 'i', l6 = 'l';
                        break;
                    case 3:
                        l1 = 'a', l2 = 'm', l3 = 'i', l4 = 'g', l5 = 'o', l6 = 's';
                        break;
                    case 4:
                        l1 = 's', l2 = 'a', l3 = 'l', l4 = 't', l5 = 'o', l6 = 's';
                        break;
                    case 5:
                        l1 = 'f', l2 = 'l', l3 = 'o', l4 = 'r', l5 = 'e', l6 = 's';
                        break;
                    case 6:
                        l1 = 'p', l2 = 'l', l3 = 'a', l4 = 'n', l5 = 'o', l6 = 's';
                        break;
                    case 7:
                        l1 = 's', l2 = 'o', l3 = 'n', l4 = 'h', l5 = 'o', l6 = 's';
                        break;
                    case 8:
                        l1 = 'f', l2 = 'r', l3 = 'u', l4 = 't', l5 = 'a', l6 = 's';
                        break;
                    case 9:
                        l1 = 'm', l2 = 'u', l3 = 'n', l4 = 'd', l5 = 'o', l6 = 's';
                        break;
                    default:
                        l1 = 'c', l2 = 'o', l3 = 'd', l4 = 'i', l5 = 'g', l6 = 'o';
                }

                // Angelo: Loop principal do jogo
                while (tentativas > 0 && ganhou != true) {
                    system("cls");
                    acertou = false;
                    
                    // Angelo: "Animação" do boneco se montando conforme o jogo roda, tem um problema pra arrumar
                    // Angelo: Quando as tentativas chegam em 0 o loop fecha sem mostrar a perna direira... Será arrumado
                    cout << "-------------------------------\n";
                    cout << "|            +---+            |\n";
                    cout << "|            |   |            |\n";
                    if (tentativas < 10) {
                        cout << "|            O   |            |\n";
                    } else {
                        cout << "|                |            |\n";
                    }
                    if (tentativas == 8) {
                        cout << "|           /    |            |\n";
                    } else if (tentativas == 7) {
                        cout << "|           /|   |            |\n";
                    } else if (tentativas <= 6) {
                        cout << "|           /|\\  |            |\n";
                    } else {
                        cout << "|                |            |\n";
                    }
                     if (tentativas == 5) {
                        cout << "|           /    |            |\n";
                    } else if (tentativas <= 4) {
                        cout << "|           / \\  |            |\n";
                    } else {
                        cout << "|                |            |\n";
                    }
                    cout << "|                |            |\n";
                    cout << "|         =========           |\n";
                    cout << "|                             |\n";
                    cout << "-------------------------------\n";

                    // Angelo: Menu "interativo" do usuario no jogo, tem um bug de poder escrever a palavra inteira
                    cout << "Numero de tentativas: " << tentativas << endl;
                    cout << "Palavra: " << oc1 << oc2 << oc3 << oc4 << oc5 << oc6 << endl;
                    cout << "Digite uma letra: ";
                    cin >> opcao;
                    
                    // Angelo: Bloco que mostra a letra quando ela é acertada, e muda o acerto pra true
                    if (opcao == l1) {oc1 = l1; acertou = true;}
                    if (opcao == l2) {oc2 = l2; acertou = true;}
                    if (opcao == l3) {oc3 = l3; acertou = true;}
                    if (opcao == l4) {oc4 = l4; acertou = true;}
                    if (opcao == l5) {oc5 = l5; acertou = true;}
                    if (opcao == l6) {oc6 = l6; acertou = true;}

                    // Angelo: Verifica se ganhou
                    if (oc1 == l1 && oc2 == l2 && oc3 == l3 && oc4 == l4 && oc5 == l5 && oc6 == l6) {ganhou = true;}

                    // Angelo: Faz o numero de tentarivas não diminuir se a pessoa acertar a letra
                    if (acertou == false) {
                        tentativas--;
                    }

                    // Bruno: Mensagem de vitória para saber se realmente ganhou
                    if (ganhou == true) {
                        system("cls");
                        cout << "-------------------------------\n";
                        cout << "|    Parabens! Voce ganhou!   |\n";
                        cout << "-------------------------------\n";
                        system("pause");
                    }

                    // Bruno: Mensagem de derrota para saber se realmente perdeu
                    if (tentativas == 0) {
                        system("cls");
                        cout << "-------------------------------\n";
                        cout << "|    Que pena, voce perdeu!   |\n";
                        cout << "-------------------------------\n";
                        system("pause");
                    }
                }
            }
            break;
            // Angelo: Menu de sobre do jogo
            case '2': {
                system("cls");
                cout << "------------------------------\n";
                cout << "|            SOBRE           |\n";
                cout << "------------------------------\n";
                cout << "| Nome dos desenvolvedores:  |\n";
                cout << "| - Angelo Miguel Requenha   |\n";
                cout << "| - Bruno de Queiroz         |\n";
                cout << "| - Luiz Eduardo Oro de Souza|\n";
                cout << "| - Carlos Eduardo Serafim   |\n";
                cout << "| - Leandro Gabardo          |\n";
                cout << "------------------------------\n";
                cout << "| Professor: Rafael Ballottin|\n";
                cout << "|            Martins         |\n";
                cout << "------------------------------\n";
                cout << "| Data: 16/10/2024           |\n";
                cout << "------------------------------\n";
                cout << "| Regras do jogo:            |\n";
                cout << "| - Somente letras minusculas|\n";
                cout << "| - O jogador tem 10 vidas   |\n";
                cout << "| - O jogador deve acertar   |\n";
                cout << "|   a palavra secreta        |\n";
                cout << "| - O jogador deve chutar    |\n";
                cout << "|   uma letra por vez        |\n";
                cout << "------------------------------\n";
                system("pause");
                break;
            }
            default:
                if (opcao == 3) {
                    system("cls");
                    cout<<"Saindo do jogo!\n";
                    system("pause");    
                    break;
                }
                cout << "Opcao invalida!\n";
                system("pause");
            break;
        }
    } while (opcao != 3);

    return 0;
}

#include <iostream>
#include "operacoesVetores.h"
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

void selecaoDeOperacao();
vector<float> leituraVetores(int);

short int opcao;
char continuar;

const int tamanho = 3;
float constante = 0;
vector<float> vetorU;
vector<float> vetorV;
vector<float> vetorW;

int main() {

    cout << " -------------------------------------------- " << endl;
    cout << " |Bem vindo ao Programa de Calculo de Vetor! |" << endl;
    cout << " -------------------------------------------- " << endl;

    selecaoDeOperacao();
    return 0;
}

vector<float> leituraVetores(int tamanho){
    vector<float> vetor;
    for(int i = 0; i < tamanho; i++){
        cout << "Insira o valor do elemento na posicao " << i + 1 << ": ";
        float valor;
        cin >> valor;
        vetor.push_back(valor);
    }
    return vetor;
}

void selecaoDeOperacao() {
    std::vector<std::vector<float>> resultado;


    system("CLS");
    cout << " ----------------------------------" << endl;
    cout << "| Qual programa deseja executar?  |" << endl;
    cout << "| 1 - Soma de Vetores             |" << endl;
    cout << "| 2 - Subtracao de Vetores        |" << endl;
    cout << "| 3 - Multiplicacao Constante     |" << endl;
    cout << "| 4 - Modulo de Vetores           |" << endl;
    cout << "| 5 - Produto Escalar de Vetores  |" << endl;
    cout << "| 6 - Angulo entre Vetores        |" << endl;
    cout << "| 0 - Sair                        |" << endl;
    cout << " ----------------------------------" << endl;
    cin >> opcao;
    switch (opcao) {
        case 1:
            cout << "Insira o vetor U" << endl;
            vetorU = leituraVetores(tamanho);
            cout << "Insira o vetor V" << endl;
            vetorV = leituraVetores(tamanho);
            cout << "Insira o vetor W" << endl;
            vetorW = leituraVetores(tamanho);
            resultado = somaVetores(vetorU, vetorV, vetorW, tamanho);

            cout << "Deseja Realizar Mais Operacoes?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "A soma dos vetores é:" << endl;
                for(int i = 0; i < resultado.size(); i++){
                    if (i == 0){
                        cout << "U + V = ";
                    } else if (i == 1){
                        cout << "U + W = ";
                    } else {
                        cout << "V + W = ";
                    }
                    for(int j = 0; j < resultado[i].size(); j++){
                        cout << resultado[j][i] << " ";
                    }
                    cout << endl;
                }
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 2:
            cout << "Insira o vetor U" << endl;
            vetorU = leituraVetores(tamanho);
            cout << "Insira o vetor V" << endl;
            vetorV = leituraVetores(tamanho);
            cout << "Insira o vetor W" << endl;
            vetorW = leituraVetores(tamanho);
            resultado = subtracaoVetores(vetorU, vetorV, vetorW, tamanho);

            cout << "Deseja Realizar Mais Operacoes?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "A subtracao dos vetores é:" << endl;
                for(int i = 0; i < resultado.size(); i++){
                    if (i == 0){
                        cout << "U - V = ";
                    } else if (i == 1){
                        cout << "U - W = ";
                    } else {
                        cout << "V - W = ";
                    }
                    for(int j = 0; j < resultado[i].size(); j++){
                        cout << resultado[j][i] << " ";
                    }
                    cout << endl;
                }
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 3:
            cout << "Multiplicação de Vetores" << endl;
            // Código para a multiplicação de vetores
            cout << "Deseja Ler mais Vetores?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "Programa encerrado!" << endl;
            }
            break;
            break;
        case 4:
            cout << "Módulo de Vetores" << endl;
            // Código para o módulo de vetores
            cout << "Deseja Ler mais Vetores?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "Programa encerrado!" << endl;
            }
            break;
            break;
        case 5:
            cout << "Produto Escalar de Vetores" << endl;
            // Código para o produto escalar de vetores
            cout << "Deseja Ler mais Vetores?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 6:
            cout << "Ângulo entre Vetores" << endl;
            // Código para o ângulo entre vetores
            cout << "Deseja Ler mais Vetores?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 0:
            cout << "Programa encerrado!" << endl;
            break;
        default:
            cout << "Selecione uma opção válida!" << endl;
            selecaoDeOperacao();
            break;
    }
}

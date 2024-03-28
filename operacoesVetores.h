//
// Created by henry on 21/03/2024.
//

#ifndef PROJETOCALCULOSBRITTO_OPERACOESVETORES_H
#define PROJETOCALCULOSBRITTO_OPERACOESVETORES_H

#endif //PROJETOCALCULOSBRITTO_OPERACOESVETORES_H

#include <math.h>
#include <vector>

using namespace std;

// Função que realiza a soma de dois vetores
std::vector<std::vector<float>> somaVetores(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho){
    vector<vector<float>> vetorResultado;
    vector<float> vetorAux(tamanho);
    // Soma vetor U e V
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] + vetor2[i];
    }
    vetorResultado.push_back(vetorAux);
    // Soma vetor U e W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] + vetor3[i];
    }
    vetorResultado.push_back(vetorAux);
    // Soma vetor V e W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor2[i] + vetor3[i];
    }
    vetorResultado.push_back(vetorAux);

    return vetorResultado;
}
vector<vector<float>> subtracaoVetores(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho){
    vector<vector<float>> vetorResultado;
    vector<float> vetorAux(tamanho);
    // Subtração vetor U e V
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] - vetor2[i];
    }
    // Resultado Subtração U e V
    vetorResultado.push_back(vetorAux);
    // Subtração vetor U e W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] - vetor3[i];
    }
    // Resultado Subtração U e W
    vetorResultado.push_back(vetorAux);
    // Subtração vetor V e W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor2[i] - vetor3[i];
    }
    // Resultado Subtração V e W
    vetorResultado.push_back(vetorAux);

    return vetorResultado;
}

vector<float> multiplicacaoConstante(float vetor[], float constante, int tamanho){
    vector<float> vetorResultado(tamanho);
    for(int i = 0; i < tamanho; i++){
        vetorResultado.at(i) = vetor[i] * constante;
    }

    return vetorResultado;
}

vector<float> anguloEntreVetores(float vetor1[], float vetor2[], int tamanho){
    vector<float> vetorResultado(1);
    float produtoEscalar = 0;
    float moduloVetor1 = 0;
    float moduloVetor2 = 0;
    for(int i = 0; i < tamanho; i++){
        produtoEscalar += vetor1[i] * vetor2[i];
        moduloVetor1 += pow(vetor1[i], 2);
        moduloVetor2 += pow(vetor2[i], 2);
    }

    moduloVetor1 = sqrt(moduloVetor1);
    moduloVetor2 = sqrt(moduloVetor2);

    vetorResultado.at(0) = acos(produtoEscalar / (moduloVetor1 * moduloVetor2));

    return vetorResultado;
}
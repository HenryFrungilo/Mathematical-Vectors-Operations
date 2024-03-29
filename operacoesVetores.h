//
// Created by henry on 21/03/2024.
//

#ifndef PROJETOCALCULOSBRITTO_OPERACOESVETORES_H
#define PROJETOCALCULOSBRITTO_OPERACOESVETORES_H

#endif //PROJETOCALCULOSBRITTO_OPERACOESVETORES_H

#include <cmath>
#include <vector>

using namespace std;

// Check out my general comments (that are the same for all the functions) in the end of the file

// Function to sum the vectors (in this case, U, V and W) and return the result in a vector of vectors of floats (vector<vector<float>>)
// The function receives the three vectors and the size of the vectors
vector<vector<float>> somaVetores(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho){
    vector<vector<float>> vetorResultado;
    vector<float> vetorAux(tamanho);
    // Sum vector U and V
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] + vetor2[i];
    }
    vetorResultado.push_back(vetorAux);
    // Sum vector U and W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] + vetor3[i];
    }
    vetorResultado.push_back(vetorAux);
    // Sum vector V and W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor2[i] + vetor3[i];
    }
    // Push the results of the sums into the vector of vectors
    vetorResultado.push_back(vetorAux);

    // Return the vector of vectors with the results of the sums to the caller
    return vetorResultado;
}

// Function to subtract the vectors (in this case, U, V and W) and return the result in a vector of vectors of floats (vector<vector<float>>)
// The function receives the three vectors and the size of the vectors
// Instead of performing the subtraction of the vectors in the same loop, I separated them into three different loops and pushed them into the vector of vectors by the end
// of each loop, so the results are more organized.
vector<vector<float>> subtracaoVetores(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho){
    vector<vector<float>> vetorResultado;
    vector<float> vetorAux(tamanho);
    // Subtraction vector U and V
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] - vetor2[i];
    }
    // Push the results of the subtractions into the vector of vectors
    vetorResultado.push_back(vetorAux);
    // Subtraction vector U and W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor1[i] - vetor3[i];
    }
    // Push the results of the subtractions into the vector of vectors
    vetorResultado.push_back(vetorAux);
    // Subtração vetor V e W
    for(int i = 0; i < tamanho; i++){
        vetorAux.at(i) = vetor2[i] - vetor3[i];
    }
    // Push the results of the subtractions into the vector of vectors
    vetorResultado.push_back(vetorAux);

    // Return the vector of vectors with the results of the subtractions to the caller
    return vetorResultado;
}

// Function to multiply the vectors (in this case, U, V and W) by a constant and return the result in a vector of vectors of floats (vector<vector<float>>)
// The function receives the three vectors, the constant and the size of the vectors
vector<vector<float>> multiplicacaoConstante(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, float constante, int tamanho){
    vector<vector<float>> vetorResultado(tamanho);
    vector<float> vetorAux1(tamanho);
    vector<float> vetorAux2(tamanho);
    vector<float> vetorAux3(tamanho);
    for(int i = 0; i < tamanho; i++){
        vetorAux1.at(i) = vetor1[i] * constante;
        vetorAux2.at(i) = vetor2[i] * constante;
        vetorAux3.at(i) = vetor3[i] * constante;
    }
    // Push the results of the multiplications into the vector of vectors
    vetorResultado.push_back(vetorAux1);
    vetorResultado.push_back(vetorAux2);
    vetorResultado.push_back(vetorAux3);

    // Return the vector of vectors with the results of the multiplications to the caller
    return vetorResultado;
}

// Function to calculate the module of the vectors (in this case, U, V and W) and return the result in a vector of vectors of floats (vector<vector<float>>)
// The function receives the three vectors and the size of the vectors
vector<vector<float>> moduloVetor(vector<float> vetorU, vector<float> vetorV, vector<float> vetorW, int tamanho) {
    vector<vector<float>> vetorResultado(tamanho);
    // Create an auxiliary vector to store the sum of the squares of the components of the vectors
    vector<double> vetorAux1(tamanho);
    // Calculate the sum of the squares of the components of the vectors
    for(int i = 0; i < tamanho; i++){
        vetorAux1[0] += pow(vetorU[i], 2);
        vetorAux1[1] += pow(vetorV[i], 2);
        vetorAux1[2] += pow(vetorW[i], 2);
    }
    // Calculate the module of the vectors and push them into the vector of vectors
    vetorResultado.at(0).push_back((float)sqrt(vetorAux1.at(0)));
    vetorResultado.at(1).push_back((float)sqrt(vetorAux1.at(1)));
    vetorResultado.at(2).push_back((float)sqrt(vetorAux1.at(2)));
    // Return the vector of vectors with the results of the modules to the caller
    return vetorResultado;
}
// Function to calculate the scalar product of the vectors (in this case, U, V and W) and return the result in a vector of vectors of floats (vector<vector<float>>)
// The function receives the three vectors and the size of the vectors
vector<float> produtoEscalar(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho) {
    // Create a vector to store the scalar products (no need for a vector of vectors)
    vector<float> vetorResultado(3);  // Store 3 scalar products: U dot V, U dot W, V dot W

    // Calculate the scalar products directly into vetorResultado
    for (int i = 0; i < tamanho; i++) {
        vetorResultado.at(0) += vetor1.at(i) * vetor2.at(i);  // U dot V
        vetorResultado.at(1) += vetor1.at(i) * vetor3.at(i);  // U dot W
        vetorResultado.at(2) += vetor2.at(i) * vetor3.at(i);  // V dot W
    }

    // Return the vector containing the scalar products
    return vetorResultado;
}

vector<long double> anguloEntreVetores(vector<float> vetorU, vector<float> vetorV, vector<float> vetorW, int tamanho) {
    // Create a vector to store the angles (U-V, U-W, V-W)
    long double resultado = 0, resultadoProdutoEscalar = 0, resultadoModuloVezes = 0;
    vector<long double> angulos(3);

    resultadoProdutoEscalar = (vetorU[0]*vetorV[0])+(vetorU[1]*vetorV[1])+(vetorU[2]*vetorV[2]);
    resultadoModuloVezes = (sqrt(pow(vetorU[0],2)+pow(vetorU[1],2)+pow(vetorU[2],2)));
    resultadoModuloVezes *= (sqrt(pow(vetorV[0],2)+pow(vetorV[1],2)+pow(vetorV[2],2)));
    resultado = resultadoProdutoEscalar/resultadoModuloVezes;
    resultado = acos(resultado)*180/M_PI;
    angulos.at(0) = resultado;

    resultadoProdutoEscalar = (vetorU[0]*vetorW[0])+(vetorU[1]*vetorW[1])+(vetorU[2]*vetorW[2]);
    resultadoModuloVezes = (sqrt(pow(vetorU[0],2)+pow(vetorU[1],2)+pow(vetorU[2],2)));
    resultadoModuloVezes *= (sqrt(pow(vetorW[0],2)+pow(vetorW[1],2)+pow(vetorW[2],2)));
    resultado = resultadoProdutoEscalar/resultadoModuloVezes;
    resultado = acos(resultado)*180/M_PI;
    angulos.at(1) = resultado;

    resultadoProdutoEscalar = (vetorV[0]*vetorW[0])+(vetorV[1]*vetorW[1])+(vetorV[2]*vetorW[2]);
    resultadoModuloVezes = (sqrt(pow(vetorV[0],2)+pow(vetorV[1],2)+pow(vetorV[2],2)));
    resultadoModuloVezes *= (sqrt(pow(vetorW[0],2)+pow(vetorW[1],2)+pow(vetorW[2],2)));
    resultado = resultadoProdutoEscalar/resultadoModuloVezes;
    resultado = acos(resultado)*180/M_PI;
    angulos.at(2) = resultado;

    return angulos;
}
// Function to calculate the vector product of the vectors
vector<vector<float>> produtoVetorial(vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho) {
    // Create a vector of vectors to store the results of the vector products
    vector<vector<float>> vetorResultado(3, vector<float>(3));  // Initialize with size 3x3

    // Calculate vector products directly into the result vector
    vetorResultado[0][0] = vetor1[1] * vetor2[2] - vetor1[2] * vetor2[1];
    vetorResultado[0][1] = vetor1[2] * vetor2[0] - vetor1[0] * vetor2[2];
    vetorResultado[0][2] = vetor1[0] * vetor2[1] - vetor1[1] * vetor2[0];

    vetorResultado[1][0] = vetor1[1] * vetor3[2] - vetor1[2] * vetor3[1];
    vetorResultado[1][1] = vetor1[2] * vetor3[0] - vetor1[0] * vetor3[2];
    vetorResultado[1][2] = vetor1[0] * vetor3[1] - vetor1[1] * vetor3[0];

    vetorResultado[2][0] = vetor2[1] * vetor3[2] - vetor2[2] * vetor3[1];
    vetorResultado[2][1] = vetor2[2] * vetor3[0] - vetor2[0] * vetor3[2];
    vetorResultado[2][2] = vetor2[0] * vetor3[1] - vetor2[1] * vetor3[0];

    // No need to push anything back since the results are directly placed

    return vetorResultado;
}
// Function to calculate the mixed product of the vectors
double produtoMisto (vector<float> vetor1, vector<float> vetor2, vector<float> vetor3, int tamanho) {
    // Calculate the mixed product directly
    double resultado;
    resultado = vetor1[0] * (vetor2[1] * vetor3[2] - vetor2[2] * vetor3[1]) - vetor1[1] *
                (vetor2[0] * vetor3[2] - vetor2[2] * vetor3[0]) + vetor1[2] *
                (vetor2[0] * vetor3[1] - vetor2[1] * vetor3[0]);
    return resultado;
}

// You can adapt the function to receive any number of vectors by changing the parameters from 3 defined vectors to
// a vector of vectors (or any other way you prefer)
// This way, you can use the same function to calculate the sum of any number of vectors
// This header file was originally created to be used in the main.cpp file, so if you want to use it in another file,
// you should include the vector library in the file you want to use it and adapt to your code
// I hope this helps you to understand the code and adapt it to your needs
// If you have any questions, feel free to ask me
// I hope you have a great day! :)
// Best regards,
// Henry Frungilo
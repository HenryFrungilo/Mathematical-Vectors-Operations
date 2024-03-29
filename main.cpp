#include <iostream>
#include <vector>
#include "operacoesVetores.h"
// Yes, I created a header file for this program :D

using namespace std;

// Function prototypes to be used in the main function
void selecaoDeOperacao();
vector<float> leituraVetores(int );

// Variables used in the main function as options for the switch case and to continue running the program;
short int opcao;
char continuar;

// Constants used in the main function, since my Professor asked for the vectors to have a size of 3, I used a constant for that
const int tamanho = 3;
// Constant used in the multiplication of the vectors by a constant
float constante = 0;
// Initialization of the vectors used to perform the operations
vector<float> vetorU;
vector<float> vetorV;
vector<float> vetorW;

// Main function
int main() {
    // Welcome message
    cout << " -------------------------------------------- " << endl;
    cout << " |Bem vindo ao Programa de Calculo de Vetor! |" << endl;
    cout << " -------------------------------------------- " << endl;
    // Reading the vectors
    // I also should have used a function to read the vectors, but I didn't did it because my Professor asked 3 vectors of size 3
    cout << "Insira o Vetor U" << endl;
    // Reading the vector
    vetorU = leituraVetores(tamanho);
    cout << "Insira o Vetor V" << endl;
    // Reading the vector
    vetorV = leituraVetores(tamanho);
    cout << "Insira o Vetor W" << endl;
    // Reading the vectors
    vetorW = leituraVetores(tamanho);
    // Function to select the operation to be performed, it will keep running until the user decides to exit the program via recursion
    selecaoDeOperacao();
    return 0;
}

vector<float> leituraVetores(int tamanhoVetor){
    vector<float> vetor;
    for(int i = 0; i < tamanhoVetor; i++){
        cout << "Insira o valor do elemento na posicao " << i + 1 << ": ";
        float valor;
        cin >> valor;
        vetor.push_back(valor);
    }
    return vetor;
}

void selecaoDeOperacao() {
    // Initialization of the variable that will store the result of the operations returned by the functions from the operacoesVetores.h file
    vector<vector<float>> resultado(3);
    vector<float> resultadoVetorFloatUnico(3);
    vector<double> resultadoVetorDouble(3);
    vector<long double> resultadoVetorLongDouble(3);
    float resultadoFloat;
    double resultadoDouble;

    // Clear the console
    system("CLS");
    // Display the menu
    cout << " ----------------------------------" << endl;
    cout << "| Qual operação deseja executar?  |" << endl;
    cout << "| 1 - Soma de Vetores             |" << endl;
    cout << "| 2 - Subtracao de Vetores        |" << endl;
    cout << "| 3 - Multiplicacao Constante     |" << endl;
    cout << "| 4 - Modulo de Vetores           |" << endl;
    cout << "| 5 - Produto Escalar de Vetores  |" << endl;
    cout << "| 6 - Angulo entre Vetores        |" << endl;
    cout << "| 7 - Produto Vetorial            |" << endl;
    cout << "| 8 - Produto Misto               |" << endl;
    cout << "| 0 - Sair                        |" << endl;
    cout << " ----------------------------------" << endl;
    // Read the user input
    cin >> opcao;
    // Switch case to select the operation to be performed
    switch (opcao) {
        case 1:
            // Author: Henry Frungilo
            // Implementation of the somaVetores function, which receives three vectors and the size of the vectors as parameters
            // and returns a vector of vectors with the sum of each pair of vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // [[5, 7, 9], [8, 10, 12], [11, 13, 15]]
            // for somaVetores documentation, check operacoesVetores.h
            resultado = somaVetores(vetorU, vetorV, vetorW, tamanho);
            cout << "A soma dos vetores é:" << endl;
            for(int i = 0; i < resultado.size(); i++){
                if (i == 0){
                    cout << "U + V = ";
                } else if (i == 1){
                    cout << "U + W = ";
                } else {
                    cout << "V + W = ";
                }
                for(float j : resultado[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << "Deseja Realizar Mais Operacoes?" << endl;
            cin >> continuar;
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 2:
            // Author: Henry Frungilo
            // Implementation of the subtracaoVetores function, which receives three vectors and the size of the vectors as parameters
            // and returns a vector of vectors with the subtraction of each pair of vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // [[-3, -3, -3], [-6, -6, -6], [-3, -3, -3]]
            // for subtracaoVetores documentation, check operacoesVetores.h
            resultado = subtracaoVetores(vetorU, vetorV, vetorW, tamanho);
            cout << "A subtracao dos vetores é:" << endl;
            for(int i = 0; i < resultado.size(); i++){
                if (i == 0){
                    cout << "U - V = ";
                } else if (i == 1){
                    cout << "U - W = ";
                } else {
                    cout << "V - W = ";
                }
                for(float j : resultado[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar Mais Operacoes?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                // Recursive call to the function to select the operation to be performed
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 3:
            cout << "Qual a constante que deseja multiplicar os vetores?" << endl;
            cin >> constante;
            // Author: Henry
            // Implementation of the multiplicacaoConstante function, which receives three vectors, a constant and the size of the vectors as parameters
            // and returns a vector of vectors with the multiplication of each vector by the constant.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // constante = 2
            // the output should be:
            // [[2, 4, 6], [8, 10, 12], [14, 16, 18]]
            // for multiplicacaoConstante documentation, check operacoesVetores.h
            resultado = multiplicacaoConstante(vetorU, vetorV, vetorW, constante, tamanho);
            cout << "A multiplicacao dos vetores pela constante " << constante << " é " << endl;
            for(int i = 0; i < resultado.size(); i++){
                if (i == 0){
                    cout << "U * " << constante << " = ";
                } else if (i == 1){
                    cout << "V * " << constante << " = ";
                } else {
                    cout << "W * " << constante << " = ";
                }
                for(float j : resultado[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 4:
            cout << "Módulo de Vetores" << endl;
            // Author: Henry Frungilo
            // Implementation of the moduloVetor function, which receives three vectors and the size of the vectors as parameters
            // and returns a vector of vectors with the module of each vector.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // [[3.74166], [8.77496], [13.9284]]
            // for moduloVetor documentation, check operacoesVetores.h
            resultado = moduloVetor(vetorU, vetorV, vetorW, tamanho);
            cout << "O módulo dos vetores é:" << endl;
            for(int i = 0; i < resultado.size(); i++){
                if (i == 0){
                    cout << "Modulo U = ";
                } else if (i == 1){
                    cout << "Modulo V = ";
                } else {
                    cout << "Modulo W = ";
                }
                for(float j : resultado[i]){
                    cout << j << " ";
                }
            }
            cout << endl;
            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 5:
            cout << "Produto Escalar de Vetores" << endl;
            // Author: Henry Frungilo
            // Implementation of the produtoEscalar function, which receives three vectors and the size of the vectors as parameters
            // and returns a vector of vectors with the scalar product of each pair of vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // [[32], [50], [122]]
            // for produtoEscalar documentation, check operacoesVetores.h
            resultadoVetorFloatUnico = produtoEscalar(vetorU, vetorV, vetorW, tamanho);
            cout << "Produto Escalar de Vetores:" << endl;
            cout << "U * V = " << resultadoVetorFloatUnico[0] << endl;
            cout << "U * W = " << resultadoVetorFloatUnico[1] << endl;
            cout << "V * W = " << resultadoVetorFloatUnico[2] << endl;
            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 6:
            cout << "Ângulo entre Vetores" << endl;
            // Author: Henry Frungilo
            // Implementation of the anguloEntreVetores function, which receives three vectors and the size of the vectors as parameters
            // and returns a long double vector with the angle between each pair of vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // 12.9332, 16.3801, 3.44695
            // for anguloEntreVetores documentation, check operacoesVetores.h
            resultadoVetorLongDouble = anguloEntreVetores(vetorU, vetorV, vetorW, tamanho);
            cout << "O ângulo entre os vetores é:" << endl;
                    cout << "Ângulo entre U e V = " << resultadoVetorLongDouble[0] << endl;
                    cout << "Ângulo entre U e W = " << resultadoVetorLongDouble[1] << endl;
                    cout << "Ângulo entre V e W = " << resultadoVetorLongDouble[2] << endl;

            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 7:
            cout << "Realizando o Produto Vetorial" << endl;
            // Author: Henry Frungilo
            // Implementation of the produtoVetorial function, which receives three vectors and the size of the vectors as parameters
            // and returns a vector of vectors with the vector product of each pair of vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // [[-3, 6, -3], [-3, 6, -3], [-3, 6, -3]]
            // for produtoVetorial documentation, check operacoesVetores.h
            resultado = produtoVetorial(vetorU, vetorV, vetorW, tamanho);
            cout << "O produto vetorial dos vetores é:" << endl;
            for(int i = 0; i < resultado.size(); i++){
                if (i == 0){
                    cout << "U x V = ";
                } else if (i == 1){
                    cout << "U x W = ";
                } else {
                    cout << "V x W = ";
                }
                for(float j : resultado[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
            // Asks the user if he wants to perform more operations (I could have made a function to do this, but I didn't (man, I'm lazy asf and I need to refactor this code))
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program (read my declaration about this at the end of the file)
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 8:
            cout << "Realizando o Produto Misto" << endl;
            cin.ignore();
            // Author: Henry
            // Implementation of the produtoMisto function, which receives three vectors and the size of the vectors as parameters
            // and returns a double with the mixed product of the three vectors.
            // for example, if the input is:
            // vetorU = [1, 2, 3]
            // vetorV = [4, 5, 6]
            // vetorW = [7, 8, 9]
            // the output should be:
            // 0
            resultadoDouble = produtoMisto(vetorU, vetorV, vetorW, tamanho);
            cout << "O produto misto dos vetores é:" << endl;
            cout << "U . (V x W) = " << resultadoDouble << endl;
            // Asks the user if he wants to perform more operations
            cout << "Deseja Realizar mais Operações?" << endl;
            cin >> continuar;
            // If the user wants to perform more operations, the function will be called again
            if(continuar == 's'){
                selecaoDeOperacao();
            } else {
                // If not
                // Ends the program ( I'm tired of writing this comment over and over again, so I'm just going to copy and paste it)
                cout << "Programa encerrado!" << endl;
            }
            break;
        case 0:
            // User selected to exit the program, so the program will display a message and end.
            cout << "Programa encerrado!" << endl;
            break;
        default:
            // If the user inputs an invalid option, the program will ask for a valid one until the user input is a valid one.
            cout << "Selecione uma opção válida!" << endl;
            selecaoDeOperacao();
            break;
    }
}
/*
 *
 * Probably you are wondering why I didn't make a function to display the message "Deseja Realizar mais Operações?" and the message "Programa encerrado!".
 * And it is a good question.
 * I could have made a function to display these messages, but I didn't because I was lazy and I didn't want to refactor the code.
 * I'm sorry for that, but I hope you understand and no, I will not refactor this code by now :D
 *
 * DISCLAIMER: This file DO NOT contain any functions that operate on vectors, the functions that operate on vectors are in the operacoesVetores.h file
 *      In case you want to contact me, you can reach me at my GitHub profile (which is where you probably got this code from) or at my LinkedIn profile, both are linked in my GitHub profile.
 *      It is not for commercial use, it is for educational purposes only.
 *      Also, it is not for scientific use, since I didn't use the double type in my variables since it could make it heavier.
 *      I'm currently looking for a job, so if you have any opportunities, please let me know! :D
 *
 * I hope you enjoyed my code, I tried to make it as clean as possible, but I'm still learning, so I'm open to suggestions and feedback.
 * I also hope you have a great day! :D
 * PS: I'm sorry for the long comment, I just wanted to explain some things about the code and the decisions I made.
 * PS2: I also added some comments to the code, explaining what each part does, that are the same comments from operacoesVetores.h file
 * I hope you don't mind it. :D
 * Originally made for a University assignment, but I decided to make it better and more readable.
 * Cheers! :D
 * Author: Henry Frungilo
 */
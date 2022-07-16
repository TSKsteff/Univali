#include <iostream>

using namespace std;

// trabalho feito por Mateus Mello de Liz, Steff Kerry Toussaint , Diogo , Lukas

int main()
{
    long long int num, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, somatorio, divisao, soma1, multiplicacao, verificador;

    //verificacao de digitos
    cout << "Digite um numero de 13 digitos: " << endl;
    cin >> num;
    if(num >= 1000000000000 && num <= 9999999999999){
        cout << "Quantidade de digitos correto" << endl;

        //separacao dos digitos
        d12 = num / 1000000000000;
        d11 = num % 1000000000000 / 100000000000;
        d10 = num % 100000000000 / 10000000000;
        d9 = num % 10000000000 / 1000000000;
        d8 = num % 1000000000 / 100000000;
        d7 = num % 100000000 / 10000000;
        d6 = num % 10000000 / 1000000;
        d5 = num % 1000000 / 100000;
        d4 = num % 100000 / 10000;
        d3 = num % 10000 / 1000;
        d2 = num % 1000 / 100;
        d1 = num % 100 / 10;
        d0 = num % 10;

        // Distribua os 12 primeiros dígitos em um quadro (multiplicando os dígitos impares por 3)
        d11 = d11 * 3;
        d9 = d9 * 3;
        d7 = d7 * 3;
        d5 = d5 * 3;
        d3 = d3 * 3;
        d1 = d1 * 3;

        // Calcule o somatório dos resultados
        somatorio = d12 + d11 + d10 + d9 + d8 + d7 + d6 + d5 + d4 + d3 + d2 + d1;

        // O resultado obtido será divido por 10
        divisao = somatorio / 10;

        // Soma-se 1 ao resultado obtido
        soma1 = divisao + 1;

        // Multiplica-se o resultado obtido por 10.
        multiplicacao = soma1 * 10;

        //Para obter o dígito verificador, subtraia o resultado da linha 55 com o do resultado da linha 46
        verificador = multiplicacao - somatorio;

        //Caso o resultado do dígito verificador tenha dado um resultado que for múltiplo de 10, basta substituí-lo por zero
        if(verificador % 10 == 0){
            verificador = 0;
        }

        //verificacao do codigo verificador
        if(d0 == verificador){
            cout << "Codigo verificador consistente. Codigo verificador: " << verificador << endl;
        }
        else{
            cout << "Codigo verificador inconsistente. Codigo verificador deveria ser: " << verificador << endl;
        }
    }
    else{
        cout << "Quantidade de digitos incorreto." << endl;
    }
    return 0;
}


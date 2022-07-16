#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{

   setlocale(LC_ALL, "portuguese");

///   _______Apresentaçao do Jogo________/

    cout << " ____________";
    cout << " \n\n";
    cout << " BEM VINDO!! | JOGO DA MEMORIA| "<< endl;
    cout << " ____________" << endl;
    system("pause");
    system("cls");

///_________ DECLARAÇÕES DE VARIAVEIS___________/

    int mtr[4][4]={1,4,5,2, /// MATRIZ PRINCIPAL
                   7,2,8,7,
                   3,6,1,4,
                   6,5,3,8};

    int mtr1[4][4] = {0}; /// MATRIZ QUE ARMAZENARA A NOSSA MATRIZ PRINCIPAL TRANSPOSTA, INVERTIDA POR LINHA OU COLUNA

    int mtr2[4][4] = {0}; /// MATRIZ DE EXPOSIÇÃO

    int linha1, coluna1, linha2,coluna2;
    int escolha1, escolha2;
    int total=1, fim=0;
    int num=0, k=3;
    int tnva=24, jogadas=0, pontos=0;
    int err=0;

    ///_______ Rand para escolher aleatoriamente qual matriz montar o jogo______/

 srand(time(NULL));
 num=rand()%3;

 switch(num){
case 0:for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
                mtr[i][j];
            mtr1[i][j]=mtr[j][i];}
    }
    break;
case 1: for(int j=0;j<4;j++){
                for(int i=0;i<4;i++){
                    mtr1[i][j]=mtr[i][k];
                }
                k--;}
    break;
case 2:for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            mtr[i][j];
            mtr1[i][j]=mtr[k][j];
        }
        k--;}
     break;
}

///_____ INICIO DO JOGO______


cout << " |X| |X| |X| |X| \n |X| |X| |X| |X| \n |X| |X| |X| |X| \n |X| |X| |X| |X|" << endl;

while(total<=24){

  cout << "ESCOLHE UMA LINHA & CORDENADA DE |0 a 3|  : " << endl;
     cin >> linha1>>coluna1;

            while(linha1 > 3 || linha1 < 0 || coluna1 > 3 || coluna1 < 0 || mtr2[linha1][coluna1]!=0){
                cout << "ESCOLHE UMA LINHA & CORDENADA VALIDA DE|0 a 3| : " << endl;
                    cin >> linha1>>coluna1;
            }

   for (int i=0; i<4; i++){
     for (int j=0; j<4; j++){
        if (i==linha1 && j==coluna1){
            cout <<"|"<<mtr1[i][j]<<"|";
                    linha1=i;
                    coluna1=j;
                    escolha1=mtr1[i][j];
        }else{ cout << "|x|";
        }
    }
    cout << endl;
  }

cout << escolha1;

 cout << "\n ESCOLHE OUTRA LINHA & CORDENADA |0 a 3|  : " << endl;
    cin>>linha2>>coluna2;

            while(linha2 > 3 || linha2 < 0 || coluna2 > 3 || coluna2 < 0 || mtr2[linha2][coluna2]!=0){
                cout << "ESCOLHE OUTRA LINHA & CORDENADA VALIDA DE|0 a 3| : " << endl;
                   cin >> linha2>>coluna2;
            }

            while(linha1 == linha2 && coluna1 == coluna2){
                cout << "CORDENADA JA FOI ESCOLINHO ANTERIORMENTE, ESCOLHE OUTRA LINHA & CORDENADA VALIDA DE|0 a 3| :  " << endl;
                   cin >> linha2>>coluna2;
             }

   for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==linha2 && j==coluna2){
                cout << "|"<<mtr1[i][j]<<"|";
                escolha2=mtr1[i][j];
            }
            else if(linha1==i && coluna1==j){
                cout << "|"<<mtr1[linha1][coluna1]<<"|";
            }else{cout<<"|x|";
        }
        }cout<<endl;
   }

        tnva = tnva - 1;
        jogadas+=1;
   if (escolha1 == escolha2){
       pontos+=1;
        cout << total <<"º TENTIVA"<< endl;
    cout << "JOGADA OK!!\n FALTAM " << tnva << " TENTAVAS "<<endl;

        system("pause");
        system("cls");

      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (mtr1[i][j]==escolha1){
                cout << "|"<<mtr1[i][j]<<"|";
                mtr2[i][j]=mtr1[i][j];

            }else if(mtr1[i][j] == escolha2){

                cout << "|"<<mtr1[i][j];
                mtr2[i][j]=mtr1[i][j];

            }else{cout<<"|x|";
        }
        }cout<<endl;
     }
    system("cls");

   }else if (escolha1 != escolha2){
       err+=1;
       cout << total <<"º TENTIVA"<< endl;
       cout << " JOGADA NOK\n TENTE DE NOVO"<<endl;
       cout << "FALTAM " <<tnva << " JOGADAS"<< endl;
        system("pause");
        system("cls");
   }

           for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){

                    if(mtr2[i][j]==0){
                        cout<<"|X|";
                    }else {
                        cout<<"|"<<mtr2[i][j]<<"|";
                    }
                }
                cout<<endl;
            }

   total++;
 }
 if(pontos==8){
        cout << "PARABENS VOCE VENCEUU!!!"<<endl;
        cout << "JOGO CONCLUIDO"<< endl;
        cout << "TENTATIVAS = " <<jogadas<<endl;
        cout << "ACERTOS = " << pontos << endl;
        cout << "ERROS = " << err <<endl;
 }else if (pontos<8 || pontos ==0){
        cout << "NÃO FOI DESSA VEZ| GAME OVER" <<endl;
        cout << "JOGO CONCLUIDO"<< endl;
        cout << "TENTATIVAS = " <<jogadas<<endl;
        cout << "ACERTOS = " << pontos << endl;
        cout << "ERROS = " << err <<endl;

 }
  string nv;
 cout << " QUER JOGAR NOVAMENTE, DIGITE 'S' | 'N' "<<endl;
 cin >> nv;
 if (nv=="s"){
      system("cls");
    return main();

 }else if (nv=="n"){
     return 0;
 }
    return 0;
}

//Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h> ///para gerar random
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: n�o permitido o uso de fun��es e vari�veis compostas como structs, vetores e matrizes
    - Corrigir os rastros (p�ssaro e obst�culos)
    - Implementar colis�o
    - Implementar pontua��o (mais um ponto para cada obst�culo superado)
    - Fazer 2 obst�culos simult�neos (obstaculo1 e obstaculo2)
    - Deixar a pontua��o vis�vel durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord, coorda, coordi;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.



    int rand1, rand2;
    int bird_x=5, bird_y=10;
    int obstaculo_x=30, obstaculo_y;
    int obstaculo2_x=60, obstaculo2_y;
    int tecla;
    int pontos = 0;
    int limpa_x = 1;
    int atras_x = 1, atras_y;
    int velocidade = 0;
    int dificuldade = 6; ///dificuldade+1 S�O OS ESPA�OS ABERTOS;

    ///DESENHO DO CEN�RIO
    cout<<"-----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------";


    ///RANDOM
        srand(time(NULL));
        rand1 = rand()%20;
        rand2 = rand()%20;

   while (true) { //esse la�o faz o jogo rodar para sempre

        if(rand1 > (20-dificuldade)){
            rand1 = rand1 - dificuldade;
        }                           ///CONTROLE PARA N�O TER FALTA DE ESPA�O EM CIMA OU EM BAIXO
        if(rand2 > (20-dificuldade)){
            rand2 = rand2 - dificuldade;
        }

        ///POSICIONA O OBST�CULO
        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y<rand1 || obstaculo_y>rand1 + dificuldade){
                cout<<char(219);
            }
            else{
                cout<<" ";

            }

            obstaculo_y++;
            cout<<" ";  ///PARA DE DESENHAR MAIS OBST�CULOS
        }

        ///SEGUNDO OBST�CULO
        obstaculo2_y=1;
        while(obstaculo2_y<20){
            coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo2_y<rand2 || obstaculo2_y>rand2 + dificuldade){
                cout<<char(219);
            }
            else{
                cout<<" ";

            }

            obstaculo2_y++;
            cout<<" ";
        }

        ///POSICIONA O P�SSARO
        coord.X = bird_x;    coord.Y = bird_y;
        coorda.X = bird_x;    coorda.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        coord.X = limpa_x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<< " " ;

        ///VERIFICA COLIS�O
        if(bird_y == 0 || bird_y == 20){    ///CH�O E TETO
        coorda.X = 35;    coorda.Y = 23;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
        cout<< "GAME OVER" << endl ;
            break;

        }
        if(obstaculo_x == limpa_x){   ///OBST�CULO 1 NA MESMA COORDENADA X depois  do P�SSARO
            if(bird_y < rand1 || bird_y > rand1+dificuldade){
                coorda.X = 35;    coorda.Y = 23;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
        cout<< "GAME OVER" << endl << "Aperte R pra restart" << endl;
            break;
            }

            pontos++;
            if(pontos%5 == 0 && pontos != 0){   ///AUMENTO DA VELOCIDADE
                velocidade = velocidade + 100;
            }


                ///NOVO RANDOM OBSTACULO 1
                rand1 = rand()%20;
                obstaculo_x = obstaculo_x + 60;


        }


        if(obstaculo2_x == limpa_x){  ///OBST�CULO 2 NA MESMA COORDENADA X QUE O P�SSARO
            if(bird_y < rand2 || bird_y > rand2+dificuldade){
                coorda.X = 35;    coorda.Y = 23;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
        cout<< "GAME OVER" << endl << "Aperte R pra restart" << endl;
            break;
            }

            pontos++;
            if(pontos%5 == 0 && pontos != 0){   ///AUMENTO DA VELOCIDADE
                velocidade = velocidade + 100;
            }

                ///NOVO RANDOM OBSTACULO 2
                rand2 = rand()%20;
                obstaculo2_x = obstaculo2_x + 60;



                }




        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' ){
            bird_y--;
            tecla='0';
        } else {
            bird_y++; ///P�SSARO CAI 1 POSI��O SE N�O FOR PRESSIONADO PARA SUBIR
        }



        ///OBST�CULOS AVAN�AM UMA POSI��O PARA ESQUERDA
        obstaculo_x--;
        obstaculo2_x--;

        ///TEMPO DE ESPERA
        Sleep(500-velocidade);

        ///APAGA PASSARO ANTERIOR
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
        cout<< " ";

        ///LIMPA OBSTACULOS PASSADOS
        atras_y = 1;
        while(atras_y < 20){
            coordi.X = atras_x;   coordi.Y = atras_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordi);
            cout << " ";
            atras_y++;
        }


        ///PONTUACAO
        coorda.X = 60;    coorda.Y = 22;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
        cout<< "pontuacao: " << pontos << " e velocidade aumentada " << velocidade/100 << " vezes." << endl;

    }
    coorda.X = 60;    coorda.Y = 26;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coorda);
    string nv;
   cout << " GOTARIA DE REINICIAR O JOGO 'S'|'N' " << endl;
        cin >> nv;
        if (nv=="s"){
            system("cls");
            return main();
        }else if(nv=="n"||nv!="s"){
           return 0;
        }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct reserva{
    char nome[50];
    int ocupado;
    int numero;
};

//int criarMenuFilme();
int criarMenuPoltrona();
//void tela_inicial();
int menu_filme();
void consultarPoltrona(struct reserva poltronas[5][5]);
void criarPoltrona(struct reserva poltronas[5][5]);
void reservarPoltrona(struct reserva poltronas[5][5]);
void comprarPoltrona(struct reserva poltronas[5][5]);
void cancelarReserva(struct reserva poltronas[5][5]);
void consultarReserva(struct reserva poltronas[5][5]);
void gerarRelatorio(struct reserva poltronas[5][5]);



int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, filme;
    struct reserva poltronas[5][5];

    //tela_inicial();
    criarPoltrona(poltronas);

/*    do
    {
        opcao = criarMenuFilme();

        switch (opcao)
        {
        case 1:

            reservarCadeiras(cadeiras);
            break;

        case 2:
        {
            comprarCadeiras(cadeiras);
            break;
        }
        case 3:
        {
            consultarCadeiras(cadeiras);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
            printf("Opção Inválida");
            break;
        }
    }

    while (opcao != 0);*/

    do
    {
        opcao = criarMenuPoltrona();

        switch (opcao)
        {
        case 1:

            reservarPoltrona(poltronas);
            break;

        case 2:
        {
            comprarPoltrona(poltronas);
            break;
        }
        case 3:
        {
            consultarPoltrona(poltronas);
            break;
        }
        case 4:
        {
            cancelarReserva(poltronas);
            break;
        }
        case 5:
        {
            gerarRelatorio(poltronas);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
            printf("\nOpção Inválida\n");
            break;
        }
    }

    while (opcao != 0);

    getch();

    return 0;
}

/*void tela_inicial(){
    printf("                                                                                \n                                                                                \n         ^JGB#BG5: !GGP. ^GGGP:  ^GGJ  7GGGBBB5  YGGGY   7GGGG^   .5GGG5        \n       .5@@#YJYG5. G@@5  Y@@@@Y  5@@! .#@@PJJY! ^@@@@B  7@@@@B   .G@&#@&:       \n       P@@G.      ~@@@^ :&@GP@@~:&@B  7@@@5YY!  Y@&G@G !@#G@@7  .G@&^5@@~       \n      :@@@~       5@@P  J@@?^@@GJ@@?  G@@GPGG~ :&@BJ@G!@&7#@B. :B@@Y^P@@7       \n      .&@@5^^^7: ^@@@~ .#@&: Y@@@@#. ~@@@!^^^  J@@??@&@@~J@@? ^#@@&&&@@@Y       \n       ~G&@@@@&^ J@@G  7@@Y  .#@@@J  P@@@&@@5 .B@#.J@@&~.#@#.^#@&7...?@@P       \n         :^~^:.  :^^.  :^^.   :^^^.  :^^^^^^. .^^: .^^: .^^: :^^:    .^^:       \n                                                                                \n                                                                                \n");
    printf("\nBem-vindo(a)!\nPressione qualquer tecla para continuar...");
}*/

/*int criarMenuFilme(){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CINEMA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~ Escolha um dos filmes em cartaz: ~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n~~~~~ Minions ~~~~~\n");
    printf("                                                  \n                .::^^~~^:::^^~~^:::.              \n              ^~^~?J??77~~^~!!7?!~^^^.            \n             ~!!!~^.    ..::::....^!~~:           \n            :J!:     .~!777!!7777~. ^J!           \n           ^J:      ~?~!~:.   .^!!7! :Y:          \n          .5^:^^^~!7J.?:         7~?! ^Y          \n          7?::::.^??^^7:~!^!!!~!^~J:Y:^5!         \n          Y7^~~~~~???.?. ~!J5?!: !~7J^^7Y         \n          Y^        77^!^......:!!!7 ..:5.        \n          J~         :!!!!!~~!!77!^     5:        \n          J^           .:^~~~~^:.       5:        \n          Y:                            Y:        \n         .P~:.             ....         5.        \n         ~Y:^~~^:.      ..::::::.     :75         \n         J^^~~::^~!!~:^^^^^^^^^^^::^~~^^5         \n        ?! .::~!~^7Y^............::7J7~^5:        \n       7?  ?.   !7!7    .::::::::   !?^ ?7        \n      ^5  ~7    :7      . .......    !. :G.       \n      J~  J~..  .?     .~        ^   ?...BJ       \n      5.  Y:.:!:^?      ~^::..::~^   ?^:!YY:      \n      5. .5^^~!:7:       .::::::.    ~^^5.77      \n      J?~!5!..::                     :J55~??^     \n      !!  :JY!^^::.   .......   .:^!777?^  ~?     \n      ^J  ^7J7.^^J!   ..JJY:.   ~5^: ^Y7~  7~     \n       J^ ::~J   :J~^^^^Y~Y^:^^^J^   ?!:: :J.     \n       .~!7~^.   .Y!^~~7Y ?J~~^~Y:    ^~7!!.      \n                 :J!7777^ :?777!J^                \n                   .          ..                  \n");
    printf("\nSessão única\nPara selecionar essa sessão digite '1'.\n");
    printf("\n~~~~~ Bob Esponja: O filme ~~~~~\n");
    printf("                                                  \n            .^^^:....                             \n           :7::^~^^^~!~^~~~~^:::.                 \n           7!. . ^  :......::::^~~~^^~^:..        \n          .J:...:J::?^^~  :  .     ..:^::7?.      \n          ?^.:^:.    .~~.^?:^J:^^  ....:!^^!^     \n         .J  ~.  :!Y!..~^.    .7~   . ^!:  .!!.   \n         .Y.^^:. ^7P7:~  :7P7:  ~:    7..... !7   \n         !~.7: :^:.  .~  :!Y!.  ~:  ^!: ..  ?!.   \n        :7  .!!^.:::^:^^.      .~   !  .:::?!     \n        ^?   ^!~^^::.  .:::::~^ . .~~..  ~?^      \n        :? ... :?~^~^^:^^^~~^7:  .!:: :..Y.       \n        ~^.. :  7~^77~:7^   ~:   ^^ ...~J^        \n        !7 ...  !~::^~^~..:!:...^~ .^: J.         \n       .Y? ...  !!~::^~^~?!. ...!   ..!J          \n       !JY~:::.:.^^^^^^^^. . ..:! ^!~~J           \n       .^Y!..^777?Y?!~^^:  . ..! .?..5!           \n         !!!7!:~~^PBY~!~!~~~^:~!:?^  ?:           \n        .??~77.~?Y^ ???~:^^^::?^:^??Y?            \n        !~^~?^Y!~7?77!!: 7?JY^7.:JY?Y!            \n        7777? ~~?7?!^^^~J!~~~^J:^~?!7.            \n         :~^^   ~!7     ~~?7J?~::~^ ^^            \n                :7?       ~7J  .!!::^!            \n                ^77^      :!?:   ~!7!^            \n           .?J?J&&#@7     :~!:    ..              \n           :#&@@@BBG~.7J?Y#PPB:                   \n            .7J?~    J@#&@@&@B.                   \n                     :?YJ7:::.                    \n                                                  \n");
    printf("\nSessão única\nPara selecionar essa sessão digite '2'.\n");
    printf("\n~~~~~ Spider-Man ~~~~~\n");
    printf("                                                  \n                                                  \n                . .            : .                \n               ~.:~            ~~ !.              \n              ?:.Y.             Y:.J.             \n             J? Y?              ~P !5             \n            ~#.^&:               #7 G!            \n            PP ?&7!7??~:..^^?77!!BP JB            \n           :@Y:~?JJ55Y#&BB&#Y55JJJ!:?@~           \n           .JPJ!^^JY?5&@@@@@P?YY~^!JPY:           \n               :?Y?!Y5J&@@@5YY!?5J^               \n            .7YJ~ !@5 J@@@@P ?@? ^J5?:            \n          7GG?:   7@J ^@@@@7 7@J   .7PGJ          \n          Y@^     ~@?  5@@B. ~@?     .&G          \n          !@^     ^@?  :#&^  ^@7     .&J          \n          .#!     .&?   :^   ~@~     ^&^          \n           J5      GJ        !&.     ?5           \n            5:     J5        ?P     .5:           \n            :7     ^G        P!     !~            \n             ::     Y~      :5     :^             \n                    .J.     ?^     .              \n                     :~    ^^                     \n                      .    .                      \n                                                  \n");
    printf("\nSessão única\nPara selecionar essa sessão digite '3'.\n");
    printf("\n### Escolha sua opção (1,2 ou 3): ###\n");
    scanf("%d", filme);
    return 0;
}*/

int criarMenuPoltrona(){

    int opcaop;

        printf("~~~~~~~~~~~~~~~~~~~~ CINEMA ~~~~~~~~~~~~~~~~~~~~\n");
        printf("1 - Reservar \n");
        printf("2 - Comprar \n");
        printf("3 - Consultar Poltronas \n");
        printf("4 - Cancelar Reserva \n");
        printf("5 - Gerar Relatório \n");
        printf("0 - Finalizar e sair \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcaop);

    return opcaop;
}

void criarPoltrona(struct reserva poltronas[5][5])
{
    int cont=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            strcpy(poltronas[i][j].nome, "VAZIO");
            poltronas[i][j].ocupado = 0;
            poltronas[i][j].numero = cont++;
        }
    }
}

void reservarPoltrona(struct reserva poltronas[5][5])
{
    int num;

    printf("informe o número da poltrona\n");
    scanf("%d", &num);
    fflush(stdin);

    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j<5 ; j++)
        {
            if (poltronas[i][j].numero == num && poltronas[i][j].ocupado == 0)
            {
                printf("Informe o nome da reserva : \n");
                gets(poltronas[i][j].nome);
                poltronas[i][j].ocupado = 1;
                printf("~~~~~~~~~~~~Poltrona[%d]~~~~~~~~~~~~\n",poltronas[i][j].numero);
                printf("Poltrona Reservada com sucesso \n");
            }
            else if(poltronas[i][j].ocupado == 1 && poltronas[i][j].numero == num)
            {
                printf("Esta poltrona já esta reservada \n");
            }
            else if(poltronas[i][j].ocupado == 2 && poltronas[i][j].numero == num)
            {
                printf("Esta poltrona já foi comprada \n");
            }
        }
    }
}

void comprarPoltrona(struct reserva poltronas[5][5])
{
    int num;
    char nome[50];

    printf("Informe o número\n");
    scanf("%d", &num);
    fflush(stdin);
    printf("Informe o nome da reserva\n");
    gets(nome);
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j<5 ; j++)
        {
            if (strcmp(poltronas[i][j].nome, nome) == 0 && poltronas[i][j].ocupado == 1 && poltronas[i][j].numero == num)
            {
                poltronas[i][j].ocupado = 2;
                printf("******Poltrona[%d]********\n", poltronas[i][j].numero);
                printf("Poltrona Comprada com sucesso \n");
            }
            else if(strcmp(poltronas[i][j].nome, nome) != 0 && poltronas[i][j].numero == num &&poltronas[i][j].ocupado == 0)
            {
                printf("Nome informado não corresponde ao da reserva \n");
            }
            else if(poltronas[i][j].ocupado == 0 && poltronas[i][j].numero == num)
            {
                printf("A poltrona não foi reservada \n");
            }
        }
    }
}

void consultarPoltrona(struct reserva poltronas[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (poltronas[i][j].ocupado == 0)
            {
                printf("[%d]", poltronas[i][j].numero);
            }
            if (poltronas[i][j].ocupado == 1)
            {;
                printf("[RESERVADO]");
            }
            if (poltronas[i][j].ocupado == 2)
            {
                printf("[COMPRADO]");
            }
        }
        printf("\n");
    }
}

void cancelarReserva(struct reserva poltronas[5][5])
{
    int num;
    char nome[500];
    printf("informe o qual número\n");
    scanf("%d", &num);
    fflush(stdin);
    printf("Informe o nome da reserva : \n");
    gets(nome);
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j<5 ; j++)
        {
            if (strcmp(poltronas[i][j].nome, nome) == 0 && poltronas[i][j].numero == num)
            {
                poltronas[i][j].ocupado = 0;
                strcpy(poltronas[i][j].nome, "VAZIO");
                printf("******Cadeira[%d]********\n", poltronas[i][j].numero);
                printf("Reserva Cancelada com sucesso \n");
            }
            else if((poltronas[i][j].numero == num) == 1 && (poltronas[i][j].nome, nome) == 1)
            {
                printf("nome informado nao corresponde com o da reserva \n");
            }
        }
    }
}

void gerarRelatorio(struct reserva poltronas[5][5])
{
    FILE *ponteiro_arquivo;
    ponteiro_arquivo = fopen("Relatorio.txt", "w");

    if (ponteiro_arquivo == NULL)
    {
        printf("Erro ao abrir relatorio");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (poltronas[i][j].ocupado == 0)
            {
                fprintf(ponteiro_arquivo, "[%d]", poltronas[i][j].numero);
                if (j%2)
                {
                    fprintf(ponteiro_arquivo, "\n");
                }
            }
            if (poltronas[i][j].ocupado == 1)
            {
                fprintf(ponteiro_arquivo, "[%s]", poltronas[i][j].nome);
            }
            if (poltronas[i][j].ocupado == 2)
            {
                fprintf(ponteiro_arquivo, "[%s]", poltronas[i][j].nome);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (poltronas[i][j].ocupado == 0)
            {
                fprintf(ponteiro_arquivo, "[RELATORIO RESERVA]\n", poltronas[i][j].nome);
                fprintf(ponteiro_arquivo, "[%d]",poltronas[i][j].numero);
                fprintf(ponteiro_arquivo, "[%s - F:%d C:%d]\n", poltronas[i][j].nome, i, j);
                fprintf(ponteiro_arquivo, "**************************\n");
            }
            if (poltronas[i][j].ocupado == 1)
            {

                fprintf(ponteiro_arquivo, "[RELATORIO RESERVA]\n", poltronas[i][j].nome);
                fprintf(ponteiro_arquivo, "[RESERVADO]");
                fprintf(ponteiro_arquivo, "[%s - F: %d C:%d]\n", poltronas[i][j].nome, i, j);
                fprintf(ponteiro_arquivo, "**************************\n");
            }
            if (poltronas[i][j].ocupado == 2)
            {
                fprintf(ponteiro_arquivo, "[RELATORIO RESERVA]\n", poltronas[i][j].nome);
                fprintf(ponteiro_arquivo, "[COMPRADO]");
                fprintf(ponteiro_arquivo, "[%s - F:%d C:%d]\n", poltronas[i][j].nome, i, j);
                fprintf(ponteiro_arquivo, "**************************\n");
            }
        }
    }
    fclose(ponteiro_arquivo);
}

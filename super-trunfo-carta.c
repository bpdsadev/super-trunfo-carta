#include <stdio.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

int main() {
    Carta carta1 = {"Dragao", 90, 60, 70};
    Carta carta2 = {"Fenix", 80, 75, 85};

    int opcao, atr1, atr2;

    do {
        printf("\n--- SUPER TRUNFO ---\n");
        printf("1 - Comparar um atributo\n");
        printf("2 - Comparar dois atributos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            printf("Escolha o atributo para comparar:\n");
            printf("1 - Forca\n2 - Velocidade\n3 - Inteligencia\n");
            scanf("%d", &atr1);

            if (atr1 == 1) {
                printf("%s: %d vs %s: %d\n", carta1.nome, carta1.forca, carta2.nome, carta2.forca);
                if (carta1.forca > carta2.forca)
                    printf("Vencedor: %s\n", carta1.nome);
                else if (carta1.forca < carta2.forca)
                    printf("Vencedor: %s\n", carta2.nome);
                else
                    printf("Empate!\n");

            } else if (atr1 == 2) {
                printf("%s: %d vs %s: %d\n", carta1.nome, carta1.velocidade, carta2.nome, carta2.velocidade);
                if (carta1.velocidade > carta2.velocidade)
                    printf("Vencedor: %s\n", carta1.nome);
                else if (carta1.velocidade < carta2.velocidade)
                    printf("Vencedor: %s\n", carta2.nome);
                else
                    printf("Empate!\n");

            } else if (atr1 == 3) {
                printf("%s: %d vs %s: %d\n", carta1.nome, carta1.inteligencia, carta2.nome, carta2.inteligencia);
                if (carta1.inteligencia > carta2.inteligencia)
                    printf("Vencedor: %s\n", carta1.nome);
                else if (carta1.inteligencia < carta2.inteligencia)
                    printf("Vencedor: %s\n", carta2.nome);
                else
                    printf("Empate!\n");
            } else {
                printf("Atributo invalido.\n");
            }

        } else if (opcao == 2) {
            printf("Escolha o primeiro atributo:\n");
            printf("1 - Forca\n2 - Velocidade\n3 - Inteligencia\n");
            scanf("%d", &atr1);

            printf("Escolha o segundo atributo (diferente do primeiro):\n");
            scanf("%d", &atr2);

            if(atr1 < 1 || atr1 > 3 || atr2 < 1 || atr2 > 3) {
                printf("Atributos invalidos.\n");
                continue;
            }
            if(atr1 == atr2) {
                printf("Atributos devem ser diferentes.\n");
                continue;
            }

            int val1_c1, val2_c1, val1_c2, val2_c2;

            
            if(atr1 == 1) {
                val1_c1 = carta1.forca;
                val1_c2 = carta2.forca;
            } else if (atr1 == 2) {
                val1_c1 = carta1.velocidade;
                val1_c2 = carta2.velocidade;
            } else {
                val1_c1 = carta1.inteligencia;
                val1_c2 = carta2.inteligencia;
            }

            if(atr2 == 1) {
                val2_c1 = carta1.forca;
                val2_c2 = carta2.forca;
            } else if (atr2 == 2) {
                val2_c1 = carta1.velocidade;
                val2_c2 = carta2.velocidade;
            } else {
                val2_c1 = carta1.inteligencia;
                val2_c2 = carta2.inteligencia;
            }

            int total_c1 = val1_c1 + val2_c1;
            int total_c2 = val1_c2 + val2_c2;

            printf("%s: %d + %d = %d\n", carta1.nome, val1_c1, val2_c1, total_c1);
            printf("%s: %d + %d = %d\n", carta2.nome, val1_c2, val2_c2, total_c2);

            (total_c1 > total_c2) ? printf("Vencedor: %s\n", carta1.nome) :
            (total_c1 < total_c2) ? printf("Vencedor: %s\n", carta2.nome) :
            printf("Empate!\n");

        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while(opcao != 0);

    printf("Fim do jogo.\n");
    return 0;
}

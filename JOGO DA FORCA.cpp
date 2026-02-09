#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char palavraSecreta[50];
char acertos[50];
int erros = 0;

void abertura() {
    printf("=====================================\n");
    printf("      BEM-VINDO AO JOGO DA FORCA     \n");
    printf("=====================================\n\n");
}

void escolhePalavra() {
    FILE *arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de palavras.\n");
        exit(1);
    }

    int qtd = 0;
    char linha[100];

    while (fgets(linha, 100, arquivo) != NULL) {
        qtd++;
    }

    srand(time(0));
    int num = rand() % qtd;

    rewind(arquivo);
    for (int i = 0; i <= num; i++) {
        fgets(palavraSecreta, 50, arquivo);
    }

    palavraSecreta[strcspn(palavraSecreta, "\n")] = '\0';
    fclose(arquivo);
}

void mostraPalavra() {
    printf("\nPalavra: ");
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (acertos[i] == 0) {
            printf("_ ");
        } else {
            printf("%c ", acertos[i]);
        }
    }
    printf("\nVidas: %d de 6\n\n", 6 - erros);
}

char lerLetraValida() {
    char letra;
    while (1) {
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (isalpha(letra)) {
            return tolower(letra);
        }

        printf("Entrada invalida! Digite apenas letras de A a Z.\n");
    }
}

void chute() {
    char letra = lerLetraValida();

    int existe = 0;

    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (palavraSecreta[i] == letra) {
            acertos[i] = letra;
            existe = 1;
        }
    }

    if (!existe) {
        erros++;
        printf("Letra incorreta!\n");
    } else {
        printf("Boa! A letra existe na palavra.\n");
    }
}

int ganhou() {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (acertos[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int perdeu() {
    return erros >= 6;
}

int main() {
    abertura();
    escolhePalavra();

    while (!ganhou() && !perdeu()) {
        mostraPalavra();
        chute();
    }

    if (ganhou()) {
        printf("\nParabens! Voce descobriu a palavra: %s!\n", palavraSecreta);
    } else {
        printf("\nVoce perdeu! A palavra era: %s\n", palavraSecreta);
    }

    printf("\n\n\n\n\n\n\n\nBy:\nAyran Boudoux\nKauan Wendel\n");
    printf("Rayan Lima\nSilas Amorim\nMaxwel Mota\n");
}
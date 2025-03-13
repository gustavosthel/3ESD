#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct {
    int cod;
    int tempo;
    char nome[50];
} tAtleta;

void horario(int total_min, int *h, int *m);
void DivisaoInteira(int dividendo, int divisor, int *quociente, int *resto);
void obtemAtleta(int num, tAtleta *atleta);
void ordenarPorTempoNome(tAtleta vetor[], int tamanho);

int main(void) {
    tAtleta atletas[TAM];
    int horas, minutos;

    // Leitura dos dados
    for (int i = 0; i < TAM; i++) {
        obtemAtleta(i+1, &atletas[i]);
    }

    // Ordenação
    ordenarPorTempoNome(atletas, TAM);

    // Exibição ordenada
    printf("\n=== Lista Ordenada (Tempo/Nome) ===\n");
    for (int i = 0; i < TAM; i++) {
        horario(atletas[i].tempo, &horas, &minutos);
        printf("%2d. %-20s | Cód: %3d | Tempo: %02d:%02d\n", i+1, atletas[i].nome, atletas[i].cod, horas, minutos);
    }

    // Cálculo do maior tempo
    int max_tempo = atletas[0].tempo;
    int cont_max = 1;
    for (int i = 1; i < TAM; i++) {
        if (atletas[i].tempo == max_tempo) {
            cont_max++;
        }
    }

    // Resultado final
    horario(max_tempo, &horas, &minutos);
    printf("\n=== Estatísticas ===\n");
    printf("Maior tempo: %02d:%02d\n", horas, minutos);
    printf("Atletas com esse tempo: %d\n", cont_max);

    return 0;
}

void horario(int total_min, int *h, int *m) {
    DivisaoInteira(total_min, 60, h, m);
}

void DivisaoInteira(int dividendo, int divisor, int *quociente, int *resto) {
    *quociente = dividendo / divisor;
    *resto = dividendo % divisor;
}

void obtemAtleta(int num, tAtleta *atleta) {
    printf("\n--- Atleta %d ---\n", num);
    printf("Código: ");
    scanf("%d", &atleta->cod);
    printf("Tempo (minutos): ");
    scanf("%d", &atleta->tempo);
    printf("Nome: ");
    scanf(" %49[^\n]", atleta->nome);
}

void ordenarPorTempoNome(tAtleta vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            // Primeiro ordena por tempo (decrescente)
            if (vetor[j].tempo < vetor[j + 1].tempo) {
                // Faz a troca
                tAtleta temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
            // Desempate por nome (crescente)
            else if (vetor[j].tempo == vetor[j + 1].tempo) {
                if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0) {
                    // Faz a troca
                    tAtleta temp = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = temp;
                }
            }
        }
    }
}
#include <stdio.h>
#include <string.h>
#include "UNIDADE_TEMPO.h"

#define TAM 2

typedef struct {
    int cod;
    UnidadeTempo *tempo;
    char nome[50];
} tAtleta;

void obtemAtleta(int num, tAtleta *atleta);
void ordenarPorTempoNome(tAtleta vetor[], int tamanho);

int main(void) {
    tAtleta atletas[TAM];

    for (int i = 0; i < TAM; i++) {
        obtemAtleta(i+1, &atletas[i]);
    }

    ordenarPorTempoNome(atletas, TAM);

    printf("\n=== Lista Ordenada (Tempo/Nome) ===\n");
    for (int i = 0; i < TAM; i++) {
        int h, m, s;
        ut_obter_valores(atletas[i].tempo, &h, &m, &s);
        printf("%2d. %-20s | Cód: %3d | Tempo: ", i+1, atletas[i].nome, atletas[i].cod);
        ut_exibir(atletas[i].tempo);
        printf("\n");
    }

    UnidadeTempo *maior_tempo = atletas[0].tempo;
    int cont_max = 1;
    for (int i = 1; i < TAM && ut_comparar(atletas[i].tempo, maior_tempo) == 0; i++) {
        cont_max++;
    }

    int h, m, s;
    ut_obter_valores(maior_tempo, &h, &m, &s);
    printf("\n=== Estatísticas ===\n");
    printf("Maior tempo: %02d:%02d:%02d\n", h, m, s);
    printf("Atletas com esse tempo: %d\n", cont_max);

    for (int i = 0; i < TAM; i++) {
        ut_destruir(atletas[i].tempo);
    }

    return 0;
}

void obtemAtleta(int num, tAtleta *atleta) {
    printf("\n--- Atleta %d ---\n", num);
    printf("Código: ");
    scanf("%d", &atleta->cod);
    
    int total_segundos;
    printf("Tempo total em segundos: ");
    scanf("%d", &total_segundos);
    atleta->tempo = ut_criar_de_segundos(total_segundos);
    
    printf("Nome: ");
    scanf(" %49[^\n]", atleta->nome);
}

void ordenarPorTempoNome(tAtleta vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            int cmp = ut_comparar(vetor[j].tempo, vetor[j+1].tempo);
            if (cmp < 0) {
                tAtleta temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            } else if (cmp == 0) {
                if (strcmp(vetor[j].nome, vetor[j+1].nome) > 0) {
                    tAtleta temp = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = temp;
                }
            }
        }
    }
}
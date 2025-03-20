#include "UNIDADE_TEMPO.h"
#include <stdlib.h>
#include <stdio.h>

struct unidade_tempo {
    int horas;
    int minutos;
    int segundos;
};

UnidadeTempo *ut_criar(int horas, int minutos, int segundos) {
    
    int total_segundos = horas * 3600 + minutos * 60 + segundos;
    
    if (total_segundos < 0) {
        return NULL;
    }

    int h = total_segundos / 3600;
    int resto = total_segundos % 3600;
    int m = resto / 60;
    int s = resto % 60;

    UnidadeTempo *ut = malloc(sizeof(UnidadeTempo));
    ut->horas = h;
    ut->minutos = m;
    ut->segundos = s;
    return ut;
}

UnidadeTempo* ut_criar_de_segundos(int total_segundos) {
    return ut_criar(0, 0, total_segundos);
}

void ut_destruir(UnidadeTempo* ut) {
    free(ut);
}

void ut_exibir(UnidadeTempo* ut) {
    printf("%02d:%02d:%02d", ut->horas, ut->minutos, ut->segundos);
}

int ut_para_segundos(UnidadeTempo* ut) {
    return ut->horas * 3600 + ut->minutos * 60 + ut->segundos;
}

UnidadeTempo* ut_somar(UnidadeTempo* ut1, UnidadeTempo* ut2) {
    return ut_criar_de_segundos(ut_para_segundos(ut1) + ut_para_segundos(ut2));
}

UnidadeTempo* ut_subtrair(UnidadeTempo* ut1, UnidadeTempo* ut2) {
    int segundos = ut_para_segundos(ut1) - ut_para_segundos(ut2);
    
    if (segundos >= 0) {
        return ut_criar_de_segundos(segundos);
    }
    
    return NULL;
}

int ut_comparar(UnidadeTempo* ut1, UnidadeTempo* ut2) {
    int s1 = ut_para_segundos(ut1);
    int s2 = ut_para_segundos(ut2);
    return (s1 > s2) - (s1 < s2);
}

void ut_obter_valores(UnidadeTempo* ut, int *h, int *m, int *s) {
    *h = ut->horas;
    *m = ut->minutos;
    *s = ut->segundos;
}
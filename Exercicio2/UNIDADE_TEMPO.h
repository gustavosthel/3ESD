typedef struct unidade_tempo UnidadeTempo;

UnidadeTempo* ut_criar(int horas, int minutos, int segundos);

UnidadeTempo* ut_criar_de_segundos(int total_segundos);

void ut_destruir(UnidadeTempo* ut);

void ut_exibir(UnidadeTempo* ut);

int ut_para_segundos(UnidadeTempo* ut);

UnidadeTempo* ut_somar(UnidadeTempo* ut1, UnidadeTempo* ut2);

UnidadeTempo* ut_subtrair(UnidadeTempo* ut1, UnidadeTempo* ut2);

int ut_comparar(UnidadeTempo* ut1, UnidadeTempo* ut2);

void ut_obter_valores(UnidadeTempo* ut, int *horas, int *minutos, int *segundos);
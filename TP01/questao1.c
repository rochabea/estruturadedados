#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Informacao
{
    char nome[100], telefone[100], curso[100];
    double nota1, nota2;
};

void situacaoFinal(FILE *entrada, FILE *saida)
{
    //fprintf(saida, "Nome,Media,Situacao\n");

    char linha[100];
    while (fgets(linha, 100, entrada) != NULL)
    {
        struct Informacao informacao;
        char *token;
        //token serve para dividir por meio da vírgula
        token = strtok(linha, ",");
        strcpy(informacao.nome, token);
        token = strtok(NULL, ","); 
        strcpy(informacao.telefone, token);
        token = strtok(NULL, ",");
        strcpy(informacao.curso, token);
        token = strtok(NULL, ",");
        informacao.nota1 = atof(token);
        token = strtok(NULL, ",");
        informacao.nota2 = atof(token);

        double media = (informacao.nota1 + informacao.nota2) / 2.0;
        const char *situacao = (media >= 7.0) ? "Aprovado" : "Reprovado";
        fprintf(saida, "%s,%.2lf,%s\n", informacao.nome, media, situacao);
    }
}

int main(void)
{
    FILE *entrada, *saida;

    entrada = fopen("C:\\Users\\Beatriz\\Desktop\\DadosEntrada.csv", "r");
    if (entrada == NULL)
    {
        printf("Arquivo de entrada nao pode ser aberto.\n");
        return 1;
    }

    saida = fopen("C:\\Users\\Beatriz\\Desktop\\SituacaoFinal.csv", "w");
    if (saida == NULL)
    {
        printf("Erro ao criar arquivo de saida.\n");
        return 1;
    }

    situacaoFinal(entrada, saida);

    fclose(entrada);
    fclose(saida);

    printf("Processamento de dados concluído e salvo no arquivo SituacaoFinal.csv.\n");

    return 0;
}

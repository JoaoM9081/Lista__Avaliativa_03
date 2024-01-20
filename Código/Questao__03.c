#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que verifica se o dia é válido
int dia_valido(char *dia)
{
    char *dias[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(dia, dias[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Função de validação da placa
int validar_placa(char *placa)
{
    int tam_placa = strlen(placa); // tamanho da placa

    if (tam_placa == 8 && placa[3] == '-')
    {
        return 1;
    }
    else if (tam_placa == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isalpha(placa[4]) && isdigit(placa[3]) && isdigit(placa[5]) && isdigit(placa[6]))
    {
        return 1;
    }
    return 0;
}

// Função que obtêm o último dígito
int ultimo_digito(char *placa)
{
    int comp_placa = strlen(placa);
    char ultimo_caractere = placa[comp_placa - 1];

    if (isdigit(ultimo_caractere))
    {
        return ultimo_caractere - '0';
    }
    else
    {
        return -1;
    }
}

// Função para verificar a circulação dos veículos
void circulacao(char *placa, char *dia)
{
    char *dias[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int proibidos[][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}};
    int last_digit = ultimo_digito(placa);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(dia, dias[i]) == 0)
        {
            char dia_minusculo[15];
            strcpy(dia_minusculo, dias[i]);

            for (int j = 0; dia_minusculo[j]; j++)
            {
                dia_minusculo[j] = tolower(dia_minusculo[j]); // fazendo as strings de dias ficarem minusculas
            }

            if (last_digit == proibidos[i][0] || last_digit == proibidos[i][1])
                printf("%s nao pode circular %s\n", placa, dia_minusculo);
            else
                printf("%s pode circular %s\n", placa, dia_minusculo);

            return;
        }
    }

    if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
    {
        printf("Nao ha proibicao no fim de semana\n");
    }
    else
    {
        printf("Dia da semana invalido\n");
    }
}

int main()
{
    char placa[9];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);

    if (!validar_placa(placa))
    {
        printf("Placa invalida\n");
    }

    if (!dia_valido(dia))
    {
        printf("Dia da semana invalido\n");
    }

    if (validar_placa(placa) && dia_valido(dia))
    {
        circulacao(placa, dia);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

// Função que obtêm o número romano
int valor_romano(char romano)
{
    char simbolo[] = "IVXLCDM"; // simbolos romanos
    int v[] = {1, 5, 10, 50, 100, 500, 1000}; // valores dos simbolos

    for (int i = 0; i < 7; i++) // Inserindo os valores de cada simbolo romano
    {
        if (romano == simbolo[i])
        {
            return v[i];
        }
    }
    return -1;
}

// Função para converter o número romano para decimal
int romano_decimal(char *nR)
{
    int result = 0;
    int v1, v2;
    int tam = strlen(nR);

    for (int i = 0; i < tam; i++)
    {
        v1 = valor_romano(nR[i]);
        if (i + 1 < tam)
        {
            v2 = valor_romano(nR[i + 1]);
        }
        else
        {
            v2 = 0;
        }

        if (v1 >= v2)
        {
            result += v1;
        }
        else
        {
            result += v2 - v1;
            i++;
        }
    }
    return result;
}

// Função que imprimi o número binário
void binario(int numero)
{
    if (numero > 1)
    binario(numero / 2);
    printf("%d", numero % 2);
}

// Função que imprimi o número em bases diferentes
void Bases(char *nR)
{
    int decimal = romano_decimal(nR);

    printf("%s na base 2: ", nR);
    binario(decimal);
    printf("\n");
    printf("%s na base 10: %d\n", nR, decimal);
    printf("%s na base 16: %x\n", nR, decimal);
}

int main()
{
    char nR[13]; // String dos números romanos

    scanf("%s", nR);
    Bases(nR);

    return 0;
}
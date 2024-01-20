#include <stdio.h>

int main()
{
    int meses;
    double aporte, taxa, montante = 0;

    scanf("%d %lf %lf", &meses, &aporte, &taxa);

    // Calcula o montante para cada mês
    for (int i = 1; i <= meses; i++)
    {
        // Atualiza o montante com as taxas e o aporte
        montante = (montante + aporte) * (1 + taxa);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    }

    return 0;
}
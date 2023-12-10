#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>  // Adicionada biblioteca para utilizar o Beep
#include <conio.h>   // Adicionada biblioteca para utilizar o getch

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int sec = 0, min = 0, hr = 0;
    int i = 0;
    int start = 0;
    int last_sec = 0, last_min = 0, last_hr = 0;

    do {
        system("cls");

        printf("Cronômetro\n\n");

        printf("\n\t\t\t\t%02dh:%02dm:%02ds\n\n", hr, min, sec);

        if (sec == 60) {
            sec = 0;
            min++;
        }

        if (min == 60) {
            min = 0;
            hr++;
            if (hr % 1 == 0 && min == 0 && sec == 0) {
                Beep(1000, 500);
            }
        }

        if (hr == 24) {
            hr = 0;
        }

        sec++;

        if (start && sec == 0 && min == 0 && hr % 1 == 0) {
            Beep(1000, 500);
        }

        printf("Pressione 's' para start, 'p' para parar, 'r' para resetar: ");
        char input = _getch();  // Usar _getch para obter o caractere imediatamente
        printf("%c\n", input);  // Imprimir o caractere para visualização (opcional)

        switch (input) {
            case 's':
                start = 1;
                break;
            case 'p':
                start = 0;
                break;
            case 'r':
                start = 0;
                sec = min = hr = 0;
                break;
        }

        last_sec = sec;
        last_min = min;
        last_hr = hr;

        printf("Pressione 'q' para sair ou qualquer outra tecla para continuar: ");
        input = _getch();  // Usar _getch para obter o caractere imediatamente
        printf("%c\n", input);  // Imprimir o caractere para visualização (opcional)
        if (input == 'q') {
            i = 1;
        }

    } while (i == 0);

    printf("Armazenando último valor de contagem: %02dh:%02dm:%02ds\n", last_hr, last_min, last_sec);

    system("pause");
    return 0;
}

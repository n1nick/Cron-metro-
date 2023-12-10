#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>  // Adicionada biblioteca para utilizar o Beep

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int sec = 0, min = 0, hr = 0;
    int i = 0;
    int start = 0;  // Variável para controlar se o cronômetro está em execução (1) ou parado (0)
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
            // Emitir um sinal sonoro a cada hora (3600 segundos)
            if (hr % 1 == 0 && min == 0 && sec == 0) {
                Beep(1000, 500);  // Beep com frequência de 1000 Hz e duração de 500 ms
            }
        }

        if (hr == 24) {
            hr = 0;
        }

        sec++;

        // Verificar se o cronômetro está em execução e se uma hora (3600 segundos) se passou
        if (start && sec == 0 && min == 0 && hr % 1 == 0) {
            Beep(1000, 500);  // Beep ao final de cada hora durante a contagem progressiva
        }

        printf("Pressione 's' para start, 'p' para parar, 'r' para resetar: ");
        char input;
        scanf(" %c", &input);

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

        // Armazenar o último valor de contagem
        last_sec = sec;
        last_min = min;
        last_hr = hr;

        printf("Pressione 'q' para sair ou qualquer outra tecla para continuar: ");
        scanf(" %c", &input);
        if (input == 'q') {
            i = 1;  // Sair do loop ao pressionar 'q'
        }

    } while (i == 0);

    // Armazenar o último valor de contagem antes de sair do programa
    printf("Armazenando último valor de contagem: %02dh:%02dm:%02ds\n", last_hr, last_min, last_sec);

    system("pause");
    return 0;
}

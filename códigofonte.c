#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
//#include <SDL.h> 

void salvarEstado(int hr, int min, int sec) {
    FILE *arquivo = fopen("estado_cronometro.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "%02d:%02d:%02d", hr, min, sec);
        fclose(arquivo);
    } else {
        printf("Erro ao salvar o estado do cronômetro\n");
    }
}

// Função para carregar o estado anterior do cronômetro de um arquivo
void carregarEstado(int *hr, int *min, int *sec) {
    FILE *arquivo = fopen("estado_cronometro.txt", "r");
    if (arquivo != NULL) {
        fscanf(arquivo, "%02d:%02d:%02d", hr, min, sec);
        fclose(arquivo);
    } else {
        // Se o arquivo não existir, inicia com zero
        *hr = *min = *sec = 0;
    }
}    
    
int main(void){
	//comando de regionalizaÃ§Ã£o
	setlocale(LC_ALL, "Portuguese");
	//tÃ­tulo do programa
	SetConsoleTitle("Cronometro");
	
	//variÃ¡veis
    int sec=0;//segundos
	int min=0;//minutos
	int hr=0;//horas
	int i=0;//controle do loop
	int running = 0; // 0 para parado, 1 para iniciado
	
	carregarEstado(&hr, &min, &sec);

     printf("Aperte 's' para iniciar, 'r' para reiniciar e 'p' para parar\n");

    do {
        if (kbhit()) {
            char key = getch();
            if (key == 's' || key == 'S') {
                running = !running;
                printf("Cronômetro %s\n", running ? "iniciado" : "parado");
            } else if (key == 'r' || key == 'R') {
                sec = min = hr = 0;
                printf("Cronômetro reiniciado\n");
            } else if (key == 'p' || key == 'P') {
                running = 0;
                printf("Cronômetro parado\n");
            }
        }
	
		system("cls");//limpa a tela
		
		printf("Cronômetro\n\n");
		
		printf("\n\t\t\t\t%02dh:%02dm:%02ds\n\n", hr,min,sec);
		
		if (running) {
		if(sec==60){
		    sec=0;
		    min++;
		}
		
		if(min==60){
		    min=0;
		    hr++;
		}
		
		if(hr==24){
		    hr=0;
		}
		
		  if (sec % 60 == 0 && sec != 0) {
                printf("\a"); // Utiliza a função reproduzirBeep para reproduzir um som
            }
            
		
		Sleep(1000);//tem a funÃ§Ã£o de pausar a execuÃ§Ã£o por um determinado tempo
		sec++;
		salvarEstado(hr, min, sec);
	}
	 
	}while (i==0);//condiÃ§Ã£o para o loop infinito

    system("pause");
    return 0;
}

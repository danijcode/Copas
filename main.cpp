#include <stdlib.h>
#include <stdio.h>
#include "Structs.h"
#include "Funcoes.h"

int main() {

	Mesa * mesaDeJogo = novaMesa(); //A funcao cria os quatro jogadores;

	printf("\n\tBem vindo ao jogo de copas. \n");
	printf("\nAlunos: Rosiel e Daniel\n");
	printf("Professor: Hermes Neto");
	do {
		Baralho * baralho1 = novoBaralho(); // Novo Baralho;

		char opc[1];
		int jogador;

		printf("\nDeseja comecar um novo jogo? Y/N \n");
		scanf("%s", &opc);

		// Embaralhar o baralho criado;
		if (opc == "Y" || opc == "y") {
			embaralhar(baralho1);
		}
		getchar();

		// Distribuir para os 4 jogadores da Mesa;
		printf("\nPressione qualquer tecla para distribuir as cartas: \n");
		getchar();
		distribuir(mesaDeJogo, baralho1);

		// Mostrando as cartas de cada jogador;
		printf("Mostrando as cartas de cada jogador: \n");
		for (jogador = 1; jogador <= 4; jogador++) {
			mostrarCartas(mesaDeJogo, jogador);
			getchar();
			system("cls");
		}

		// Turno de Jogo;
		system("cls");
		rodadaMesa(mesaDeJogo);

	} while (mesaDeJogo->jogadores[0]->pontuacao != 100 &&
			mesaDeJogo->jogadores[1]->pontuacao != 100 &&
			mesaDeJogo->jogadores[2]->pontuacao != 100 &&
			mesaDeJogo->jogadores[3]->pontuacao != 100);
	
	system("pause");
}


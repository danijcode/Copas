
Carta * novaCarta(int n, int f){
	Carta * nova = (Carta*)malloc(sizeof(Carta));
	nova->naipe = n;
	nova->face = f;
	return nova;
}

void inserirCarta(Baralho * b, Carta * c){
	if(b->cont<52){
		b->cartas[b->cont] = c;
		b->cont++;
	}
}

Carta * tirarCarta(Baralho * b, int pos){
	Carta * aux = NULL;
	if ((pos < 0)||(pos > b->cont)){
		return NULL;
	}
	aux = b->cartas[pos];
	for (int i=pos+1;i<b->cont;i++){
		b->cartas[i-1] = b->cartas[i];
	}
	b->cont--;
	return aux;
}

Baralho * novoBaralho(){
	Baralho * novo = (Baralho*)malloc(sizeof(Baralho));
	novo->cont = 0;
	int i, j;
	
	for(j = 0; j < 13; j++){
		for(i = 0; i<4; i++){
			Carta * n = novaCarta(i,j);
			inserirCarta(novo, n);
		}
	}
	return novo;
}

void embaralhar(Baralho * b){
	Carta * caux;
	int paux;
	int i;
	
	for (i = 0; i < b->cont; i++){
		caux = tirarCarta(b, paux);
		paux = rand() % b->cont;	
		inserirCarta(b,caux);
	}
}

Mesa * novaMesa() {
	int i;
	Mesa * m = (Mesa*)malloc(sizeof(Mesa));

	for (i = 0; i < 4; i++) {
		m->jogadores[i] = (Jogador*)malloc(sizeof(Jogador));
		m->jogadores[i]->pontuacao = 0;
	}
	return m;
}

void distribuir(Mesa * m, Baralho * b){
	int i, j;
			
	for(i=0; i<4; i++){
		for(j=0; j<13; j++){
			m->jogadores[i]->JogadorCartas[j] = b->cartas[j];
			if (b->cont > 13) {
				tirarCarta(b, j);
			}			
		}
		m->jogadores[i]->cont = 13;
	}
}

void mostrarCartas(Mesa * m, int j) {
	Jogador * aux = m->jogadores[j-1];

	int i;
	char * Naipe[4] = { "Paus", "Copas", "Espadas","Ouro" };
	char * Face[13] = { "As", "2", "3","4","5","6","7","8","9","10","J","Q","K" };


	printf("\n Cartas do Jogador %i: \n", j);
	for (i = 0; i < aux->cont; i++) {
		printf("Carta %i = %s de %s \n", i+1, Face[aux->JogadorCartas[i]->face], Naipe[aux->JogadorCartas[i]->naipe]);
	}
}

void compararCartas(Mesa * m, Pilha * p) {
	int i = 0;

	if (p->cartasRodada[i]->face > p->cartasRodada[i + 1]->face &&
		p->cartasRodada[i]->face > p->cartasRodada[i + 2]->face &&
		p->cartasRodada[i]->face > p->cartasRodada[i + 3]->face) {
		if (p->cartasRodada[i]->naipe == 1) {
			m->jogadores[i]->pontuacao = m->jogadores[i]->pontuacao + 1;
		}
		else if (p->cartasRodada[i]->naipe == 2 && p->cartasRodada[i]->face == 11) {
			m->jogadores[i]->pontuacao = m->jogadores[i]->pontuacao + 13;
		}
	}
	if (p->cartasRodada[i + 1]->face > p->cartasRodada[i]->face &&
		p->cartasRodada[i + 1]->face > p->cartasRodada[i + 2]->face &&
		p->cartasRodada[i + 1]->face > p->cartasRodada[i + 3]->face) {
		if (p->cartasRodada[i + 1]->naipe == 1) {
			m->jogadores[i + 1]->pontuacao = m->jogadores[i + 1]->pontuacao + 1;
		}
		else if (p->cartasRodada[i + 1]->naipe == 2 && p->cartasRodada[i + 1]->face == 11) {
			m->jogadores[i + 1]->pontuacao = m->jogadores[i + 1]->pontuacao + 13;
		}
	}
	if (p->cartasRodada[i + 2]->face > p->cartasRodada[i]->face &&
		p->cartasRodada[i + 2]->face > p->cartasRodada[i + 1]->face &&
		p->cartasRodada[i + 2]->face > p->cartasRodada[i + 3]->face) {
		if (p->cartasRodada[i + 2]->naipe == 1) {
			m->jogadores[i + 2]->pontuacao = m->jogadores[i + 2]->pontuacao + 1;
		}
		else if (p->cartasRodada[i + 2]->naipe == 2 && p->cartasRodada[i + 2]->face == 11) {
			m->jogadores[i + 2]->pontuacao = m->jogadores[i + 2]->pontuacao + 13;
		}
	}
	if (p->cartasRodada[i + 3]->face > p->cartasRodada[i]->face &&
		p->cartasRodada[i + 3]->face > p->cartasRodada[i + 1]->face &&
		p->cartasRodada[i + 3]->face > p->cartasRodada[i + 2]->face) {
		if (p->cartasRodada[i + 3]->naipe == 1) {
			m->jogadores[i + 3]->pontuacao = m->jogadores[i]->pontuacao + 1;
		}
		else if (p->cartasRodada[i + 3]->naipe == 2 && p->cartasRodada[i + 3]->face == 11) {
			m->jogadores[i + 3]->pontuacao = m->jogadores[i + 3]->pontuacao + 13;
		}
	}
}

Mesa * checarPontuacao(Mesa * m, Pilha * p) {
	int i;

	printf("Pontuacao Atual: \n\n");
	for (i = 0; i < 4; i++) {
		printf("Jogador %i = %i Pontos\n", i+1, m->jogadores[i]->pontuacao);
		if (m->jogadores[i]->pontuacao == 100) {
			printf("\nJogador %i Venceu!\n\n", i + 1);
		}
	}
	return m;
}

Mesa * criarMonte(Mesa * m, Pilha * p, Carta * c) {

	char * Naipe[4] = { "Paus", "Copas", "Espadas","Ouro" };
	char * Face[13] = { "As", "2", "3","4","5","6","7","8","9","10","J","Q","K" };

	p->topo++;
	p->cartasRodada[p->topo] = c;

	printf("Topo do descarte: %s de %s\n", Face[p->cartasRodada[p->topo]->face], Naipe[p->cartasRodada[p->topo]->naipe]);

	return m;
}

Mesa * jogarCarta(Mesa * m, Jogador * jog, int pos, Pilha * p) {

	int i;

	criarMonte(m, p, jog->JogadorCartas[pos - 1]);

	for (i = pos - 1; i<jog->cont; i++) {
		jog->JogadorCartas[i] = jog->JogadorCartas[i + 1];
	}
	jog->cont--;

	return m;
}

Mesa * turnoJogadores(int posicao, Mesa * m, Jogador * j, Pilha * p) {
	int i;
	int pos;
	char * Naipe[4] = { "Paus", "Copas", "Espadas","Ouro" };
	char * Face[13] = { "As", "2", "3","4","5","6","7","8","9","10","J","Q","K" };

	printf("\nJogador %i \n\n", posicao);
	printf("Escolha uma carta: \n");
	for (i = 0; i < j->cont; i++) {
		printf("Posicao %i = %s de %s\n", i+1, Face[j->JogadorCartas[i]->face], Naipe[j->JogadorCartas[i]->naipe]);
	}

	printf("\nPosicao da carta escolhida: ");
	scanf("%i", &pos);

	system("cls");
	if (pos <= j->cont) {
		jogarCarta(m, j, pos, p);
	}
	else {
		printf("Digite uma posicao valida!");
	}
	return m;
}

Mesa * rodadaMesa(Mesa * m) {
	int i;
	int j;

	for (j = 0; j < 13; j++) {

		int k = 1;

		Pilha * p = (Pilha*)malloc(sizeof(Pilha));
		p->topo = -1;

		for (i = 0; i < 4; i++) {
			turnoJogadores(k, m, m->jogadores[i], p);
			k++;
		}
		system("cls");
		compararCartas(m, p);
		checarPontuacao(m, p);
	}

	return m;
}

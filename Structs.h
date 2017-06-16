
typedef struct {
	int naipe;
	int face;
}Carta;

typedef struct {
	Carta * cartas[52];
	int cont;
}Baralho;

typedef struct {
	Carta * JogadorCartas[13];
	int pontuacao;
	int cont;
}Jogador;

typedef struct{
	Jogador * jogadores[4];
}Mesa;

typedef struct{
	Carta * cartasRodada[4];
	int topo;
}Pilha;

Carta * novaCarta(int n, int f);
void inserirCarta(Baralho *b, Carta * c);
Carta * tirarCarta(Baralho * b, int pos);
Baralho * novoBaralho();
void embaralhar(Baralho * b);
Mesa * novaMesa();
void distribuir(Mesa * m, Baralho * b);
void mostrarCartas(Mesa * m, int j);
Mesa * criarMonte(Mesa * m, Pilha * p, Carta * c);
void compararCartas(Mesa * m, Pilha * p);
Mesa * jogarCarta(Mesa * m, Jogador * jog, int pos, Pilha * p);
Mesa * turnoJogadores(int posicao, Mesa * m, Jogador * j, Pilha * p);
Mesa * rodadaMesa(Mesa * m);
Mesa * checarPontuacao(Mesa * m, Pilha * p);








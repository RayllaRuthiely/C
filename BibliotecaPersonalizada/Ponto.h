#ifndef PONTO_H
#define PONTO_H

/**
 * Estrutura que representa um ponto no plano cartesiano.
 * Contém as coordenadas x e y do ponto.
 */
typedef struct ponto Ponto;

//Criar um novo ponto
Ponto* ponto_criar(float x, float y);

//Liberar um ponto
void ponto_Liberar(Ponto* p);

//Acessar os valores de x e y do ponto
void ponto_acessar(Ponto* p, float* x, float* y);

//Atribui os valores de x e y ao ponto
void ponto_atribuir(Ponto* p, float x, float y);

//Calcula a distância entre dois pontos
float ponto_distancia(Ponto* p1, Ponto* p2);

#endif
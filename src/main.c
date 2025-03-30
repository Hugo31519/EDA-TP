/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"
int main(int argc, char const *argv[])
{
Antena* elemento1;//Antena 1
Antena* elemento2;//.....2
Antena* elemento3;//.....3
Antena* ord2;
Antena* ord3;
Antena*lista=NULL;//cabeça da lista(aponta para primeiro elemento)
const char* ficheiro1="antenas.txt";
char* ficheiro2="Antenas.bin";
EfeitoNefasto*listaE;

//Cria novas antenas 
elemento1 = Inserir('A', 2, 2);
elemento2 = Inserir('B', 3, 3);
elemento3 = Inserir('C', 4, 4);

lista = Inicio(lista, elemento1);//Insere o elemento no inicio da lista
lista = InserirFim(lista, elemento3);//Insere um elemento no fim da lista
lista = InserirOrdenada(lista, elemento2);//Insere elementos de forma ordenada(crescente)
Listar(lista);//Lista a lista criada 
printf("------------------------------\n");
lista = remover(lista, elemento2);//remoeve um elemento da lista
Listar(lista);//lista a lista criada
printf("------------------------------\n");
lerFicheirotxt(ficheiro1);//lê o ficheiro antenas.txt
ord2=GravarElementBinario(ficheiro2, elemento1);//Grava o elemento1 em um ficheiro
elemento1=LerElementsBinario(ficheiro2);//le e adicona o elemento1 a um ficheiro binario
printf("------------------------------\n");
listaE=CalculaNefasto(lista);//calcula os efeitos nefasto
ListarNefasto(listaE);//lista os efeitos nefastos












return 0;
}


/**
 * @file funcoes.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef FUNCOES_H
#define FUNCOES_H
#define M 100
#include<string.h>

//Struct da Antena
typedef struct Antena{
    char frequencia;//frequencia da Antena
    int a, b;//variáveis do tipo x&y da antena
    struct Antena* next;//apontador para o próximo elemento
    }Antena;
//Estrutura de uxílio para os ficheiros em bin
typedef struct AntenaFile {
    int a;//valor inteiro
    int b;//""""
    char frequencia;//nome(frequencia)
    }AntenaFile;
//struct auxiliar para o efeito nefasto
typedef struct EfeitoNefasto{
    int a;
    int b;
    struct EfeitoNefasto* next;
}EfeitoNefasto;
    
    
    //Cria uma Antena
    Antena* Inserir(char frequencia,int a, int b);
    //Insere Antenas alterando o apontador da variável inicio
    Antena* Inicio(Antena* inicio, Antena*quadrdado);
    //Lista as Antenas
    void Listar(Antena*incio);
    //Insere as Antenas no fim da lista
    Antena* InserirFim(Antena*inicio, Antena*quadrdado);
    //Remove as Antenas desejadas
    Antena* remover(Antena*inicio, Antena*quadrdado);
    //Carrega as Antenas para um ficheiro .txt
    int CarregarParaFicheiro(Antena* inicio,char* nome_arquivo);
    //Insere as Antenas de uma forma ordenada
    Antena* InserirOrdenada(Antena* inicio, Antena*quadrdado);
    //Grava as Antenas em binário
    int GravarElementBinario(char* nomeFicheiro, Antena* quadrado);
    //Lê um ficheiro binário(.bin)
    Antena* LerElementsBinario(char* nomeFicheiro);
    //Lẽ um ficheiro txt(.txt)
    void lerFicheirotxt(const char* nomeFicheiro);
    //Calcula o efeito nefasto
    EfeitoNefasto* CalculaNefasto(Antena* inicio);
    //Lista os efeitos nefasto
    void ListarNefasto(EfeitoNefasto*head);



#endif

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

//Classe que armazena os dados individuais de cada execução do benchmark
class Benchmark
{
private:
    //Armazena o número de comparações
    int compNumber;
    //Armazena o ponto de partida do algoritmo de ordenação
    chrono::time_point<chrono::high_resolution_clock> startTime;
    //Armazena o ponto de término do algoritmo de ordenação
    chrono::time_point<chrono::high_resolution_clock> endTime;
    //Armazena o tempo de execução dos algoritmos de inserção e busca
    double insertionRuntime;
    double searchRuntime;

public:
    /**
     * Construtor da classe
     * 
    */
    Benchmark();
    /**
     * Destrutor da Classe
     * 
    */
    ~Benchmark();

    /**
     * Retorna o número de comparações
     * 
     * @return int
    */
    int getCompNumber();
 
    /**
     * Retorna o ponto de partida do algoritmo
     * 
     * @return chrono::time_point<chrono::high_resolution_clock>
    */
    chrono::time_point<chrono::high_resolution_clock> getStartTime();
    /**
     * Retorna o ponto de término do algoritmo
     * 
     * @return chrono::time_point<chrono::high_resolution_clock>
    */
    chrono::time_point<chrono::high_resolution_clock> getEndTime();
    /**
     * Retorna o tempo de execução do algoritmo de inserção
     * 
     * @return double
    */
    double getInsertionRuntime();
    /**
     * Retorna o tempo de execução do algoritmo de busca
     * 
     * @return double
    */
    double getSearchRuntime();

    /**
     * Define/Redefine o número de comparações
     * 
     * @param int compNumber
     * @return void
    */
    void setCompNumber(int compNumber);

    /**
     * Define/Redefine o ponto de partida do algoritmo
     * 
     * @param chrono::time_point<chrono::high_resolution_clock> startTime
     * @return void
    */
    void setStartTime(chrono::time_point<chrono::high_resolution_clock> startTime);
    /**
     * Define/Redefine o ponto de término do algoritmo
     * 
     * @param chrono::time_point<chrono::high_resolution_clock> endTime
     * @return void
    */
    void setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime);
    /**
     * Define/Redefine o tempo de execução da inserção
     * 
     * @param double runtime
     * @return void
    */
    void setInsertionRuntime(double insertionRuntime);
    /**
     * Define/Redefine o tempo de execução
     * 
     * @param double runtime
     * @return void
    */
    void setSearchRuntime(double searchRuntime);
 
    /**
     * Incrementa em 1 o número de comparações
     * 
     * @return void
    */
    void incrementCompNumber();

    /**
     * Define ponto de partida do algoritmo para o momento em que esta função é chamada
     * 
     * @return void
    */
    void setStartTimeAsNow();
    /**
     * Define ponto de término do algoritmo para o momento em que esta função é chamada
     * 
     * @return void
    */
    void setEndTimeAsNow();
    /**
     * Gera o tempo de execução da inserção realizando a diferença do ponto partida e o ponto de término
     * 
     * @return void
    */
    void generateInsertionRuntime();
    /**
     * Gera o tempo de execução da busca realizando a diferença do ponto partida e o ponto de término
     * 
     * @return void
    */
    void generateSearchRuntime();
};

#endif
#include "Benchmark.h"

Benchmark::Benchmark()
{
    this->compNumber = 0;
    this->insertionRuntime = 0;
    this->searchRuntime = 0;
  
}

Benchmark::~Benchmark(){}

int Benchmark::getCompNumber()
{
    return this->compNumber;
}


chrono::time_point<chrono::high_resolution_clock> Benchmark::getStartTime()
{
    return this->startTime;
}

chrono::time_point<chrono::high_resolution_clock> Benchmark::getEndTime()
{
    return this->endTime;
}

double Benchmark::getInsertionRuntime()
{
    return this->insertionRuntime;
}


double Benchmark::getSearchRuntime()
{
    return this->searchRuntime;
}


void Benchmark::setCompNumber(int compNumber)
{
    this->compNumber = compNumber;
}


void Benchmark::setStartTime(chrono::time_point<chrono::high_resolution_clock> startTime)
{
    this->startTime = startTime;
}

void Benchmark::setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime)
{
    this->endTime = endTime;
}

void Benchmark::setInsertionRuntime(double insertionRuntime)
{
    this->insertionRuntime = insertionRuntime;
}

void Benchmark::setSearchRuntime(double searchRuntime)
{
    this->searchRuntime = searchRuntime;
}

void Benchmark::incrementCompNumber()
{
    this->compNumber++;
}

void Benchmark::setStartTimeAsNow()
{
    this->startTime = chrono::high_resolution_clock::now();
}

void Benchmark::setEndTimeAsNow()
{
    this->endTime = chrono::high_resolution_clock::now();
}

void Benchmark::generateInsertionRuntime()
{
    this->insertionRuntime = chrono::duration_cast<chrono::milliseconds>(this->endTime - this->startTime).count();
}

void Benchmark::generateSearchRuntime()
{
    this->searchRuntime = chrono::duration_cast<chrono::milliseconds>(this->endTime - this->startTime).count();
}


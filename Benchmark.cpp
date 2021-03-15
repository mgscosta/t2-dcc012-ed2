#include "Benchmark.h"

Benchmark::Benchmark()
{
    this->s1CompNumber = 0;
    this->s2CompNumber = 0;
    this->insertionRuntime = 0;
    this->searchRuntime = 0;
    this->s1NumCases = 0;
    this->s2NumCases = 0;
}

Benchmark::~Benchmark(){}

int Benchmark::getS1CompNumber()
{
    return this->s1CompNumber;
}

int Benchmark::getS2CompNumber()
{
    return this->s2CompNumber;
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


void Benchmark::setS1CompNumber(int compNumber)
{
    this->s1CompNumber = compNumber;
}

void Benchmark::setS2CompNumber(int compNumber)
{
    this->s2CompNumber = compNumber;
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

int Benchmark::getS1NumCases()
{
    return this->s1NumCases;
}

void Benchmark::setS1NumCases(int numCases)
{
    this->s1NumCases = numCases;
}

int Benchmark::getS2NumCases()
{
    return this->s2NumCases;
}

void Benchmark::setS2NumCases(int numCases)
{
    this->s2NumCases = numCases;
}


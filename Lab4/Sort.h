#pragma once

class Sort
{
private:
    int* vector;
    unsigned int size;

    friend int  qsPartition (int* array, int low, int high);
    friend void qsNoReverse (int* array, int low, int high);
public:
    Sort (unsigned int count, int min, int max);
    Sort (int* array, unsigned int count);
    Sort (unsigned int count, ...);
    Sort (const char* string);
    ~Sort ();

    void reverse ();
    void insertSort (bool ascendent = false);
    void quickSort (int low, int high, bool ascendent = false);
    void bubbleSort (bool ascendent = false);

    void print ();
    void merge (Sort& list);
    int  getElementCount ();
    int  getElementFromIndex (unsigned int index);
};

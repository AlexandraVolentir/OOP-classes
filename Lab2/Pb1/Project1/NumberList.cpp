
#include "NumberList.h" // header in local directory
#include <iostream> // header in standard library

using namespace std;

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count > 10)
        return false;
    numbers[count++] = x;
    return true;
}

void NumberList::RemoveAllElements(int x)
{
    for (int i = 0; i < count; i++)
        if (numbers[i] == x)
        {
            for (int j = i; j < count; j++)
                numbers[j] = numbers[j + 1];
            count--;
            i--;
        }
}

void NumberList::Sort()
{
    int i, key, j;
    for (i = 1; i < count; i++) {
        key = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}

bool NumberList::Insert(int position, int x)
{
    if (count > 10)
        return false;
    for (int i = count; i > position; i--)
        numbers[i] = numbers[i - 1];
    numbers[position] = x;
    count++;
    return true;
}


#include "NumberList.h"

int main()
{
    NumberList l;
    l.Init();
    l.Add(10);
    l.Add(20);
    l.Add(4);
    l.Add(3);
    l.Add(45);

    l.Insert(4, 30);
    l.Print();

    l.Sort();
    l.Print();

    l.RemoveAllElements(10);
    l.Print();
   
    return 0;
}
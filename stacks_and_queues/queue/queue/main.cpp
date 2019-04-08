//
//  main.cpp
//  queue
//
//  Created by LYT on 07/04/2019.
//  Copyright © 2019 Kiki Tan. All rights reserved.
//

#define MAX 1000
#include <iostream>


template <class T>
class Queue
{
private:
    T queue[MAX];
    int head;
    int len;
    
public:
    
    // constructor
    Queue(): len(0), head(0){}
    Queue(T arr[], int arrLen)
    {
        len = 0;
        head = 0;
        for (int i = head; (i < arrLen) && (head + i < MAX); i++)
        {
            queue[i] = arr[i];
            len++;
        }
    }
    
    // methods
    T add(T _newVal)
    {
        if (head + len < MAX)
        {
            queue[len++] = _newVal;
        }
        return queue[len];
    }
    
    T remove()
    {
        T tmp = queue[0];
        head++;
        return tmp;
    }
    
    void print()
    {
        for (int i = head; i < len; i++)
        {
            std::cout << queue[i] << ' ';
        }
        std::cout << '\n';
    }
};


int main(int argc, const char * argv[]) {
    
    Queue<int> q;
    q.add(0);
    q.add(1);
    q.add(2);
    q.print();
    q.remove();
    q.print();
}

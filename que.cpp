#ifndef QUE_CPP
#define QUE_CPP
#include<cstddef>
#include<new>
#include"que.h"
#include<iostream>
using namespace std;

template<class ItemType>
que<ItemType>::que()
{
        front=NULL;
        rear=NULL;
        maxItems = 0;
}

template<class ItemType>
void que<ItemType>::MakeEmpty()
{
        NodeType<ItemType>*tempPtr;
        while(front!=NULL)
        {
            tempPtr=front;
            front=front->next;
            delete tempPtr;
        }
        rear=NULL;

}

template<class ItemType>
que<ItemType>::~que()
{
    MakeEmpty();
    maxItems = 0;
}

template<class ItemType>
bool que<ItemType>::IsFull()
{
        NodeType<ItemType>*location;
        try
        {
            location=new NodeType<ItemType>;
            delete location;
            return false;
        }
        catch(...)
        {
            return true;
        }
}

template<class ItemType>
bool que<ItemType>::IsEmpty()
{
    return(front==NULL);
}

template<class ItemType>
void que<ItemType>::getMax(int &m)
{
    m = maxItems;
}

template<class ItemType>
void que<ItemType>::Enque(ItemType item, ItemType a_time,ItemType runTime)
{
    if(IsFull())
    cout<<"que is full\n";
    else
    {
        NodeType<ItemType>* newNode;
        newNode=new NodeType<ItemType>;
        newNode->info=item;
        newNode->arrival = a_time;
        newNode->burstTime=runTime;
        newNode->next=NULL;

        if(rear==NULL)
        {
            front=newNode;
        }
        else
        rear->next=newNode;

        rear=newNode;

        maxItems++;
    }
}

template<class ItemType>
void que<ItemType>::Deque(ItemType& item, ItemType &a_time,ItemType& rtime)
{
    NodeType<ItemType>* temp;
    temp = front;
    item = front->info;
    a_time = front->arrival;
    rtime = front->burstTime;
    front = front->next;

    if(front == NULL)
    rear=NULL;

    delete temp;
    maxItems--;

}

#endif

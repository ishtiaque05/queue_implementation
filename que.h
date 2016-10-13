#ifndef QUE_H
#define QUE_H

template<class ItemType>
struct NodeType
{
    ItemType info;
    ItemType burstTime;
    ItemType arrival;
    NodeType*next;
};

template<class ItemType>
class que
{
    public:
    que();
    ~que();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void LengthIs();
    void getMax(int &);
    void Enque(ItemType item, ItemType a_time, ItemType runTime);
    void Deque(ItemType& item, ItemType &a_time,ItemType& rtime);
    private:
    NodeType<ItemType>* front;
    NodeType<ItemType>* rear;
    int maxItems;
};
#endif
#include"que.cpp"

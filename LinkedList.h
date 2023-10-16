#pragma once
//Muhammad_Uzair_Choudhary_22i2681

template<typename T, typename U>
class Node
{
public:
	U data;
	T next;
};

template<typename T>
class LinkedList
{
public:
	Node<T> *head;
	Node<T> *tail;
};
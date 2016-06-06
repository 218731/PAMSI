#ifndef QUEUE_HH
#define QUEUE_HH

#include "lista.hh"

/* Klasa implementuj±ca kolejkê. */

template <class T> class Queue {

private:
  Lista<T> *queue;
public:
  void enqueue (T element);
  T dequeue ();
	T get (int i);
  int size ();
  Queue();
  ~Queue();
};

template <class T> T Queue<T>::get (int i) {
  return queue->get(i);
}

template <class T> Queue<T>::Queue () {
  queue = new Lista<T> ();
}

template <class T> Queue<T>::~Queue () {
  delete queue;
}

template <class T> void Queue<T>::enqueue (T element) {
  queue->add(element, queue->size()+1);
}

template <class T> T Queue<T>::dequeue () {
  if (queue->size()>0) {
    T dequeuedElement;
    dequeuedElement = queue->get(1);
    queue->remove(1);
    return dequeuedElement;
  } else return 0;
}

template <class T> int Queue<T>::size () {
    return queue->size();
  }

#endif

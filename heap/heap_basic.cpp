// Max-Heap data structure in C++

#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void heapify(vector<int> &heap, int i)
{
  int size = heap.size();
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && heap[l] < heap[smallest])
    smallest = l;
  if (r < size && heap[r] < heap[smallest])
    smallest = r;

  if (smallest != i)
  {
    swap(&heap[i], &heap[smallest]);
    heapify(heap, smallest);
  }
}
void insert(vector<int> &heap, int newNum)
{
  int size = heap.size();
  if (size == 0)
  {
    heap.push_back(newNum);
  }
  else
  {
    heap.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(heap, i);
    }
  }
}
void deleteNode(vector<int> &heap, int num)
{
  int size = heap.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == heap[i])
      break;
  }
  swap(&heap[i], &heap[size - 1]);

  heap.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(heap, i);
  }
}
void printArray(vector<int> &heap)
{
  for (int i = 0; i < heap.size(); ++i)
    cout << heap[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;

  insert(heapTree, 5);
  printArray(heapTree);
  insert(heapTree, 2);
  printArray(heapTree);
  insert(heapTree, 4);
  printArray(heapTree);
  insert(heapTree, 9);
  printArray(heapTree);
  
  insert(heapTree, 3);
  printArray(heapTree);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "After deleting an element: ";

  printArray(heapTree);
}
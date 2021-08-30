# Singly-linked list
```Definition```: Like arrays, a linked list is a linear data structure. Unlike arrays, linked list elements are not stored at a contiguous loation; the elements are linked using pointers.
[Source]

Note: [linkedlist] is the compiled C code.


## Singly-linked list pseudocode

### Inserting at the beginning = O(1)
```
1. int val
2. Node temp = node with val
3. Next node of temp = next node of head
4. Head = temp
5. return
```

### Inserting at a specific index ```pos``` = O(n)
```
1. int val, int pos, int i = 0, node temp = head // temp is used to traverse(travel through) the linked list
2. if (pos <= size of linked list) // Only insert a node if the index given is within the size of the linked list
    
    2.1. Node new_node = node with val
    2.2. if (pos != 0) // if the position is not at the head of the list
        2.2.1. for (i < position - 2 ) 
            2.2.1.1. temp = next node of temp
            2.2.1.2. i = i + 1
    
    2.3 Next node of new_node = next node of temp
    2.4 Next node of temp = new_node
    2.5 return
```


### Removing(deleting) a node at a specific index ```pos``` = O(n)
```
1. int i = 0, int pos = position of the node to be removed.
2. node temp = head
3. if (pos <= size of linked list) 
    3.1. if (pos == 0)
        3.1.1. head = next node of temp
        3.1.2. release node
        3.1.3. return
    3.2. for (i < position - 2)
        3.2.1. temp = next node of temp
        3.2.2. i = i + 1
    3.3 temp2 = next node of temp
    3.4 next node of temp = next node of temp2
    3.5 release temp2
    3.6 return
```


<!-- Variable definition -->
[Source]: https://www.geeksforgeeks.org/linked-list-set-1-introduction/
[linkedlist]: https://github.com/Nustree/Data-Structures-And-Algorithms-SCS-2103/blob/main/linkedlist/singlylinkedlist/linkedlist
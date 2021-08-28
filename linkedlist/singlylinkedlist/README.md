# Singly-linked list pseudocode

## Inserting into a linked list

### Inserting at the beginning = O(1)
```
1. int val
2. Node temp = node with val
3. Next node of temp = next node of head
4. Head = temp
```

### Inserting at a specific index ```pos``` = 0(n)
```
1. int val, int pos, node temp = head // temp is used to traverse(travel through) the linked list
2. if (pos <= size of linked list) // Only insert a node if the index given is within the size of the linked list
    
    2.1 Node new_node = node with val
    2.2 if (pos != 0) // if the position is not at the head of the list
         2.2.1 for (i < position -1 ) temp = next node of temp
    
    2.3 Next node of new_node = next node of temp
    2.4 Next node of temp = new_node
```
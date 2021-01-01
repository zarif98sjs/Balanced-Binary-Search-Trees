# **Balanced Binary Search Trees**
 
Implementation of some popular Balanced Binary Search Trees and Performance Comparison

# **Implementation**

- ## [`AVL Tree`](AdelsonVelskyLandisTree.cpp)
- ## [`Red Black Tree`](RedBlackTree.cpp)
- ## [`Splay Tree`](Splay%20Tree.cpp)
- ## [`Treap`](Treap.cpp)



# **Performance Comparison**

Here , `N` is the number of operations (`insert`/`find`/`delete`) .

You can find the `generator` [here](Generator/Gen.cpp) 

![](Time%20Track/time_new.png)

**`Red Black Tree`** is surprisingly _**fastest**_ despite its recursive implementation . **`Treap`** is _**slowest**_ as expected with its high constant factor .
# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

from matplotlib import pyplot as plt 

fig = plt.figure(num=None, figsize=(15, 10), dpi=80, facecolor='w', edgecolor='k')


# IF 
N = [100 ,1000	,10000	,100000	,200000	,300000	,400000	,500000	,600000	,700000,800000	,900000	,1000000]
 
# VT
avl = [0.009	,0.001,	0.008	,0.095,	0.142	,0.235,	0.522,	0.512,	0.591	,0.584,	0.736,	0.87,	0.92]

rbt = [0.008,	0.002	,0.007	,0.071	,0.139,	0.228	,0.297	,0.394	,0.472	,0.522	,0.727	,0.749	,0.751] 
 
treap = [0.007	,0.002	,0.007	,0.074	,0.153	,0.235,	0.365	,0.394	,0.455,	0.538,	1.434	,1.541	,1.666]

mapp = [0.005	,0.001	,0.012	,0.102,	0.224,	0.316	,0.459	,0.559	,0.695,	0.911,	1.105,	1.339	,1.559]

splay = [0.006	,0.002	,0.015,	0.216,	0.227,	0.241,	0.363	,0.382	,0.44	,0.575	,0.63	,0.7,	1.448]

plt.plot(N, avl, c='blue',label = "AVL Tree")
plt.scatter(N, avl, c='blue')

plt.plot(N, rbt, c='red',label = "Red BLack Tree")
plt.scatter(N, rbt, c='red')

plt.plot(N, treap, c='green' , label = "Treap")
plt.scatter(N, treap, c='green')

plt.plot(N, splay, c='purple' , label = "Splay Tree")
plt.scatter(N, splay, c='purple')


plt.plot(N, mapp, c='orange' , label = "STL Map")
plt.scatter(N, mapp, c='orange')


plt.grid(True)
plt.title("Balanced Binary Search Tree Performance Comparison")
plt.xlabel("N")
plt.ylabel("time(s)")

# Function add a legend   
plt.legend() 
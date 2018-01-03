#Solution#

*	第一种方法里面，使用了从begin到end的路径，通过BFS来求解问题。但是会TLE，所以需要two-end的方法来解决问题。
*	第二种方法，就是使用了two-end的方法。
*	从两头开始寻找，直到找到middle，发现相遇之后，得到求解。
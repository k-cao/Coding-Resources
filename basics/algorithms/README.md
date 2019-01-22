# BFS 

A common algorithm for traversing through a graph

Key point: Explore all the nodes at a level before moving on to deeper nodes

## Time Complexity
Worst Case: O(|V| + |E|)

|V| large: O(b<sup>d + 1</sup>) = O(b<sup>d</sup>)
b: average out-degree (branching factor)
d: distance from start

## Space Complexity
Worst Case (|V| known): O(|V|)

|V| large: O(b<sup>d + 1</sup>) = O(b<sup>d</sup>)

# DFS

Another common algorithm for traversing through a graph

Key point: Explores as far as possible before backtracking

## Time Complexity
Worst Case: O(|V| + |E|)

|V| large: O(b<sup>d + 1</sup>) = O(b<sup>d</sup>)
b: average out-degree (branching factor)
d: distance from start

## Space Complexity
Worst Case (|V| known): O(|V|)

|V| large: O(longest path len searched) = O(bd)

# Quicksort

A divide and conquer sorting algorithm

Key point: Choose pivot, partition elems so that:
* elems < pivot are before pivot and 
* elems > pivot are after pivot

## Time Complexity
Worst Case: O(n<sup>2</sup>)
Pivot always is the smallest / largest elem

## Space Complexity
Worst Case (in-place): O(log n)

# Mergesort

Another divide and conquer sorting algorithm

Key point: Sort sub-arrays

## Time Complexity
Worst Case: O(nlog n)

## Space Complexity
Worst Case: O(n)

# Binary Search

Search algorithm

Key point: Assume sorted array, compare elem to middle elem and zoom in

## Time Complexity
Worst Case: O(log n)

## Space Complexity
Worst Case: O(1)

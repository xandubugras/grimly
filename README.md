# grimly
Find the shortest path to solve a maze

# testing it
Make && ./grimly name_of_map1 name_of_map2 ...
or
./grimly and write on the stdin
or
cat name_of_map | ./grimly 

# How it works
The algorithm uses BFS with a couple improvements to run faster.

Initially the algorithm reads the input and checks for errors. Error considered are: 
∗ All lines must respect the sizes given in the first line (LINExCOL).
∗ There can only be one entrance.
∗ There must be at least one exit.
∗ There must be a solution to the labyrinth.
∗ The labyrinth will not be more than a billion square.
∗ At the end of each line, there is a new line.
∗ The characters present in the card must be only those shown on the first
line.
* file doesn't open

Sequentially, starts from the entrance and enqueues all adjacent "empty" spots,
and write their respective position relative to the "father" (in the first case, the entrance).
The while loop repeats that until there are no spots left (empty queue) or the spot being currently evaluated is adjacent to an exit.
If the first case, returns an error. The second, it follows back the number path to draw the map properly. 

improvements: Queue implemented with double linked list, and memory saving by using numbers to guide the path drawing

Using BFS instead of simple backtracking (first try) made it O(n) rather than O(n*n).

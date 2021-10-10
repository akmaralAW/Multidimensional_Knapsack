# Multidimensional_Knapsack
Task: Design a dynamic programming algorithm that takes a tuple {(damage, red, blue), (damage, red, blue), ...} as an input. Play cards so the total amount of damage is maximized, while having limited red, blue cards.

Solution: 0/1 Knapsack based solution. Table has nxredxblue dimension. T[i, j, k] - "maximum damage value" of j-th red, k-th blue, considering all values from 0 to i-th participant. 

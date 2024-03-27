# Advent of Code

My submission written in C can be compiled with GCC, no additional flags are needed. Submissions written in Python can be executed directly using the Python interpreter.

### Day 1

For the first half of the puzzle, I decided to write my submission in **C**. While this initially worked out, I quickly realized that the scalability of C to include **word numbers** wouldn't suffice for my second submission, so I switched to **Python**.

Some of the optimizations I was able to introduce when transitioning includes:

-   Storing the digits inside an array as oppose to only two variables. This cleaned up my loop quite a bit as obtaining the first and last digit only required me to get the first and last index of the array, as oppose to checking against two separate variables on each iteration.
-   The buffers I defined in C has a fixed limit, as allocating memory to store dynamically sized data was out of the scope for this challenge. In Python, arrays by default can grow dynamically, which leaves it less error prone to different input samples.

Command line arguments:

```
./1-trebuchet <input_file>
py 1-trebuchet-pt2.py <input_file>
```

#!/usr/bin/env python

import sys
file1 = open('input.txt', 'r') 
values = [int(x) for x in ' '.join(file1.readlines()).split()]

[rows, cols, target] = values[:3]
matrix = values[3:]

# reshape the matrix into 2D, with the first dimension being lower
if rows <= cols:
    matrix = [[matrix[r*cols+c] for c in range(0,cols)] for r in range(0,rows)]
else:
    matrix = [[matrix[r*cols+c] for r in range(0,rows)] for c in range(0,cols)]
    rows,cols = cols,rows

sums = []
for r in range(0,rows+1):
    sums += [[0] * cols]
for c in range(0,cols):
    for r in range(0, rows):
        sums[r+1][c] = sums[r][c] + matrix[r][c]

MAX = 2**63 - 1
answer = MAX
for height in range(1, rows+1):
    for r in range(0, rows-height+1):
        # the sum of each column for `height` rows starting at `r`
        csums = [sums[r+height][c]-sums[r][c] for c in range(0,cols)]

        sum = 0
        partials = []
        best = MAX
        value_at = lambda i: sum + partials[i][1]

        for c in range(0, cols):
            sum += csums[c]
            delta = csums[c] - sum

            # partials tracks, for each column, the sum we get by adding from
            # that partial to the current running sum. this loop discards any
            # sums that are less than the one we're about to add, because they
            # can never be an answer. it also makes the sums generated for
            # each element in `partials` monotonically increasing, which means
            # we can binary search it in the next step    
            while partials and partials[-1][1] <= delta:
                partials = partials[:-1]
            partials += [(c, delta)]

            if value_at(0) < target:
                continue

            l = 0
            h = len(partials) - 1
            while h - l > 1:
                m = int((h + l) / 2)
                if value_at(m) >= target:
                    l = m
                else:
                    h = m

            if value_at(h) < target:
                h -= 1

            best = min(best, c - partials[h][0] + 1)
            
        if best != MAX:
            answer = min(answer, best * height)

print(answer if answer != MAX else -1)

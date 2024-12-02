// AOC 2024 results in C
// @chadsy
// Copyright (C) 2024 Chad Royal
// MIT License http://opensource.org/licenses/MIT

// Day 1
// The one about reconciling lists of locations (ints) and their distance apart
//
// Part 1:
// Looks like creating two lists, left and right of pair, sorting them
// (smallest to largest), then abs(diff) each. Sum the diffs.
//
// Part 2:
// Count the number of occurrences of a given number in right list, then sum
// the counts of in the right of the values in the left list.

#include "aoc24.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define MAX_LOCATIONS       1000
#define MAX_VALUES          100000
typedef int location;

int comp_answer_desc(const void *a, const void *b) {
      return (((answer_t *)a)->val - ((answer_t *)b)->val);
}

bool day01_solver(arguments *args) {
    char *buf = calloc(BUFSIZ, sizeof(char));
    location *lefts = calloc(MAX_LOCATIONS, sizeof(location));
    location *rights = calloc(MAX_LOCATIONS, sizeof(location));

    if (!buf || !lefts || !rights) {
        fprintf(stderr, "Error allocating memory");
        free(buf);
        free(lefts);
        free(rights);
        return false;
    }

    int cur = 0;

    // part 1
    while (fgets(buf, BUFSIZ * sizeof(char), args->input) && cur < MAX_LOCATIONS) {
        if (!strlen(trim(buf)))
            continue;

        int l = 0, r = 0;
        if (sscanf(buf, "%d %d", &l, &r) == 2) {
            lefts[cur] = l;
            rights[cur] = r;
            cur++;
        }
        else {
            fprintf(stderr, "Unrecognized input, line %d: %s\n", cur, buf);
            free(buf);
            free(lefts);
            free(rights);
            return false;
        }
    }

    qsort(lefts, cur, sizeof(*lefts), comp_answer_desc);
    qsort(rights, cur, sizeof(*rights), comp_answer_desc);

    int sum = 0;
    for (int i = 0; i < cur; i++) {
        int diff = abs(lefts[i] - rights[i]);
        sum += diff;
    }

    args->actual[0].val = sum;

    // Part 2
    location *counts = calloc(MAX_VALUES, sizeof(location));
    for (int i = 0; i < cur; i++) {
        counts[rights[i]]++;
    }
    sum = 0;
    for (int i = 0; i < cur; i++) {
        sum += lefts[i] * counts[lefts[i]];
    }

    args->actual[1].val = sum;

    free(buf);
    free(lefts);
    free(rights);
    free(counts);

    return true;
}

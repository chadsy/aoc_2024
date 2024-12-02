// AOC 2024 results in C
// @chadsy
// Copyright (C) 2024 Chad Royal
// MIT License http://opensource.org/licenses/MIT

// Day 1
// The one about making a template
//
// Part 1:
//
// Part 2:

#include "aoc24.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define MAX_LOCATIONS       1000
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

    // part 1
    args->actual[0].val = 0;

    // Part 2
    args->actual[1].val = 0;

    free(buf);
    free(lefts);
    free(rights);

    return true;
}

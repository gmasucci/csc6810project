#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#include <float.h>

/*
    Some useful Macros
*/
#define EPSILON     0.001
#define BETA_ZERO   1.0
#define GAMMA       0.8
#define ALPHA_ZERO  0.01

typedef struct _ff
{
    double *params;
    double val;
} ffly;

/*
    Our type declarations
*/
typedef struct _ffp
{
    size_t nfflies;
    size_t nparams;
    ffly *flies;
} ffly_population;

/*
    This will allow for different functions to be passed in for evaluation
*/
typedef double (*obj_func)(const ffly*, const size_t nparams);


/******************************************
    OPTIMIZATION FUNCTIONS
    These will run with the given parameters
****************************************/

/*
    Vanilla Firefly Optimization Algorithm
*/
void
ffa(const size_t nfireflies, const size_t niteration, const size_t nparams,
    const double mins[], const double maxs[], obj_func f);

/*
    Firefly + SA  Optimization Algorithm
*/
void
ffasa(const size_t nfireflies, const size_t niteration, const size_t nparams,
      const double mins[], const double maxs[],  obj_func f);



/******************************************
    TEST FUNCTIONS
    These will run until the flies really aren't moving
    much anymore and return the function evaluation count
****************************************/

/*
    Vanilla Firefly Optimization Algorithm TEST FUNCTION
*/
size_t
test_ffa(const size_t nfireflies, const size_t nparams,
         const double mins[], const double maxs[], obj_func f);

/*
    Firefly + SA  Optimization Algorithm  TEST FUNCTION
*/
size_t
test_ffasa(const size_t nfireflies, const size_t nparams,
           const double mins[], const double maxs[],  obj_func f);

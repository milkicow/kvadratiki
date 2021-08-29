///@file quadric.h
#ifndef QUADRIC_H
#define QUADRIC_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// static const int Infinity = -1;

const int Infinity = -1;
const double Precision = 1e-6;


//------------------------------------------------------------------------------
//! Solves a square equation: ax^2 + bx + c = 0 
//!
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 pointer to the first root
//! @param [out] x2 pointer to the second root
//! 
//! @return number of roots
//!
//! @note if an infinite number of solutions then returns Infinity
//! @note if coef a do not equal to zero
//-----------------------------------------------------------------------------

int SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2);

//-----------------------------------------------------------------------------
//! Solves a linear equastion: bx + c = 0
//!
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x x pointer to the root
//!
//! @return number of roots
//!
//! @note if an infinite number of solutions then returns Infinity
//! 
//-----------------------------------------------------------------------------

int SolveLinearEquation(double b, double c, double* x);

//-----------------------------------------------------------------------------
//! Solves a square equation: ax^2 + bx + c = 0 for any entered values
//!
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 pointer to the first root
//! @param [out] x2 pointer to the second root
//! 
//! @return number of roots
//!
//! @note if an infinite number of solutions then returns Infinity
//-----------------------------------------------------------------------------

int EquationSol(double a, double b, double c, double* x1,double* x2);

//-----------------------------------------------------------------------------
//! Compare number with zero
//!
//! @param [in] n n - comparable number
//!
//! @return true if number equals to 0, false if number do not equal to 0
//!
//-----------------------------------------------------------------------------

bool IsZero(double n);

//--------------------------------------------------------------------------------------------------
//! Tests a program for solving a quadratic equation, function indicates to errors that program did
//!
//! @return true if test passed without errors and false if test did not pass
//!
//---------------------------------------------------------------------------------------------------

bool Test();

//-----------------------------------------------------------------------------
//! Compares two numbers a and b for equality
//!
//! @param a [in] a - comparable number
//! @param b [in] b - another comparable number
//!
//! @return true if numbers equal, false if numbers do not equal 
//!
//-----------------------------------------------------------------------------

bool IsEqual(double a, double b);

//--------------------------------------------------------------------------------------------
//! Prints that you failed test, counts failed tests
//!
//! @param flag [in, out] flag - correct test execution marker, shows that a program was wrong
//! @param current_test [in, out] current_test - test counter
//! @param fail_tests [in, out] fail_tests - fail tests counter
//! @param nroots [in] nroots - shows number of solutions received
//! @param num_of_roots [in] num_of_roots - real number of roots
//---------------------------------------------------------------------------------------------

void FailedTest(bool* flag, int current_test, int* fail_tests, int nroots, int num_of_roots);

//--------------------------------------------------------------------------------------------
//! Cleans up clipboard
//--------------------------------------------------------------------------------------------


void ClearBuf();

//--------------------------------------------------------------------------------------------
//! Prints roots of square equation
//!
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//!
//--------------------------------------------------------------------------------------------


void PrintAnswer(double a, double b, double c);


//--------------------------------------------------------------------------------------------
//! Prints errors when function testing program
//! 
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [in] x1 the first root that program counted up
//! @param [in] x2 the second root that program counted up
//! @param [in] nroots number of roots that program counted up 
//! @param [in] num_of_roots true number of roots
//! @param [in,out] flag flag - correct test execution marker, shows that a program was wrong
//! @param [in, out] current_test - test counter
//! @param [in, out] fail_tests - fail tests counter
//! @param [in] r1 a true root
//! @param [in] r2 a true root
//!
//--------------------------------------------------------------------------------------------

void CheckAnswer(int nroots, int num_of_roots, double a, double b, double c, double x1, double x2, bool* flag, int* current_test, int* fail_tests, double r1, double r2);



#endif 



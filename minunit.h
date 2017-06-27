/*//
//  minunit.h
//  TXBRPG
//
//  Created by Hector Denis on 15/06/2017.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef minunit_h
#define minunit_h

/* Explanation
 mu_assert: if test is 0 (fail), then !0 is 1, then return message to caller (usually mu_run_test).
 mu_run_test: call a fonction, then increment test number. Receives the error message from the function, then returns it to the first caller if message isnt null.
 mu_tests_run: number of ran tests
 */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); mu_tests_run++; \
if (message) return message; } while (0)
extern int mu_tests_run;




/* --- --- --- DOCUMENTATION TEMPLATES --- --- --- */
/* --- --- FUNCTION TEMPLATE --- --- */

/*
 Version:
 Changes:
 Goal:
 Params:
 Modif:
 Return:
 Comment:
 */

/* --- --- INCLUDE TEMPLATE --- --- */


#endif /* minunit_h */

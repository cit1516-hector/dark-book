/*//
//  hpl_rand.h
//  TXBRPG
//
//  Created by Hector Denis on 30/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_rand_h
#define hpl_rand_h

#include <stdlib.h>
#include <time.h>

/*
 Version: 1.0.0
 Changes: None.
 Goal: Return a random number in range [min;max].
 Params: #1 min: minimal number generated.
         #2 max: maximal number generated.
 Modif: None.
 Return: Random number in range [min;max].
 Comment: See: "http://c-faq.com/lib/randrange.html"
 */
long hpl_RandRange(long min, long max);

#endif /* hpl_rand_h */

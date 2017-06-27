/*//
//  hpl_rand.c
//  TXBRPG
//
//  Created by Hector Denis on 30/04/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_rand.h"

long hpl_RandRange(long min, long max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

/*//
//  hpl_bool.h
//  TXBRPG
//
//  Created by Hector Denis on 03/06/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#ifndef hpl_bool_h
#define hpl_bool_h

enum hpl_Bool {
    hpl_false = 0,
    hpl_true = !hpl_false
};
typedef enum hpl_Bool hpl_Bool;
/* Creates a bool type. */

#endif /* hpl_bool_h */

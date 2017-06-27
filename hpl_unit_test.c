/*//
//  hpl_unit_test.c
//  TXBRPG
//
//  Created by Hector Denis on 08/06/17.
//  Copyright © 2017 Hector Denis. All rights reserved.
//*/

#include "hpl_unit_test.h"
int mu_tests_run = 0;

static char* hpl_UnitTestAlloc(void){
    int* p = NULL;
    mu_assert("unable to alloc", (p = hpl_Malloc(sizeof(int) * 64)));
    hpl_FreeNull((void**)&p);
    mu_assert("p is not null", p == NULL);
    return NULL;
}

static char* hpl_UnitTestRead(void) {
    char str[32] = "";
    const int base = 10;
    
    long l = 0;
    unsigned long ul = 0;
    int i = 0;
    unsigned int ui = 0;
    double d = 0;
    float t = 0;
    int a = 0;
    
    
    FILE* f = fopen("ut.txt", "r+");
    mu_assert("file couldnt be read", 1 == hpl_FilePrintFromTo(f, stdout));
    putc('\n', stdout);
    /*Reads at most n-1 chars, so 4.*/
    mu_assert("bad read strin", 2 == hpl_ReadString(str, 5, f));
    mu_assert("incorrect string value", 0 == strcmp("Hect", str));
    mu_assert("char isnt 5", '5' == getc(f));
    mu_assert("stream is null", 1 == hpl_StreamClear(f));
    
    mu_assert("bad read long", 1 == hpl_ReadLong(&l, base, f));
    mu_assert("incorrect long", 13 == l);
    mu_assert("bad read ulong", 1 == hpl_ReadUnsignedLong(&ul, base, f));
    mu_assert("incorrect ulong", 9000 == ul);
    
    mu_assert("bad read int", 1 == hpl_ReadInt(&i, base, f));
    mu_assert("incorrect int", -101 == i);
    mu_assert("bad read uint", 1 == hpl_ReadUnsignedInt(&ui, base, f));
    mu_assert("incorrect uint", 101 == ui);
    
    mu_assert("bad read double", 1 == hpl_ReadDouble(&d, f));
    mu_assert("incorrect double", 3.14 == d);
    
    mu_assert("bad read float", 1 == hpl_ReadFloat(&t, f));
    mu_assert("incorrect float", -6.28F == t);
    
    mu_assert("bad yesno read", 1 == hpl_ReadYesNo(&a, f, "", stdout));
    mu_assert("didnt read yes", 1 == a);
    mu_assert("bad yesno read", 1 == hpl_ReadYesNo(&a, f, "", stdout));
    mu_assert("didnt read yes", -1 == a);
    mu_assert("bad yesno read", 1 == hpl_ReadYesNo(&a, f, "", stdout));
    mu_assert("didnt read yes", -1 == a);
    
    fclose(f);
    return NULL;
}
static char* hpl_UnitTestMatrix(void) {
    long lin = 10, col = 5;
    Matrix* mx = hpl_MatrixAlloc(lin, col);
    mu_assert("matrix alloc fail", NULL != mx);
    mu_assert("matrix fill params", 1 == hpl_MatrixFill(mx, 7));
    mu_assert("matrix print params", 1 == hpl_MatrixPrint(mx, stdout));
    mu_assert("null or lin size", 1 == hpl_MatrixFree(mx, lin));
    mu_assert("should fail, param -n", NULL == hpl_MatrixAlloc(-1, col));
    mu_assert("should fail, param null", -1 == hpl_MatrixPrint(NULL, stdout));
    mu_assert("should fail, mx null", -1 == hpl_MatrixFree(NULL, lin));
    return NULL;
}
static char* hpl_UnitTestString(void) {
    char s[32] = "Hello, World!";
    mu_assert("str upper return", 1 == hpl_StrUpper(s));
    mu_assert("str upper value", 0 == strcmp(s, "HELLO, WORLD!"));
    mu_assert("str lower return", 1 == hpl_StrLower(s));
    mu_assert("str lower value", 0 == strcmp(s, "hello, world!"));
    mu_assert("str clear return", 1 == hpl_StrClear(s, sizeof(s)));
    mu_assert("str clear value", 0 == strncmp(s, "", 32));
    return NULL;
}

static char* hpl_UnitTestStringStruct(void) {
    String* str = NULL;
    char turtles[] = "Turtles are fun!";
    mu_assert("string malloc fail", NULL != (str = hpl_StringAlloc(77)));
    strncpy(str->str, turtles, str->wri);
    mu_assert("string bad copy", NULL != strncpy(str->str, turtles, str->wri));
    mu_assert("string printinfo", 1 == hpl_StringPrintInfo(str, stdout));
    mu_assert("string free fail", 1 == hpl_StringFree(str));
    
    /* Do not try this one :
     mu_assert("string malloc should fail", NULL == (str = hpl_StringAlloc((size_t)-64))); */
    mu_assert("string printinfo should fail: stream", -1 == hpl_StringPrintInfo(str, NULL));
    mu_assert("string printinfo should fail: string", -1 == hpl_StringPrintInfo(NULL, stdout));
    mu_assert("string free should fail", -1 == hpl_StringFree(NULL));
    return NULL;
}

#define TABSIZE (10L)
#define NUMGENERATE (1000L)
/* Works best with TABSIZE < NUMGENERATE. */
static char* hpl_UnitTestRand(void) {
    unsigned long tab [TABSIZE] = {0};
    unsigned long moy = 0;
    size_t i = 0;
    
    for (i = 0; i < NUMGENERATE; i++) {
        tab[hpl_RandRange(0, TABSIZE-1)]++;
    }
    
    fprintf(stdout, "TABSIZE:%8ld\n", TABSIZE);
    for (i = 0; i < TABSIZE; i++) {
        fprintf(stdout, "%3zu:%9lu\n", i, tab[i]);
        moy += tab[i];
    }
    moy /= TABSIZE;
    fprintf(stdout, "MOYN:%8lu\n", moy);
    return NULL;
}

static char* hpl_UnitTestBool(void) {
    mu_assert("false isnt 0?", 0 == hpl_false);
    mu_assert("!0 isnt 1?", 1 == !hpl_false);
    mu_assert("true isnt true?", hpl_true);
    mu_assert("!1 isnt false?", 0 == !hpl_true);
    return NULL;
}
static char* hpl_UnitTestAll(void) {
    /*Keep order in sync with actual code.*/
    mu_run_test(hpl_UnitTestAlloc);
    mu_run_test(hpl_UnitTestRead);
    mu_run_test(hpl_UnitTestMatrix);
    mu_run_test(hpl_UnitTestString);
    mu_run_test(hpl_UnitTestStringStruct);
    mu_run_test(hpl_UnitTestRand);
    mu_run_test(hpl_UnitTestBool);
    return NULL;
}

int hpl_UnitTestMain(void) {
    char *error = NULL;
    printf("a");
    error = hpl_UnitTestAll();
    if (NULL != error) {
        fprintf(stdout, "ERROR: %s.\n", error);
    }
    else {
        fprintf(stdout, "ALL TESTS PASSED SUCCESSFULLY.\n");
    }
    fprintf(stdout, "Tests run: %d\n", mu_tests_run);
    
    return NULL != error;
    /*error == NULL ? 0 : 1*/
}

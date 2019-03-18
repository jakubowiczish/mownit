#include <stdio.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_cblas.h>
#include <math.h>


/*
 * Zadanie 3
 * Jedną z bibliotek numerycznych, jaką będziemy używać na zajęciach jest GSL (język C).
 * Korzystając ze wsparcia dla wyświetlania reprezentacji liczb zmiennoprzecinkowych
 * zobaczyć jak zmienia się cecha i mantysa dla coraz mniejszych liczb.
 * Zaobserwować, kiedy matysa przestaje być znormalizowana i dlaczego?
 */
//int main() {
//    float f = 1.0;
//
//    for (int i = 0; i < 200; ++i) {
//        f /= 2;
//        gsl_ieee_printf_float(&f);
//        puts("\n");
//    }
//
//    return 0;
//}
// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S5813A_00000058.cpp
// BSL              : 00000058
// Model number     : ABLIC S-5813A, S-5814A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 28/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "S5813A.h"

AnalogIn S5813A_adc( iS5813A_pin , iVref );             // AnalogIn object

// Main Function
pp2ap_adc_t S5813A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( S5813A_adc , tbl_S5813A );
        return( res );
}

// License       : License.txt
// Specifications: Spec-S-5813A_5814A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S5813A.h
// Reason for change: 01.00.00 : 28/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __S5813A_H__
#define __S5813A_H__

#include "user_define.h"

// Components number
#define iS5813A                 104U                    // ABLIC S-5813A, S-5814A

// S-5813A, S-5814A System Parts definitions
#define iS5813A_xoff            1.940F                  // X offset [V]
#define iS5813A_yoff            30.0F                   // Y offset [degree celsius]
#define iS5813A_gain            -0.01104F               // Gain [V/degree celsius]
#define iS5813A_max             100.0F                  // Temperature Max [degree celsius]
#define iS5813A_min             -30.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_S5813A;

#endif /*__S5813A_H__*/

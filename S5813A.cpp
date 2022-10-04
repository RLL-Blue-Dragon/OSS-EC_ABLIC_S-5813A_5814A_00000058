// License       : License.txt
// Specifications: Spec-S-5813A_5814A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S5813A.cpp
// Reason for change: 01.00.00 : 28/09/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "S5813A.h"

#if     iS5813A_ma == iSMA                              // Simple moving average filter
static float32 S5813A_sma_buf[iS5813A_SMA_num];
static sma_f32_t S5813A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iS5813A_SMA_num ,                               // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &S5813A_sma_buf[0]                              // buffer
};

#elif   iS5813A_ma == iEMA                              // Exponential moving average filter
static ema_f32_t S5813A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iS5813A_EMA_K                                   // Exponential smoothing factor 
};

#elif   iS5813A_ma == iWMA                              // Weighted moving average filter
static float32 S5813A_wma_buf[iS5813A_WMA_num];
static wma_f32_t S5813A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iS5813A_WMA_num ,                               // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iS5813A_WMA_num * (iS5813A_WMA_num + 1)/2 ,     // kn sum
        &S5813A_wma_buf[0]                              // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_S5813A =
{
        iS5813A                 ,
        iS5813A_pin             ,
        iS5813A_xoff            ,
        iS5813A_yoff            ,
        iS5813A_gain            ,
        iS5813A_max             ,
        iS5813A_min             ,
        iS5813A_ma              ,
        
#if     iS5813A_ma == iSMA                              // Simple moving average filter
        &S5813A_Phy_SMA         ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iS5813A_ma == iEMA                              // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &S5813A_Phy_EMA         ,
        (wma_f32_t*)iDummy_adr
#elif   iS5813A_ma == iWMA                              // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &S5813A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};

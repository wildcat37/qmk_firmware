#pragma once

#include "quantum.h"

#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
      k00,      k11, k12, k13,      k14,   \
	            k21, k22, k23,             \
	  k30,      k31, k32, k33,      k34,   \
	k45, k46,   k47, k48, k49,   k410, k411, \
	k55, k56,   k57, k58, k59,   k510, k511, \
	  k66,      k67, k68, k69,   k610, k611, \
	  k76,      k77, k78, k79,      k710    \
) \
{ \
    { k00, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
	{ ___, k11, k12, k13, k14, ___, ___, ___, ___, ___, ___, ___ }, \
	{ ___, k21, k22, k23, ___, ___, ___, ___, ___, ___, ___, ___ }, \
	{ k30, k31, k32, k33, k34, ___, ___, ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___, k45, k46, k47, k48, k49, k410, k411 }, \
	{ ___, ___, ___, ___, ___, k55, k56, k57, k58, k59, k510, k511 }, \
	{ ___, ___, ___, ___, ___, ___, k66, k67, k68, k69, k610, k611 }, \
	{ ___, ___, ___, ___, ___, ___, k76, k77, k78, k79, k710, ___ }   \
}


/*
This is the matrix
Along with the pins for each row and column
             P??   P??  P??  P?? P??   P?? P?? P?? P?? P?? P??  P??
             kx0   kx1  kx2  kx3 kx4   kx5 kx6 kx7 kx8 kx9 kx10 kx11
P?? k0x Row: YOURS --   --   --  --    --  --  --  --  --  --   --  
P?? k1x Row: --    F7   F8   F9  MINE  --  --  --  --  --  --   --     
P?? k2x Row: --    F10  F11  F12 --    --  --  --  --  --  --   --   
P?? k3x Row: BID   HOLD DEAL REL OFFER --  --  --  --  --  --   --   
P?? k4x Row: --    --   --   --  --    UP  DN  7   8   9   LEND REND
P?? k5x Row: --    --   --   --  --    L   R   4   5   6   CHGP SPCE
P?? k6x Row: --    --   --   --  --    --  CXI 1   2   3   QUIT MENU
P?? k7x Row: --    --   --   --  --    --  CXA 0   .   DEL TXR  --

LEND = Left end
REND = Right end
CHGP = Chng Prop
SPCE = Space
CXI = Cancel Instrument
CXA = Cancel All
DEL = backspace
TXR = Transmit
*/

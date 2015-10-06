//******************************************************************************
//*
//*     FULLNAME:  Single-Chip Microcontroller Real-Time Operating System
//*
//*     NICKNAME:  scmRTOS
//*
//*     PROCESSOR: ADSP-BF533 (Analog Devices)
//*
//*     TOOLKIT:   VDSP (Analog Devices)
//*
//*     PURPOSE:   Port Test File (low-level stuff for terminal support)
//*
//*     Version: 5.0.0
//*
//*
//*     Copyright (c) 2003-2015, scmRTOS Team
//*
//*     Permission is hereby granted, free of charge, to any person 
//*     obtaining  a copy of this software and associated documentation 
//*     files (the "Software"), to deal in the Software without restriction, 
//*     including without limitation the rights to use, copy, modify, merge, 
//*     publish, distribute, sublicense, and/or sell copies of the Software, 
//*     and to permit persons to whom the Software is furnished to do so, 
//*     subject to the following conditions:
//*
//*     The above copyright notice and this permission notice shall be included 
//*     in all copies or substantial portions of the Software.
//*
//*     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
//*     EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
//*     MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
//*     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
//*     CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
//*     TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
//*     THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//*
//*     =================================================================
//*     See http://scmrtos.sourceforge.net for documentation, latest
//*     information, license and contact details.
//*     =================================================================
//*
//******************************************************************************
//*     MSP430/IAR sample by Harry E. Zhurov, Copyright (c) 2012-2015

#ifndef UART_DEV_H
#define UART_DEV_H

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <scmRTOS.h>


namespace UART
{
    void init();
    void send(const char  c);
    void send(const char *s);
}

const uint16_t TX_BUF_SIZE = 256;
const uint16_t RX_BUF_SIZE = 64;

INLINE void enable_tx_int()  { IE2 |= UTXIE1;  }
INLINE void disable_tx_int() { IE2 &= ~UTXIE1; }
INLINE void enable_rx_int()  { IE2 |= URXIE1;  }
INLINE void disable_rx_int() { IE2 &= ~URXIE1; }

extern usr::ring_buffer<char, TX_BUF_SIZE, uint16_t> TxBuf;
extern OS::TEventFlag NewLineIncoming;
extern char RxBuf[RX_BUF_SIZE];

#endif // UART_DEV_H
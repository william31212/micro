#include <nds32_intrinsic.h>
#include "WT58F2C9.h"

/* It will use Default_Handler if you don't have one */
#pragma weak tlb_exception_handler 	= Default_Handler
#pragma weak error_exception_handler 	= Default_Handler
#pragma weak syscall_handler 		= Default_Handler
#pragma weak HW0_ISR 			= Default_Handler
#pragma weak HW1_ISR 			= Default_Handler
#pragma weak HW2_ISR 			= Default_Handler
#pragma weak HW3_ISR 			= Default_Handler
#pragma weak HW4_ISR 			= Default_Handler
#pragma weak HW5_ISR 			= Default_Handler
#pragma weak SW0_ISR 			= Default_Handler

__attribute__((unused))
static void Default_Handler()
{
	while (1) ;
}

void __null_function()
{
}

void __c_init()
{
/* Use compiler builtin memcpy and memset */
#define MEMCPY(des, src, n)	__builtin_memcpy ((des), (src), (n))
#define MEMSET(s, c, n)		__builtin_memset ((s), (c), (n))

	extern char _end;
	extern char __bss_start;
	int size;

	extern char __data_lmastart;
	extern char __data_start;
	extern char _edata;
	/* Copy data section to RAM */
	size = &_edata - &__data_start;
	MEMCPY(&__data_start, &__data_lmastart, size);

	/* Clear bss section */
	size = &_end - &__bss_start;
	MEMSET(&__bss_start, 0, size);
	return;
}

void __attribute__ ((optimize("Os"))) __cpu_init()
{

	unsigned int tmp;

	/* turn on BTB */
	tmp = 0x0;
	__nds32__mtsr(tmp, NDS32_SR_MISC_CTL);

#if defined(NDS32_BASELINE_V3M) && defined(USE_C_EXT)
	/* set IVIC, vector size: 16 bytes, base: 0x0
	 * If we use v3m toolchain and want to use
	 * C extension please use USE_C_EXT in CFLAGS
	 */
	__nds32__mtsr(0x4001, NDS32_SR_IVB);
#else
	/* set IVIC, vector size: 4 bytes, base: 0x0
	 * If we use v3m toolchain and want to use
	 * assembly version please don't use USE_C_EXT
	 * in CFLAGS */
	__nds32__mtsr(0x0, NDS32_SR_IVB);
#endif
	/* Set PSW INTL to 0 */
	tmp = __nds32__mfsr(NDS32_SR_PSW);
	tmp = tmp & 0xfffffff9;
#if (defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* Set PSW CPL to 7 to allow any priority */
	tmp = tmp | 0x70008;
#endif
	__nds32__mtsr(tmp, NDS32_SR_PSW);
	__nds32__dsb();
#if (defined(NDS32_BASELINE_V3M) || defined(NDS32_BASELINE_V3))
	/* Set PPL2FIX_EN to 0 to enable Programmable 
	 * Priority Level */
	__nds32__mtsr(0x0, NDS32_SR_INT_CTRL);
	/* set priority HW0: 0, HW1: 1, HW2: 2, HW3: 3 
	 * HW4-: 0 */
	__nds32__mtsr(0xe4, NDS32_SR_INT_PRI);
#endif
	return;
}

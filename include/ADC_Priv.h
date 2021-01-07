#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

typedef struct
{
	volatile u32 ADC_SR;
	volatile u32 ADC_CR1;
	volatile u32 ADC_CR2;
	volatile u32 ADC_SMPR1;
	volatile u32 ADC_SMPR2;
	volatile u32 ADC_JOFR1;
	volatile u32 ADC_JOFR2;
	volatile u32 ADC_JOFR3;
	volatile u32 ADC_JOFR4;
	volatile u32 ADC_HTR;
	volatile u32 ADC_LTR;
	volatile u32 ADC_SQR1;
	volatile u32 ADC_SQR2;
	volatile u32 ADC_SQR3;
	volatile u32 ADC_JSQR;
	volatile u32 ADC_JDR1;
	volatile u32 ADC_JDR2;
	volatile u32 ADC_JDR3;
	volatile u32 ADC_JDR4;
	volatile u32 ADC_DR;
	
	
}MADC;

#define ADC  ((volatile MADC*)0x40012400)

/*****************************************************************************/
/**************************** ADC SAVE FROM **********************************/
/*****************************************************************************/

#define Right_Adjust 0
#define Left_Adjust  1


/*****************************************************************************/
/******************************** ADC MODE ***********************************/
/*****************************************************************************/
#define ADC_Single_Conversion_Mode  	 0
#define ADC_Continuous_Conversion_Mode	 1










#endif

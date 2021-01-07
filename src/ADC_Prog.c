/******************************************************************/
/*             >>DATE:2/1/2021                                    */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_INT.h"
#include"ADC_Priv.h"
#include"ADC_Config.h"


/****** Global Pointer To Function *********/
static void (*ADC1_GPFunc)(void)=NULL;

void ADC1_SetCallBack(void(*LocPFunc)(void))
{
ADC1_GPFunc=LocPFunc;
}

void MADC_VidINIT(void)
{
	/**set ADON bit in ADC_CR2 to wake up**/
	SET_BIT(ADC->ADC_CR2,0); //ADON
	#if   ADC_Mode==ADC_Single_Conversion_Mode
		/**Single Conversion**/
	       CLR_BIT(ADC->ADC_CR2,1); //CONT
	#elif ADC_Mode==ADC_Continuous_Conversion_Mode
		/**Continuous Conversion**/
	       SET_BIT(ADC->ADC_CR2,1); //CONT
	#endif
	
	#if   ADC_SAVE_FROM==Right_Adjust
		/**Choose Data Eligen**/
	        CLR_BIT(ADC->ADC_CR2,11); //ALIGN
	#elif ADC_SAVE_FROM==Left_Adjust
		/**Choose Data Eligen**/
	        SET_BIT(ADC->ADC_CR2,11); //ALIGN
	#endif

}
void MADC_Start_Conversion(void)
{
	/**Start Convertion**/
	SET_BIT(ADC->ADC_CR2,0); //ADON
	
}
void MADC_Get_Result(u32 *ptr)
{

	while(GET_BIT(ADC->ADC_SR,1)==0);
	*ptr=ADC->ADC_DR;

}
void MADC_Select_Channal(u8 LOC_Channal,u8 LOC_NumOfConversion)
{

ADC->ADC_CR2 &= ~ ( ( 0b1111 )    << ( 20 ));
ADC->ADC_CR2 |= ( LOC_NumOfConversion ) << (20  );
	switch(LOC_NumOfConversion)
	{
	case 16: ADC->ADC_SQR1 |= ( LOC_Channal ) << (15);break;
	case 15: ADC->ADC_SQR1 |= ( LOC_Channal ) << (10);break;
	case 14: ADC->ADC_SQR1 |= ( LOC_Channal ) << (5);break;
	case 13: ADC->ADC_SQR1 |= ( LOC_Channal ) << (0);break;
	case 12: ADC->ADC_SQR2 |= ( LOC_Channal ) << (25);break;
	case 11: ADC->ADC_SQR2 |= ( LOC_Channal ) << (20);break;
	case 10: ADC->ADC_SQR2 |= ( LOC_Channal ) << (15);break;
	case 9 : ADC->ADC_SQR2 |= ( LOC_Channal ) << (10);break;
	case 8 : ADC->ADC_SQR2 |= ( LOC_Channal ) << (5) ;break;
	case 7 : ADC->ADC_SQR2 |= ( LOC_Channal ) << (0) ;break;
	case 6 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (25);break;
	case 5 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (20);break;
	case 4 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (15);break;
	case 3 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (10);break;
	case 2 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (5) ;break;
	case 1 : ADC->ADC_SQR3 |= ( LOC_Channal ) << (0) ;break;
	}
}
void MADC_Interrupt_Enable(void)
{
	/**Interrupt enable for EOC**/
	SET_BIT( ADC->ADC_CR1,5);
	SET_BIT( ADC->ADC_SR,1);
}
void ADC1_2_IRQHandler(void)
{
	if(ADC1_GPFunc!=NULL)
	{
		ADC1_GPFunc();
	}
}

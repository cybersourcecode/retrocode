

ldi   A,0b1110_0011  ;[ADEN,ADSC,ADATE,ADIF,_,ADIE,ADPS2,ADPS1,ADPS0]
sts   ADCSRA,A       ;START ANALOG TO DIGITAL CONVERSION
ldi   A,0b0000_0011  ;SELECT ADC #3 (PORT C 3), BEFORE CLEANING
sts   ADMUX,A

  lds A, ADCL         ;MUST READ ADCL BEFORE ADCH
 lds AH, ADCH        ;REQUIRED, THOUGH NOT USED

Begin:
	 cpi AH, 0
	 breq kontr
 rjmp begin

 kontr:
 cpi A, 102
 brlo null
 cpi A, 204
 brlo one
 rjmp begin

null:
ldi r16, ~0x3F
out portd, r16
rcall sevendisp   
rjmp mux

one:

ldi r17, 0x06
out portd, r17
rcall sevendisp  
rjmp begin


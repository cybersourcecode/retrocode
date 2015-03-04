ldi r16, 0x00
 out portd, r16
 sbi portb, 6       
cbi portb, 6

clr r25  

Knopki:
ldi r16, 0b1011_1111                        
out portd, r16         
nop
in r17, pinc                      
andi r17, 0x04                                                  
breq tuletamine

ldi r16, 0b1011_1111
out portd, r16      
nop
in r17, pinc
andi r17, 0x02 
breq tuletamine2

rjmp Knopki

tuletamine:
cpi r25, 0
breq relee1ON
cpi r25, 32
breq relee12ON
cpi r25, 64 
breq relee1OFF
cpi r25, 96
breq relee11OFF

rjmp Knopki

tuletamine2:
cpi r25, 0
breq relee2ON
cpi r25, 64 
breq relee12ON
cpi r25, 32
breq relee2OFF   
cpi r25, 96
breq relee22OFF
rjmp knopki

relee1ON:
ldi r25, 64
out portd, r25
rcall relay
rcall aeg
rjmp knopki

relee1OFF:
ldi r25, 0
out portd, r25
rcall relay
rcall aeg
rjmp knopki
///////
relee12ON: //2 rele ON
ldi r25, 96
out portd, r25
rcall relay
rcall aeg
rjmp knopki

relee11OFF:  //esli oba bili vkljucheni i nazimaem knopku 1 to vikl tolko 1
ldi r25, 32
out portd, r25
rcall relay
rcall aeg
rjmp knopki

relee22OFF:  //esli oba bili vkljucheni i nazimaem knopku 2 to vikl tolko 2
ldi r25, 64
out portd, r25
rcall relay
rcall aeg
rjmp knopki
//////

relee2ON:  // vkljuchaem tolko 2 rele
ldi r25, 32
out portd, r25
rcall relay
rcall aeg
rjmp knopki

relee2OFF: //vikljuchaem oba rele
ldi r25, 0
out portd, r25
rcall relay
rcall aeg
rjmp knopki

 relay:
sbi portb, 6       
cbi portb, 6
ret         
 

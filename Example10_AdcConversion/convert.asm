; Convert.asm
; Runs on any Cortex M
; Student version to lab
; Conversion function for a GP2Y0A21YK0F IR sensor
; Jonathan Valvano
; July 11, 2019

; This example accompanies the book
;   "Embedded Systems: Introduction to Robotics,
;   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2019
; For more information about my classes, my research, and my books, see
; http://users.ece.utexas.edu/~valvano/
;
;Simplified BSD License (FreeBSD License)
;Copyright (c) 2019, Jonathan Valvano, All rights reserved.
;
;Redistribution and use in source and binary forms, with or without modification,
;are permitted provided that the following conditions are met:
;
;1. Redistributions of source code must retain the above copyright notice,
;   this list of conditions and the following disclaimer.
;2. Redistributions in binary form must reproduce the above copyright notice,
;   this list of conditions and the following disclaimer in the documentation
;   and/or other materials provided with the distribution.
;
;THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
;LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
;DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
;AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
;OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
;USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;The views and conclusions contained in the software and documentation are
;those of the authors and should not be interpreted as representing official
;policies, either expressed or implied, of the FreeBSD Project.

       .thumb
       .text
       .align 2
       .global Convert

;------------Convert------------
; Calculate the distance in mm given the 14-bit ADC value
; D = 1195172/(n - 1058)
; Input: R0 is n, ADC value, 14-bit unsigned number 2552 to 16383
; Output: R0 is distance in mm
; If the ADC input is less than 2552, return 800 mm
Convert:   .asmfunc
; put your solution here


;      .endasmfunc
;      .align 4
;IRSlope  .word
;IROffset

;    .end


; solution
	LDR R1, IRMax
	CMP	R1, R0
	BGE	TooClose
	LDR R2, IROffset
	LDR R3, IRSlope
	ADD R0, R0, R2	; R0 = n-1058
	UDIV R0, R3, R0
	BX LR
TooClose:
	LDR R0, MaxDist
    BX LR

      .endasmfunc
      .align 4
IRSlope  .word 1195172
IROffset .word -1058
IRMax    .word 2552
MaxDist	 .word 800

    .end
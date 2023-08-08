// Copyright 2021 Michael Floren (Seafoxc)
// https://www.youtube.com/c/seafoxc
// Date 23/05/2021 
// Version 2.0

// Code to link with Factory I/O.
// Note: I have an education as a mechatronics technician and have no formal training in text based languages (but it works). 

#include <Arduino.h>
#include "Modbus.h"
#include "ModbusSerial.h"

//Modbus Object
ModbusSerial modbus;

//ModBus Port information
#define BAUD        115200 // Fastest the Arduino Uno/Nano can go. 
#define ID           0 
#define TXPIN       -1

//Define the number of registers, inputs and coils to be created
#define NUM_DISCRETE_INPUT      0 // can not write with PythonModbus to the Inputs.
#define NUM_INPUT_REGISTERS     0 // can not write with PythonModbus to the Inputregisters.
#define NUM_COILS               32 // 16 for writing Factory IO inputs to and 16 to write to Factory IO
#define NUM_HOLDING_REGISTERS   16 // 8 for writing Factory IO Input register and 16 to write to Factory IO holding register.

//Defining the digital inputs from Factory IO

bool FactoryIO_Input0 = LOW;
bool FactoryIO_Input1 = LOW;
bool FactoryIO_Input2 = LOW;
bool FactoryIO_Input3 = LOW;
bool FactoryIO_Input4 = LOW;
bool FactoryIO_Input5 = LOW;
bool FactoryIO_Input6 = LOW;
bool FactoryIO_Input7 = LOW;
bool FactoryIO_Input8 = LOW;
bool FactoryIO_Input9 = LOW;
bool FactoryIO_Input10 = LOW;
bool FactoryIO_Input11= LOW;
bool FactoryIO_Input12 = LOW;
bool FactoryIO_Input13 = LOW;
bool FactoryIO_Input14 = LOW;
bool FactoryIO_Input15 = LOW;

//Defining the digital outputs coils from Factory IO
bool FactoryIO_Coil0 = LOW;
bool FactoryIO_Coil1 = LOW;
bool FactoryIO_Coil2 = LOW;
bool FactoryIO_Coil3 = LOW;
bool FactoryIO_Coil4 = LOW;
bool FactoryIO_Coil5 = LOW;
bool FactoryIO_Coil6 = LOW;
bool FactoryIO_Coil7 = LOW;
bool FactoryIO_Coil8 = LOW;
bool FactoryIO_Coil9 = LOW;
bool FactoryIO_Coil10 = LOW;
bool FactoryIO_Coil11 = LOW;
bool FactoryIO_Coil12 = LOW;
bool FactoryIO_Coil13 = LOW;
bool FactoryIO_Coil14 = LOW;
bool FactoryIO_Coil15 = LOW;

//Defining the Analog outputs (Holding Reg.) 

word FactoryIO_HoldingReg0 = 0;
word FactoryIO_HoldingReg1 = 0;
word FactoryIO_HoldingReg2 = 0;
word FactoryIO_HoldingReg3 = 0;
word FactoryIO_HoldingReg4 = 0;
word FactoryIO_HoldingReg5 = 0;
word FactoryIO_HoldingReg6 = 0;
word FactoryIO_HoldingReg7 = 0;



word FactoryIO_InputReg0 = 0;
word FactoryIO_InputReg1 = 0;
word FactoryIO_InputReg2 = 0;
word FactoryIO_InputReg3 = 0;
word FactoryIO_InputReg4 = 0;
word FactoryIO_InputReg5 = 0;
word FactoryIO_InputReg6 = 0;
word FactoryIO_InputReg7 = 0;




void FactoryIO_Setup(){

    //Config Modbus Serial (port, speed, rs485 tx pin)
    modbus.config(&Serial, BAUD, TXPIN); //&Serial
    
    //Set the Slave ID
    modbus.setSlaveId(ID); 
    
    //Add all modbus registers
    for (int i = 0; i < NUM_DISCRETE_INPUT; ++i) 
    {
        modbus.addIsts(i);
    }
    for (int i = 0; i < NUM_INPUT_REGISTERS; ++i) 
    {
        modbus.addIreg(i);
    }
    for (int i = 0; i < NUM_COILS; ++i) 
    {
        modbus.addCoil(i);
    }
    for (int i = 0; i < NUM_HOLDING_REGISTERS; ++i) 
    {
        modbus.addHreg(i);
    }
  
}


void FactoryIO_ReadInputs(){
  
    modbus.task();


    FactoryIO_Input0 = modbus.Coil(0); 
    FactoryIO_Input1 = modbus.Coil(1); 
    FactoryIO_Input2 = modbus.Coil(2); 
    FactoryIO_Input3 = modbus.Coil(3);
    FactoryIO_Input4 = modbus.Coil(4);  
    FactoryIO_Input5 = modbus.Coil(5);
    FactoryIO_Input6 = modbus.Coil(6);
    FactoryIO_Input7 = modbus.Coil(7);
    FactoryIO_Input8 = modbus.Coil(8);
    FactoryIO_Input9 = modbus.Coil(9);
    FactoryIO_Input10 = modbus.Coil(10);
    FactoryIO_Input11 = modbus.Coil(11);
    FactoryIO_Input12 = modbus.Coil(12);
    FactoryIO_Input13 = modbus.Coil(13);
    FactoryIO_Input14 = modbus.Coil(14);
    FactoryIO_Input15 = modbus.Coil(15);

    FactoryIO_InputReg0 = modbus.Hreg(8);
    FactoryIO_InputReg1 = modbus.Hreg(9);
    FactoryIO_InputReg2 = modbus.Hreg(10);
    FactoryIO_InputReg3 = modbus.Hreg(11);
    FactoryIO_InputReg4 = modbus.Hreg(12);
    FactoryIO_InputReg5 = modbus.Hreg(13);
    FactoryIO_InputReg6 = modbus.Hreg(14);
    FactoryIO_InputReg7 = modbus.Hreg(15);
}



void FactoryIO_WriteOutputs(){

    // Update modbus registers - writing Digital Outputs
    
    modbus.Coil(16, FactoryIO_Coil0);    
    modbus.Coil(17, FactoryIO_Coil1);
    modbus.Coil(18, FactoryIO_Coil2);
    modbus.Coil(19, FactoryIO_Coil3);
    modbus.Coil(20, FactoryIO_Coil4);
    modbus.Coil(21, FactoryIO_Coil5);
    modbus.Coil(22, FactoryIO_Coil6);
    modbus.Coil(23, FactoryIO_Coil7);
    modbus.Coil(24, FactoryIO_Coil8);
    modbus.Coil(25, FactoryIO_Coil9);
    modbus.Coil(26, FactoryIO_Coil10);
    modbus.Coil(27, FactoryIO_Coil11);
    modbus.Coil(28, FactoryIO_Coil12);
    modbus.Coil(29, FactoryIO_Coil13);  
    modbus.Coil(30, FactoryIO_Coil14);    
    modbus.Coil(31, FactoryIO_Coil15);

    // Update modbus registers - writing Holding register
    
    modbus.Hreg(0,FactoryIO_HoldingReg0);
    modbus.Hreg(1,FactoryIO_HoldingReg1);
    modbus.Hreg(2,FactoryIO_HoldingReg2);
    modbus.Hreg(3,FactoryIO_HoldingReg3);
    modbus.Hreg(4,FactoryIO_HoldingReg4);
    modbus.Hreg(5,FactoryIO_HoldingReg5);
    modbus.Hreg(6,FactoryIO_HoldingReg6);
    modbus.Hreg(7,FactoryIO_HoldingReg7);
}

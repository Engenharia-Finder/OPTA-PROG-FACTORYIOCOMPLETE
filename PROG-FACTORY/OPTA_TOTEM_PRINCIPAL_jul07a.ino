#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/0d08f323-1555-432a-b131-186e73e01a5c 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float sensorValueA0;
  float voltageA0;
  float voltageA1;
  CloudLight emergenciafisico;
  CloudLight m1status;
  CloudLight m2status;
  CloudLight manutencao1;
  CloudLight manutencao2;
  CloudLight reset1;
  CloudLight reset2;
  int contador;
  int contador2;
  int contador3;
  int contador4;
  int motor1luz;
  int motor2luz;
  CloudLocation localizacao;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "Factory_IO.h"
bool motor1 = HIGH;
bool motor2 = HIGH;
bool moveZ = LOW;
bool moveX = LOW;
bool detectado = LOW;
bool Grab = LOW;
bool sensor1 = LOW;
bool sensorZ = LOW;
bool sensorX = LOW;
bool sensor2 = LOW;
bool sensor3 = LOW;
bool sensor4 = LOW;
bool contagem1 = LOW;
bool contagem2 = LOW;
bool conmuta = true;
bool conmuta2 = true;
bool conmuta3 = true;
bool conmuta4 = true;

bool estadoButton = 0;
bool estadobotao1 = 0;
bool estadobotao2 = 0;
bool estadobotao3 = 0;
bool estadobotao4 = 0;
bool estadobotao5 = 0;
bool estadobotao6 = 0;
float teste = 0;
float voltteste = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  FactoryIO_Setup(); 
   pinMode(LED_D0, OUTPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
   pinMode(A5, INPUT);
   pinMode(D0,OUTPUT);
   pinMode(D1,OUTPUT);
   pinMode(D2,OUTPUT);
   pinMode(D3,OUTPUT);
   pinMode(LED_D0,OUTPUT);
   pinMode(LED_D1,OUTPUT);
   pinMode(LED_D2,OUTPUT);
   pinMode(LED_D3,OUTPUT);
   pinMode(BTN_USER, INPUT);
  contador = 0;
  contador2 = 0;
  contador3 = 0;
  contador4 = 0;
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  

ArduinoCloud.update();
  
  sensorValueA0 = analogRead(A6);
  voltageA0 = sensorValueA0 * (3.0 / 4095.0) / 0.3 + 0.827;
  voltteste = voltageA0 * 20;
  voltageA1 = voltteste;
  delay(5);


 double Lat;                               //definição de latitude
 double Long;                              //definição de longitude

  localizacao = {-23.645243709629, -46.62952765397569};          //coordenadas de latitude e longitude


    FactoryIO_ReadInputs();    // Reading the inputs from Factory I/O

    
//--------------------------------------------------------------------------------------------------------
//-------------------------- Here you have place to write your Main program ------------------------------
//--------------------------------------------------------------------------------------------------------
// Digital Inputs : FactoryIO_Input0 , FactoryIO_Input1 ,.....,  FactoryIO_Input15
// Digital Outputs: FactoryIO_Coil0 , FactoryIO_Coil1, ..... , FactoryIO_Coil15
// Analog Inputs : FactoryIO_InputReg0, FactoryIO_InputReg1, ..... , FactoryIO_InputReg7
// Analog Outputs : FactoryIO_HoldingReg0, FactoryIO_HoldingReg1, ..... , FactoryIO_HoldingReg7
// Logic for scene "2 - from A to B (Set en Reset)  
  detectado = FactoryIO_Input0;
  sensor1 = FactoryIO_Input1;
  sensorZ = FactoryIO_Input2;
  sensorX = FactoryIO_Input3;
  sensor2 = FactoryIO_Input11;
  sensor3 = FactoryIO_Input4;
  sensor4 = FactoryIO_Input12;
  contagem1 = FactoryIO_Input5;
  contagem2 = FactoryIO_Input6;



if (contagem1 == HIGH){
  if (conmuta) {
      contador++;
      conmuta = false;
    }

  } else {
    conmuta = true;
  }

if (contagem2 == HIGH){
  if (conmuta2) {
      contador2++;
      conmuta2 = false;
    }

  } else {
    conmuta2 = true;
  }


if (moveZ == HIGH){
  if (conmuta3) {
      contador3++;
      conmuta3 = false;
    }

  } else {
    conmuta3 = true;
  }


if (moveX == HIGH){
  if (conmuta4) {
      contador4++;
      conmuta4 = false;
    }

  } else {
    conmuta4 = true;
  }

if (contador3 >= 20){
  manutencao1 = HIGH;
  digitalWrite(D2,HIGH);
  digitalWrite(LED_D2,HIGH);
}


if (contador4 >= 20){
  manutencao2 = HIGH;
  digitalWrite(D3,HIGH);
  digitalWrite(LED_D3,HIGH);
}

if (reset1 == HIGH){
  manutencao1 = LOW;
  digitalWrite(D2,LOW);
  digitalWrite(LED_D2,LOW);
  contador3 = 0;
}


if (reset2 == HIGH){
  manutencao2 = LOW;
  digitalWrite(D3,LOW);
  digitalWrite(LED_D3,LOW);
  contador4 = 0;
}

estadobotao6 = digitalRead(BTN_USER);
if (estadobotao6 == LOW) {
  manutencao1 = LOW;
  digitalWrite(D2,LOW);
  digitalWrite(LED_D2,LOW);
  contador3 = 0;
  manutencao2 = LOW;
  digitalWrite(D3,LOW);
  digitalWrite(LED_D3,LOW);
  contador4 = 0; 
}


estadoButton = digitalRead(A0);
if (estadoButton == HIGH && emergenciafisico == LOW && estadobotao5 == HIGH){
   if (sensor1 == HIGH && sensor2 == LOW){ // Sensor is low when a box is between the sensor and the reflector of the sensor
     motor1 = LOW;
     digitalWrite(D0,LOW);
     digitalWrite(LED_D0,LOW);
     moveZ = HIGH;
     Grab = HIGH;
     motor1luz = LOW;
     m1status = LOW;
  }else{
    Grab = LOW;
    motor1 = HIGH;
    digitalWrite(D0,HIGH);
    digitalWrite(LED_D0,HIGH);
    moveZ = LOW;
    motor1luz = HIGH;
    m1status = HIGH;
  }
  
  if (detectado == HIGH && sensor2 == LOW){
    moveZ = LOW;
    moveX = HIGH;
    Grab = HIGH;
  }else{
    Grab = LOW;
  }

  if (sensor2 == HIGH){
    moveZ = HIGH;
    Grab = HIGH;
    motor2 = LOW;
    motor2luz = LOW;
    m2status = LOW;
    digitalWrite(D1,LOW);
    digitalWrite(LED_D1,LOW);
  }else{
    motor2 = HIGH;
    motor2luz = HIGH;
    m2status = HIGH;
    digitalWrite(D1,HIGH);
    digitalWrite(LED_D1,HIGH);
  }
  
  if (sensor2 == HIGH && sensor3 == HIGH){
    Grab = LOW;
    moveZ = LOW;
    moveX = LOW;
  }
}else{
  motor1 = LOW;
  motor1luz = LOW;
  m1status = LOW;
  digitalWrite(D0,LOW);
  digitalWrite(LED_D0,LOW);
  motor2 = LOW;
  motor2luz = LOW;
  m2status = LOW;
  digitalWrite(D1,LOW);
  digitalWrite(LED_D1,LOW);
}

estadoButton = digitalRead(A0);
estadobotao1 = digitalRead(A1);
estadobotao2 = digitalRead(A2);
estadobotao3 = digitalRead(A3);
estadobotao4 = digitalRead(A4);
estadobotao5 = digitalRead(A5);
{
  if(estadoButton == LOW && emergenciafisico == LOW && estadobotao5 == HIGH){
    if (estadobotao1 == HIGH && emergenciafisico == LOW && estadobotao5 == HIGH){
      motor1 = HIGH;
      motor1luz = HIGH;
      m1status = HIGH;
      
      digitalWrite(D0,HIGH);
      digitalWrite(LED_D0,HIGH);
    }else{
      motor1 = LOW;
      m1status = LOW;
      motor1luz = LOW;
      digitalWrite(D0,LOW);
      digitalWrite(LED_D0,LOW);
    }

    if(estadobotao2 == HIGH && moveX == LOW && emergenciafisico == LOW && estadobotao5 == HIGH){
      moveZ = HIGH;
      Grab = HIGH;
    }

    if (detectado == HIGH & moveX == LOW && emergenciafisico == LOW && estadobotao5 == HIGH) {
      moveZ = LOW;
    }

    if (detectado == HIGH && estadobotao3 == HIGH && emergenciafisico == LOW && estadobotao5 == HIGH){
      moveX = HIGH;
    }

    if (moveX == HIGH && sensor2 == HIGH && sensor4 == HIGH && estadobotao2 != LOW && emergenciafisico == LOW && estadobotao5 == HIGH){
      moveZ = HIGH;
    }

    if (sensor3 == HIGH && emergenciafisico == LOW && estadobotao5 == HIGH){
      Grab = LOW;
      moveZ = LOW;
      moveX = LOW;
    }

    if(estadobotao4 == HIGH && emergenciafisico == LOW && estadobotao5 == HIGH){
      motor2 = HIGH;
      motor2luz = HIGH;
      m2status = HIGH;
      digitalWrite(D1,HIGH);
      digitalWrite(LED_D1,HIGH);
    }else{
      motor2 = LOW;
      motor2luz = LOW;
      m2status = LOW;
      digitalWrite(D1,LOW);
      digitalWrite(LED_D1,LOW);
    }

  }
}


  // Writing Outputs 

  FactoryIO_Coil0 = motor1;
  FactoryIO_Coil1 = motor2;
  FactoryIO_Coil2 = moveZ;
  FactoryIO_Coil3 = moveX;
  FactoryIO_Coil4 = Grab;
  
  FactoryIO_WriteOutputs();    // Writing the outputs to Factory I/O

  
  
   
  
}



/********************************************* BOTÃO DE EMERGENCIA *********************************************/


void onEmergenciafisicoChange()  {
  
}









/*
  Since Reset is READ_WRITE variable, onResetChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onResetChange()  {
  // Add your code here to act upon Reset change
}

/*
  Since Reset1 is READ_WRITE variable, onReset1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onReset1Change()  {
  // Add your code here to act upon Reset1 change
}

/*
  Since Reset2 is READ_WRITE variable, onReset2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onReset2Change()  {
  // Add your code here to act upon Reset2 change
}

















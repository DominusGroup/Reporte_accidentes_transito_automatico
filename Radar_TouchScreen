
// Touch screen libraries  
#include <Nextion.h>
#include <NextionPage.h>
#include <NextionButton.h>
#include <NextionPicture.h>
#include <NextionText.h> 
#include <NextionNumber.h>

// Serial comunication library
#include <SoftwareSerial.h>
  
SoftwareSerial nextionSerial(10, 11);            // RX, TX

Nextion       nex(nextionSerial);
NextionPage   pgButton(nex, 0, 0, "pgButton") ;
NextionButton report_button(nex, 0, 3, "b0") ;   // botón de reporte
NextionText   banner(nex, 0, 5, "t0") ;          // banner
NextionText   estado(nex, 0, 4, "t1") ;          // estado del sistema
NextionText   link(nex, 0, 6, "t2") ;            // link

// Touch screen
char buffer[50];
int n = 0 ; 
const int RadarSignal = 7 ; 
boolean Reporte = false ; boolean RadarON = false ; boolean RadarOFF = false ; 

// Radar  
int i ; float Prom ; float Prom0 ; const int g = 125 ;

void setup()
{
  i = 1 ; 
  Serial.begin(9600);
  pinMode(13, OUTPUT) ; pinMode(RadarSignal, INPUT); 

  nextionSerial.begin(9600);

// Touch screen setup  
  nex.init();
  Serial.println(pgButton.show());
  Serial.println(report_button.attachCallback(&callback)); 
  Serial.println(report_button.setText("Reporte"));   
  Serial.println(estado.setText(" OK "));
  Serial.println(banner.setText(""));  
  Serial.println(link.setText(""));  
}

void loop()
{ 
// Radar 
  muestreo();
  i++;  

// Touch screen   
  report_button.getText(buffer, 50); Serial.println(buffer) ; delay(1500) ;    
  nex.poll(); 
  
  if (digitalRead(RadarSignal) == HIGH && Reporte == false ){  
    Serial.println(estado.setBackgroundColour(NEX_COL_YELLOW));
    Serial.println(estado.setText(" Precaucion !"));  
    Serial.println(banner.setText(""));      
    Serial.println(link.setText(""));    
    n = n+1 ; 
    RadarON = true ;
  }
  if (digitalRead(RadarSignal) == LOW && Reporte == false ) {   // && RadarON == true){ 
    Serial.println(estado.setBackgroundColour(NEX_COL_GREEN));
    Serial.println(estado.setText(" OK "));  
    Serial.println(banner.setText(""));      
    Serial.println(link.setText(""));   
    n = n+1 ;  
    RadarON = false ;   
  }
  
}


void FillArray(int TheArray[], int pin){
    for(int i=0; i<g; i++){ TheArray[i] = analogRead(A0) ; }
}

 
void muestreo(){ 
    Serial.println(" . ") ; Serial.println(" . ") ; Serial.println(" . ") ;         
    
    int myArray[g] ;   
    FillArray(myArray, A0) ; 
     
    for(int k=0; k<g; k++){
      Serial.println(myArray[k]) ; 
      Prom += myArray[k] ; 
    } 

    Serial.println("") ; Serial.print(" Promedio : ")  ; Serial.print(Prom/g) ; 
    Serial.println("") ; Serial.print(" Promedio0 : ") ; Serial.print(Prom0/g) ; 
    Serial.println("") ; Serial.println("") ; 
    
    Prom0 = Prom ; 
    Prom = 0 ;
}

 
void callback(NextionEventType type, INextionTouchable *widget)
{ 
      if (type == NEX_EVENT_PUSH && Reporte == false){
        Serial.println(estado.setBackgroundColour(NEX_COL_RED));
        Serial.println(estado.setText("Emergencia"));    
        Serial.println(banner.setText("Continuar reporte desde:"));    
        Serial.println(link.setText("www.bbc.co.uk"));   
        Reporte = true ; 
        digitalWrite(13, HIGH);
      }
      else if (type == NEX_EVENT_PUSH && Reporte == true){
        Serial.println(estado.setBackgroundColour(NEX_COL_GREEN));
        Serial.println(estado.setText(" OK "));  
        Serial.println(banner.setText(""));    
        Serial.println(link.setText(""));     
        Reporte = false ;
        digitalWrite(13, LOW);    
      }
      else { 
        Serial.println(estado.setBackgroundColour(NEX_COL_GREEN));
        Serial.println(estado.setText(" OK "));  
        Serial.println(banner.setText(""));    
        Serial.println(link.setText(""));  
        digitalWrite(13, LOW);        
        n = n+1 ;    
      }      
 } 







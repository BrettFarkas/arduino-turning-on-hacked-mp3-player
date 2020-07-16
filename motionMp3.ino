// when I walk in the house a motion sensor is activated.  
//The arduino turns on the speakers with a powerswitchtail.  Then
// it activates the mp3 player.  After playing the song for 1
// minute, the speakers are turned off.  Then the song is forwarded
// to the next one, and the mp3 player is turned off.  
//A song will play every other time so that it doesn't play
// on exit, only entry.  

int speaker = 0;         //powerswitchtail for speakers
int Forward =  13;    // song forward
int Play = 8;          // play/pause a song
                     


int motion = 1;
int entry=0;

void setup()   {
 
//Serial.begin(9600);  

 pinMode(Forward, OUTPUT);     //to a transistor
 pinMode(Play, OUTPUT);         //to a transistor
pinMode(0,OUTPUT); //speaker
pinMode(2,INPUT);   //motion sensor input

digitalWrite(speaker,LOW); //speakers off
}


void loop()                    
{

motion=digitalRead(2); // read motion sensor on pin 2

if(motion==1){  // if the motion sensor has been activated

 if(entry==1){  // entry goes from 0 to 1 and 1 to 0 every time that
                // the motion sensor is activated.  It will only
                // play a song every other time, when it's 1
 
 //TURN the MP3 player ON by pressing 'play' for 3 seconds
 digitalWrite(Play, HIGH);  
 delay(3500);                  
 digitalWrite(Play, LOW);  
 delay(5260);                //wait for the mp3 to come on
                         
                           

// TURN SPEAKERS ON
digitalWrite(speaker,HIGH);

//PLAY SONG
delay(60000); //wait 1 minute while the song plays

// TURN SPEAKERS OFF
digitalWrite(speaker,LOW);

//GO FORWARD ONE SONG
digitalWrite(Forward, HIGH);  //pass the current song
 delay(145);                  
 digitalWrite(Forward, LOW);
delay(300);                    // let it load in

//TURN mp3 player OFF by pressing 'play' for 3 seconds
 digitalWrite(Play, HIGH);  
       
 delay(3500);                
 digitalWrite(Play, LOW);  
 
delay(4000);
entry=0;      // make 'entry' 0 so that next time it won't play a song
 } else{
   entry=1;   // else, next time play the song
   delay(20000);  //waits 20 seconds for the person to leave the house
 }//end entry if statement


} //END MOTION SENSOR IF STATEMENT

delay(100);
} // END MAIN LOOP

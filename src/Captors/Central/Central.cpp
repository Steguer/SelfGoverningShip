/**
 * @file Central.cpp
 * @author  Batiste Bertier
 */
#include "Central.hpp"

Central::Central()
{
    // heading=0;
     raw=0;
     pitch=0;
     dx=0;
    a=0;
     mean= 0;
     sizeMean = Parsser::readConfigInt("ConstMeanCompas");
}

int Central::initCentral()
{

 short int fd;
	 struct termios Serial;
 	FILE *RX4_Handle = NULL, *TX4_Handle = NULL;
// 		FILE *RX1_Handle = NULL, *TX1_Handle = NULL;

 	char tx4Mode[4], rx4Mode[4],tx4ModeSet[4], rx4ModeSet[4];
 	const char *uart4_tx = "/sys/kernel/debug/omap_mux/gpmc_wpn",
 					*uart4_rx = "/sys/kernel/debug/omap_mux/gpmc_wait0";

 	sprintf(tx4Mode, "%d", 06); //uart4 TX mode
 	sprintf(rx4Mode, "%d", 26); //uart4 RX mode
 	//Open file 4
 		if((TX4_Handle = fopen(uart4_tx, "r+")) == NULL){
 			printf( "Can't set up TX4.");
 			return -1;       }
 		strcpy(tx4ModeSet, tx4Mode);
 		fwrite(&tx4ModeSet, sizeof(char), sizeof(&tx4ModeSet), TX4_Handle);
 		fclose(TX4_Handle);
 		//Open file 2
 		if((RX4_Handle = fopen(uart4_rx, "r+")) == NULL){
 			printf("Can't set up RX4.");
 			return -1;       }
 		strcpy(rx4ModeSet, rx4Mode);
 		fwrite(&rx4ModeSet, sizeof(char), sizeof(&rx4ModeSet), RX4_Handle);
 		fclose(RX4_Handle);

 		if ((fd = open("/dev/ttyO4", O_RDWR | O_NOCTTY)) < 0){
 			printf("Could not open port.");
 				return -1;
 			}

 		if (tcgetattr(fd, &Serial) != 0){
 			 printf("Unable to retrieve port attributes.");
 		 }
 		 if (cfsetispeed(&Serial, B115200) < 0){
 		 		printf("Input baud rate not successfully set.");
 		 	}
 		tcsetattr(fd, TCSANOW, &Serial);
 		close(fd);
 		return 1;


  int i = 0;
  int meanHeading = 0;
  int value = 0;

  while(i!=1)
  {    
    for (int j=0;j<=sizeMean;j++)
    {
      //cout<<"heading : "<<readData()<<" ";
      if(readData() != -1){
      value = readData();}
      cout<<"value : "<<value<<endl;;
      bu.push_back(value);
      cout<<"raw"<<getRaw()<<" ";
      cout<<"pitch "<<getPitch()<<endl;
      /*************************************/
      sleep(1);
    }
    meanHeading = dataMean(bu,sizeMean);
    cout<<"moyenne heading : "<<meanHeading<<endl;
    // bu.clear();

    //j=0;
    i++;
  }
}

int Central:: readData()
{

Central c;
union flochar pitchData;
union flochar headData;
union flochar rawData;
struct termios Serial;
float x = 0;float y = 0; /*************************************/
int angle = 70; /*************************************/
float headingRad = 0; /*************************************/
float angleRad=0; /*************************************/
//rph all;

char debut[1]={'F'};
char tab[74];

//while(i!=3){
	if ((fd2 = open("/dev/ttyO4", O_RDWR | O_NOCTTY)) < 0){
  			printf("Could not open port.");
  				//return -1;
  			}

  		if (tcgetattr(fd2, &Serial) != 0){
  			 printf("Unable to retrieve port attributes.");
  		 }
  		 if (cfsetispeed(&Serial, B115200) < 0){
  		 		printf("Input baud rate not successfully set.");
  		 	}
  		 if (cfsetospeed(&Serial, B115200) < 0){
  		  		 		printf("Input baud rate not successfully set.");
  		  		 	}
  		Serial.c_iflag = 0;
  			Serial.c_oflag = 0;
  			Serial.c_lflag = 0;
  			Serial.c_cc[VMIN] = 1;
  			Serial.c_cc[VTIME] = 0;

  		tcsetattr(fd2, TCSANOW, &Serial);


 fd = open("/dev/ttyO4", O_RDWR | O_NOCTTY);

 write(fd,debut,1);

 bytes_read = read(fd2, tab, 15);
 	close(fd2);
 	 close(fd);

headData.nbch.char0=tab[10];
headData.nbch.char1=tab[11];
headData.nbch.char2=tab[12];
headData.nbch.char3=tab[13];
heading=(int)(360.0*headData.nbf1/6.28);

rawData.nbch.char0=tab[2];
rawData.nbch.char1=tab[3];
rawData.nbch.char2=tab[4];
rawData.nbch.char3=tab[5];
raw=(int)(360.0*rawData.nbf1/6.28);

pitchData.nbch.char0=tab[6];
pitchData.nbch.char1=tab[7];
pitchData.nbch.char2=tab[8];
pitchData.nbch.char3=tab[9];
pitch = (int)(360.0*pitchData.nbf1/6.28);

   if(heading<0){

heading = heading+360;

}
//printf("heading : %d\n",heading); /*************************************/

angleRad = (angle*M_PI)/180; /*************************************/
headingRad = (heading*M_PI)/180; /*************************************/

	// on utilise la formule qui est sin (a+b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( (cos(headingRad)*cos(angleRad)) - (sin(headingRad)*sin(angleRad)) ); /*************************************/
    //avec a = boatFlagAxe et b = axeBoat

    y = asin ( sin(headingRad)*cos(angleRad) + cos(headingRad)*sin(angleRad) ); /*************************************/

    x = (x*180)/M_PI; /*************************************/
    y= (y*180)/M_PI; /*************************************/




//printf("%f %d %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu\n\n ", headData.nbf1h,heading,tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7],tab[8],tab[9],tab[10],tab[11],tab[12],tab[13]);
//fprintf(fichier_navh,"%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %f %d \n ", tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7],tab[8],tab[9],tab[10],tab[11],tab[12],tab[13],head.nbf1,heading);
//printf("heading1 : %d\n",heading);


//sleep(1); /*************************************/ le sleep a été supprimé et placé dans le main
//}



//printf("%d  %d  %d\n",heading,raw,pitch);
/*all.heading = heading;
all.pitch = pitch;
all.raw = raw;*/
if (x == 0){

return -1;

}else if (y<=0){ /*************************************/

return 360-x; /*************************************/
}

else {

return x; /*************************************/
}
}

int Central::getHeading(){

return heading;
}
int Central::getRaw(){

return raw;
}
int Central::getPitch(){

return pitch;
}

void Central::cbInit(CircularBuffer &cb, int size) 
{
    cb.size  = size + 1;
    cb.start = 0;
    cb.end   = 0;
    cb.elems = (int *)calloc(cb.size, sizeof(int));
}

void Central::cbFree(CircularBuffer *cb) 
{
    free(cb->elems);
}

int Central::cbIsFull(CircularBuffer *cb) 
{
    return (cb->end + 1) % cb->size == cb->start;
}

int Central::cbIsEmpty(CircularBuffer *cb) 
{
    return cb->end == cb->start;
}

/*Ajout d'un élément*/
void Central::cbWrite(CircularBuffer *cb, int *elem) 
{
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1) % cb->size;
    if (cb->end == cb->start)
        cb->start = (cb->start + 1) % cb->size;
}

/* lit la valeur la plus ancienne en s'assurant que le buffer n'est pas vide  */
void Central::cbRead(CircularBuffer *cb, int *elem) 
{
    *elem = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
}

int Central::dataMean(deque <int> &buf, int sizeBuf)
{
  int sum=0;

  for(auto it : buf)
  { 
    cout<<"$$$"<<it<<"$$$"<<endl;
    sum += it;
  }

  cout<<"$$$$$"<<sum<<"$$$$$"<<endl;

  mean = sum/buf.size();
  cout<<"$$$$$"<<buf.size()<<"$$$$$"<<endl;
  return mean;
}

int Central::finalData(int sizeMean)
{
  int i=0;
  int value = 0;

  if(readData() != -1)
  {
    value = readData();
  }
  cout<<"value : "<<value<<endl;
  if(bu.size() >= Parsser::readConfigInt("ConstMeanCompas"))
  {
    bu.pop_front();
    bu.push_back(value);
  }
  else
  {
    bu.push_back(value);
  }
  cout<<"raw"<<getRaw()<<" ";
  cout<<"pitch "<<getPitch()<<endl;
  /*************************************/
  int meanHeading = dataMean(bu,sizeMean);
  //return meanHeading;
  cout<<"moyenne heading : "<<meanHeading<<endl;
  sleep(1);

  return meanHeading;

}

void Central::notifyData()
{
  DataPack dataToSend;
  dataToSend.id = PITCH_ID;
  dataToSend.data[0] = pitch;
  dataToSend.data[1] = 0;
  notify(dataToSend);

  dataToSend.id = RAW_ID;
  dataToSend.data[0] = raw;
  notify(dataToSend);

  dataToSend.id = COMPAS_ID;
  dataToSend.data[0] = finalData(Parsser::readConfigInt("ConstMeanCompas"));
  notify(dataToSend);
}

/**
 * @file Gps.cpp
 * @author  Batiste Bertier
 */
#include "Gps.hpp"

Gps::Gps()
{
    cout<<"coucou gps"<<endl;
    system("/home/ubuntu/initGps.sh"); // Appel du script .sh d'initialisation du gps à 5Hz, 38400 bauds et des trames Gprmc
    cout<<"coucou"<<endl;
    size = 0;
}

void Gps::initGpsUart()
{

    // erase file gps3.txt


    // si la taille du fichier est inf à 500 Mo on enregistre les données
    while (size <= 51)
    {
        system("cat /dev/ttyO1 >> gps3.txt");
        cout<<"ecriture des donnees"<<endl;
        sizeFile();
        cout<< size<<endl;
    }
    cout<< size<<endl;
    cout<<"\nMemory full\n";


}


void Gps::sizeFile()
{
    ifstream file;
    file.open("gps3.txt");
    cout<<"ouverture du fichier de donnees"<<endl;
    file.seekg(-1,ios_base::end);
    size = file.tellg();
    cout<<size;
    file.close();
      cout<<"fermeture du fichier"<< endl;

}

int Gps::readData()
{

    string data;
    ifstream file ("/dev/ttyO1",ios::in);//"gps3.txt"


    if (file)
    {

      //  while (file.eof() != 1) // until we are not at the end of the file, we read data of each line
       // {

            getline(file,data);
            cout << data<<endl;
            strcpy(rawData,data.c_str()); // convert data string into char*

            if (rawData[18]=='A')   //signal valid
            {
                DataPack dataToSend;
                dataToSend.data[0] = readLat();
                dataToSend.data[1] = readLongi();
                dataToSend.id = GPS_ID;
                cout<<"data send: lat = "<<dataToSend.data[0]<<" long = "<<dataToSend.data[1]<<endl;
                cout<<"notify"<<endl;
                notify(dataToSend);
                dataToSend.id = SPEED_ID;
                dataToSend.data[0] = readVelocity();
                dataToSend.data[1] = 0;
                notify(dataToSend);
            return 1;
            }
            else
            {

                cout<< "fail reading \n"<<endl;
                 //file.close();
        return 0;
            }
       // }


    }

    else
    {
        cout << "fail to open \n";
    }

return 1;
}

float Gps::readLat()
{

    int latPosition = 20 ;
    int latLeng = 11;
    int latLengDeg = 2;
    int latPositionMin = latPosition + latLengDeg ;
    int latLengMin = 9;


    latStr = (char*)malloc((latLeng+1) * sizeof(char));
    char *latStrDeg = (char*)malloc((latLengDeg+1) * sizeof(char));
    char *latStrMin = (char*)malloc((latLengMin+1) * sizeof(char));

    snprintf(latStr, latLeng+1,"%s", rawData+latPosition);
    snprintf(latStrDeg, latLengDeg+1,"%s", rawData+latPosition);
    snprintf(latStrMin, latLengMin+1,"%s", rawData+latPositionMin);

    float latMin = atof(latStrMin);
    float latDeg = atof(latStrDeg);

    float latDecimale = latDeg + latMin/60;

    cout << "Latitude : "<<latStr<<endl;

    if (latStr[10]=='S')
    {
        latDecimale = 0-latDecimale;

        cout << " latitude finale = "<<latDecimale<<"°"<<endl;
    }
    else
    {

        cout << " latitude finale = "<<latDecimale<<"°"<<endl;
    }


    free(latStr);
    free(latStrDeg);
    free(latStrMin);

    return latDecimale;
}



float Gps::readLongi()
{

    int longiPosition = 32 ;
    int longiLeng = 12;
    int longiLengDeg = 3;
    int longiPositionMin = longiPosition + longiLengDeg ;
    int longiLengMin = 9;



    longiStr = (char*)malloc((longiLeng+1) * sizeof(char));
    char *longiStrDeg = (char*)malloc((longiLengDeg+1) * sizeof(char));
    char *longiStrMin = (char*)malloc((longiLengMin+1) * sizeof(char));

    snprintf(longiStr, longiLeng+1,"%s", rawData+longiPosition);
    snprintf(longiStrDeg, longiLengDeg+1,"%s", rawData+longiPosition);
    snprintf(longiStrMin, longiLengMin+1,"%s", rawData+longiPositionMin);

    float longiMin = atof(longiStrMin);
    float longiDeg = atof(longiStrDeg);

    float longiDecimale = longiDeg + longiMin/60;

    cout << "Longitude : "<<longiStr<<endl; ;


    if (longiStr[11] == 'W')
    {
        longiDecimale = 0-longiDecimale;

        cout << " longitude finale = "<<longiDecimale<<"°\n"<<endl;
    }
    else
    {

        cout << " longitude finale = "<<longiDecimale<<"°\n"<<endl;
    }


    free(longiStr);
    free(longiStrDeg);
    free(longiStrMin);

    return longiDecimale;
}

float Gps::readVelocity()
{


    int velocityPosition = 45 ;
    int velocityLeng = 4 ;

    velocityStr = (char*)malloc((velocityLeng+1) * sizeof(char));

    snprintf(velocityStr, velocityLeng+1,"%s", rawData+velocityPosition);

    // velocity = strtol(velocityStr,NULL, 10);
    float velocity = atof(velocityStr);

    cout << "\nvelocity in knots : "<<velocity<<endl;
    
    free(velocityStr);

    return velocity;
}

void Gps::supprFile()
{

  ofstream file("gps3.txt");
  file.close();

}

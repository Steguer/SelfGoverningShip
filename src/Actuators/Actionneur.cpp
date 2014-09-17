/**
 * @file Actionneur.cpp
 * @author  Batiste Bertier
 */
#include "Actionneur.hpp"

Actionneur::Actionneur()
{
    FILE* f;
//  	int m_q = 0;
  //	int up_time = 0;

  //configuration du port PWM1A => AM335X P9_14
	f = fopen("/sys/kernel/debug/omap_mux/gpmc_a2", "a");
	fprintf(f, "%d",6);
	fflush(f);
	fclose(f);

  //configuration du port PWM1B => AM335X P9_16
	f = fopen("/sys/kernel/debug/omap_mux/gpmc_a3", "a");
	fprintf(f, "%d",6);
	fflush(f);
	fclose(f);

	//configuration du PWM2B => AM335X P8_13 Rudder
	f = fopen("/sys/kernel/debug/omap_mux/gpmc_ad9", "a");
	fprintf(f, "%d",4);
	fflush(f);
	fclose(f);

}

Actionneur::~Actionneur()
{
    stopSystem();
}

void Actionneur::moveJibe(int angle){

//D�claration des variables locales
	if(angle >= 35 && angle <= 90)
	{
		FILE* f;

		 int m_q = 11111; // Quantum en nanoseconde pour servo de 16sec/60deg => 3.75 sec/1 deg. Le servo va de -30 à 30 en passant par 0 le quantum correspond à la variation d'un angle de 1 deg pour un tps donné// pour le servo test 0.23/60deg soit 3.8ms/1deg

		//Mise en place des donn�es dans les variables
		//UpTime = (angle demand�e) * quantum + valeur du temps en sec pour lequel le servo est à 0 exple : à 1.5ms le servo est à 0
		//Note : TEMPS EN MICRO SECONDE !!!!!!!!!!
		up_time = angle * m_q + (1 * 100000);


		//printf("activation PWM\n");
		f = fopen("/sys/class/pwm/ehrpwm.1:0/request", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);

		//Mise en place de la polarit�
		f = fopen("/sys/class/pwm/ehrpwm.1:0/polarity", "w");
		fprintf(f, "%d", 0);
		fflush(f);
		fclose(f);

			//Mise en place de la p�riode
		f = fopen("/sys/class/pwm/ehrpwm.1:0/period_ns", "w");
		fprintf(f, "%d", 20 * 1000000);
		fflush(f);
		fclose(f);

		//Mise en place du cycle de 20ms
		//printf("Mise en place du cycle\n");
		f = fopen("/sys/class/pwm/ehrpwm.1:0/duty_ns", "w");
		fprintf(f, "%d", up_time);
		fflush(f);
		fclose(f);

	    //Lancement du servo
	    f = fopen("/sys/class/pwm/ehrpwm.1:0/run", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);
	}

}

void Actionneur::moveMainSail(int angle){

	if(angle >= 35 && angle <= 90)
	{
	//D�claration des variables locales
		FILE* f;

		 int m_q = 11111; // Quantum en nanoseconde pour servo de 16sec/60deg => 3.75 sec/1 deg. Le servo va de -30 à 30 en passant par 0 le quantum correspond à la variation d'un angle de 1 deg pour un tps donné// pour le servo test 0.23/60deg soit 3.8ms/1deg

		//Mise en place des donn�es dans les variables
		//UpTime = (angle demand�e) * quantum + valeur du temps en sec pour lequel le servo est à 0 exple : à 1.5ms le servo est à 0
		//Note : TEMPS EN MICRO SECONDE !!!!!!!!!!
		up_time = angle * m_q + (1 * 100000);



		//printf("lancement PWM\n");
		f = fopen("/sys/class/pwm/ehrpwm.1:1/request", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);

		//Mise en place de la polarit�
		f = fopen("/sys/class/pwm/ehrpwm.1:1/polarity", "w");
		fprintf(f, "%d", 0);
		fflush(f);
		fclose(f);

			//Mise en place de la p�riode
		f = fopen("/sys/class/pwm/ehrpwm.1:1/period_ns", "w"); // periode de 20 ms
		fprintf(f, "%d", 20 * 1000000);
		fflush(f);
		fclose(f);

		//Mise en place du cycle de 20ms
		//printf("Mise en place du cycle\n");
		f = fopen("/sys/class/pwm/ehrpwm.1:1/duty_ns", "w");
		fprintf(f, "%d", up_time);
		fflush(f);
		fclose(f);

	      //Lancement du servo
	    f = fopen("/sys/class/pwm/ehrpwm.1:1/run", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);
	}
}

void Actionneur::moveRudder(int angleD){

	if(angleD >= 80 && angleD <= 170)
	{
	    //D�claration des variables locales
		FILE* f;
		int up_time2;
		int m_q2 = 11111; // Quantum en nanoseconde pour servo de 0.9sec/360deg =>  2.5ms/1 deg. Le servo va de 0 à 360 en passant par 0

		//Mise en place des donn�es dans les variables
		//UpTime = (angle demand�e) * quantum + valeur du temps en sec pour lequel le servo est à 0 exple : à 1.5ms le servo est à 0
		//Note : TEMPS EN MICRO SECONDE !!!!!!!!!!
		up_time2 = angleD * m_q2 + (1 * 100000); // inconnu la valeur pour laquelle l'angle est à 0 sur le servo



	//printf("activation PWM\n");
		f = fopen("/sys/class/pwm/ehrpwm.2:1/request", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);

		//Mise en place de la polarit�
		f = fopen("/sys/class/pwm/ehrpwm.2:1/polarity", "w");
		fprintf(f, "%d", 0);
		fflush(f);
		fclose(f);

	   /* f = fopen("/sys/class/pwm/ehrpwm.2:1/period_freq", "w");
		fprintf(f, "%d", 100);
		fflush(f);
		fclose(f);*/

			//Mise en place de la p�riode
		f = fopen("/sys/class/pwm/ehrpwm.2:1/period_ns", "w");
		fprintf(f, "%d", 20 * 1000000); // 1sec
		fflush(f);
		fclose(f);

		//Mise en place du cycle de 20ms
		//printf("Mise en place du cycle\n");
		f = fopen("/sys/class/pwm/ehrpwm.2:1/duty_ns", "w");
		fprintf(f, "%d", up_time2);
		fflush(f);
		fclose(f);

		  //Lancement du servo
		f = fopen("/sys/class/pwm/ehrpwm.2:1/run", "w");
		fprintf(f, "%d",1);
		fflush(f);
		fclose(f);
	}
}

	void Actionneur::stopSystem(){

	    FILE* f;

	    f = fopen("/sys/class/pwm/ehrpwm.2:1/run", "w");
		fprintf(f, "%d",0);
		fflush(f);
		fclose(f);

	    f = fopen("/sys/class/pwm/ehrpwm.1:1/run", "w");
		fprintf(f, "%d",0);
		fflush(f);
		fclose(f);

		 f = fopen("/sys/class/pwm/ehrpwm.1:0/run", "w");
		fprintf(f, "%d",0);
		fflush(f);
		fclose(f);

}

void Actionneur::update(DataPack cmd)
{
    //Check if the cmd is for the motors.
    if(cmd.id == MOTORS_ID)
    {
        try
        {
            thread threadMainSail(&Actionneur::moveJibe, this, cmd.data[0]);
            thread threadJibe(&Actionneur::moveMainSail, this, cmd.data[0]);
            thread threadRudder(&Actionneur::moveRudder, this, cmd.data[1]);
            threadMainSail.join();
            threadJibe.join();
            threadRudder.join();
            cout<<"***********************"<<cmd.data[0]<<endl;
            cout<<"***********************"<<cmd.data[1]<<endl;
            // sleep(20000);
        }
        catch(exception e)
        {
            cout<<"Error in the motor thread: "<<e.what()<<endl;
        }
    }
}

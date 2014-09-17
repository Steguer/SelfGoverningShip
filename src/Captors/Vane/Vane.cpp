/**
 * @file Vane.cpp
 * @author  Batiste Bertier
 */
#include "Vane.hpp"

Vane::Vane()
{
    //ctor
}

/****************************************************************
 * gpio_export
 ****************************************************************/
int Vane :: gpio_export(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}

/****************************************************************
 * gpio_unexport
 ****************************************************************/
int Vane:: gpio_unexport(unsigned int gpio)
{
    int fd, len;
    char buf[MAX_BUF];

    fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);
    return 0;
}

/****************************************************************
 * gpio_set_dir
 ****************************************************************/
int Vane :: gpio_set_dir(unsigned int gpio, unsigned int out_flag)
{
    int fd, len;
    char buf[MAX_BUF];

    len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("gpio/direction");
        return fd;
    }

    if (out_flag)
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}



/****************************************************************
 * gpio_get_value
 ****************************************************************/
int Vane :: gpio_get_value(unsigned int gpio,int *value)
{
    int fd, len;
    char buf[MAX_BUF];
    char ch;

    len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

    fd = open(buf, O_RDONLY);
    if (fd < 0)
    {
        perror("gpio/get-value");
        return fd;
    }

    read(fd, &ch, 1);

    if (ch != '0')
    {
        *value = 1;
    }
    else
    {
        *value = 0;
    }

    close(fd);
    return 0;
}

int Vane::dataVane()
{

    int fd_main;
    int value0,value1,value2,value3,value4,value5;
    int i = 0;
    int j=0;
    Vane v;

     char zone[32]={0,1,3,2,7,6,4,5,15,14,12,13,8,9,11,10,31,30,28,29,24,25,27,26,16,17,19,18,23,22,20,21};

    for(i=0; i<40; i++)
    {
        //fd_main=gpio_get_value(gpio, &value0);
        fd_main=v.gpio_get_value(48, &value0);
        fd_main=v.gpio_get_value(49, &value1);
        fd_main=v.gpio_get_value(117, &value2);
        fd_main=v.gpio_get_value(115, &value3);
        fd_main=v.gpio_get_value(7, &value4);
        fd_main=v.gpio_get_value(60, &value5);
        //printf("%d \n ", zone[value0+2*value1+4*value2+8*value3+16*value4]);

        for (j=0; j<=32; j++)
        {

            if (zone[value0+2*value1+4*value2+8*value3+16*value4] == j)
            {

               // zone[value0+2*value1+4*value2+8*value3+16*value4] = j*11.25;
               printf("%d\n",zone[value0+2*value1+4*value2+8*value3+16*value4]);
              return zone[value0+2*value1+4*value2+8*value3+16*value4];

            }

        }



       // sleep(1);

    }

    return 0;
}

void Vane::initGpio()
{

    //	struct pollfd fdset[2];
//	int nfds = 2;
//	int gpio_fd, timeout, rc;
//	char *buf[MAX_BUF];
//	unsigned int gpio;
//	int len;

//	Vane v;

    //gpio1_16 =>48
    //gpio1_17 =>49
    //gpio3_21 =>117
    //gpio3_19=>115
    //gpio0_7=>7
    //gpio1_28=>60
    //gpio_export(gpio);

    /*char *zone;
    	zone = (char*) malloc(sizeof(char)*32);

    	// zone[32]={0,1,3,2,7,6,4,5,15,14,12,13,8,9,11,10,31,30,28,29,24,25,27,26,16,17,19,18,23,22,20,21};

    	for (int i=0;i<=32;i++){

    	 zone[i]=i;

    	 }*/

    Vane v;

    system("echo 0x2F > /sys/kernel/debug/omap_mux/mcasp0_fsr");
    system("echo 0x2F > /sys/kernel/debug/omap_mux/mcasp0_ahclkx");
    system("echo 0x2F > /sys/kernel/debug/omap_mux/gpmc_a1");
    system("echo 0x2F > /sys/kernel/debug/omap_mux/gpmc_a0");

    v.gpio_export(48);
    v.gpio_export(49);
    v.gpio_export(117);
    v.gpio_export(115);
    v.gpio_export(7);
    v.gpio_export(60);

    //gpio_set_dir(gpio, 0);
    v.gpio_set_dir(48, 0);
    v.gpio_set_dir(49, 0);
    v.gpio_set_dir(117, 0);
    v.gpio_set_dir(115, 0);
    v.gpio_set_dir(7, 0);
    v.gpio_set_dir(60, 0);


}

void Vane::closeGpio()
{

    Vane v;

    v.gpio_unexport(48);
    v.gpio_unexport(49);
    v.gpio_unexport(117);
    v.gpio_unexport(115);
    v.gpio_unexport(7);
    v.gpio_unexport(60);


}



void Vane::cbInit(CircularBuffer &cb, int size) {
    cb.size  = size + 1; /* include empty elem */
    cb.start = 0;
    cb.end   = 0;
    cb.elems = (int *)calloc(cb.size, sizeof(int));
}

void Vane::cbFree(CircularBuffer *cb) {
    free(cb->elems); /* OK if null */
}

int Vane::cbIsFull(CircularBuffer *cb) {
    return (cb->end + 1) % cb->size == cb->start;
}

int Vane::cbIsEmpty(CircularBuffer *cb) {
    return cb->end == cb->start;
}

/* Write an element, overwriting oldest element if buffer is full. App can
   choose to avoid the overwrite by checking cbIsFull(). */
void Vane::cbWrite(CircularBuffer *cb, int *elem) {
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1) % cb->size;
    if (cb->end == cb->start)
        cb->start = (cb->start + 1) % cb->size; /* full, overwrite */
}

/* Read oldest element. App must ensure !cbIsEmpty() first. */
void Vane::cbRead(CircularBuffer *cb, int *elem) {
    *elem = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
}

int Vane::dataMean(vector<int> &buf){

    int a=0;
    int mean= 0;
    int sum=0;
    int dx=0;

    CircularBuffer cb;
    int BufferSize = 5; // On fait une moyenne de 5 nombres
//buffer = (int*) malloc(sizeof(int));

    int elem = {0};

    cbInit(cb, BufferSize);

    while(dx<=35){ // Décalage d'une valeur vers la droite en faisant attention à ne pas dépasser la taille du tableau

        a=0;
        sum =0;
        mean = 0;

    /* Remplissage du buffer par les valeurs de la girouette*/

    for (int i=0; i<= BufferSize; i++){
        elem = buf[i-1+dx];
        cbWrite(&cb, &elem);
    }
    /* Suppression et écriture des nombres */
    while (!cbIsEmpty(&cb)) {

        cbRead(&cb, &elem);
        sum = sum + elem;
        //cout<<"somme"<<a<<" : "<<sum<<endl;
        a++;
    }

    mean = sum/a;
   // cout << "moyenne : "<<mean<<endl;
      return mean;
  dx++;

  }

    cbFree(&cb);

return 0;
}

int Vane::convert(int value,int correction){


float angleRad =0;
float valueRad = 0;
float x,y;

angleRad = (correction*M_PI)/180; /*************************************/
valueRad = (value*M_PI)/180; /*************************************/

	// on utilise la formule qui est sin (a+b) = sin(a)*cos(b) - cos(a)*sin(b) avec x = a-b
	x = acos ( (cos(valueRad)*cos(angleRad)) + (sin(valueRad)*sin(angleRad)) ); /*************************************/
    //avec a = boatFlagAxe et b = axeBoat

    y = asin ( sin(valueRad)*cos(angleRad) - cos(valueRad)*sin(angleRad) );

    x = (x*180)/M_PI;
    y= (y*180)/M_PI;


 if (y<=0){
return 360-x;
}

return x; /*************************************/

}

int Vane::getMeanData()
{
    int mean=0;

    int buffer = 0;
    vector <int> bu;
    initGpio();

    // for (int j=0;j<=5;j++)
    // {
        buffer = dataVane();
        cout<<"buffer "<<buffer<<endl;
    //     bu.push_back(convert(buffer,123));
    //     cout<<"buf convertit : "<<bu[j]<<endl;
    //     sleep(1);
    // }
    // mean = dataMean(bu);
    cout<<"moyenne : "<<mean<<endl;
    // bu.clear();

    DataPack dataToSend;
    dataToSend.id = VANE_ID;
    dataToSend.data[0] = mean;
    cout<<"NOTIFY VANE"<<endl;
    notify(dataToSend);

    closeGpio();
}

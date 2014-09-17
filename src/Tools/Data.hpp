/**
 * @file Data.hpp
 * @brief Contain enum and struct use in the sofware
 */
#ifndef DATA_H
#define DATA_H

typedef enum
{
	GPS_ID, COMPAS_ID, MOTORS_ID, RAW_ID, PITCH_ID, SPEED_ID, VANE_ID
}HardwareId;

/**
 * @struct DataPack
 * @brief Use to send data from Observer to Observable
 * @details Contain a float array of two cell and an HardwareId id
 * 
 * @see  HardwareId
 */
typedef struct DataPack DataPack;
struct DataPack
{
	/**
	 * @brief id of the Observable which send data 
	 */
	HardwareId id;
	/**
	 * @brief Data send by Observable
	 */
	float data[2];
};

typedef enum
{
	SIDE_WIND, BACK_WIND, FRONT_WIND, NOTHING
}WindDirection;

/*Declaration Buffer circulaire */
typedef struct {
	/**
	 * @brief maximum number of elements
	 */
    int         size;
    /**
     * @brief index of the last element
     */
    int         start; 
    /**
     * @brief index where write the new element
     */
    int         end;
    /**
     * @brief element vector
     */
    int   *elems;
} CircularBuffer;

#endif
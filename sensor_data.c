// ✅ 2) Sensor Data Processing Framework

// Create a framework where sensors can produce different data types:

// Temperature → float

// Accelerometer → struct (x,y,z)

// GPS → struct (lat, lon)
// Use:

// union SensorData

// struct SensorPacket { sensorType; union data; function_pointer process; }

// Write processing functions for each sensor and call them via function pointers.

#include <stdio.h>
typedef enum
{
    TEMP_SENSOR = 1,
    ACCEL_SENSOR,
    GPS_SENSOR
} SensorType;
typedef struct
{
    int x;
    int y;
    int z;
} Accelerometer;

typedef struct
{
    float lat;
    float lan;
} GPS;

typedef union
{
    float temperature;
    Accelerometer axis;
    GPS cordinates;

} SensorData;
typedef void (*Sensor_Handler)(SensorData *args);
typedef struct
{
    SensorType type;
    SensorData data;
    Sensor_Handler process;
} SensorPacket;

void process_temp(SensorData *temp)
{
    printf("Temprature is %.2f\n", temp->temperature);
}

void process_accel(SensorData *Accel)
{
    printf("Cordinates of Accelometer is X=%d Y=%d Z=%d\n", Accel->axis.x, Accel->axis.y, Accel->axis.z);
}

void process_gps(SensorData *Gps)
{
    printf("GPS Cordinates is latitude = %f longitude = %f\n", Gps->cordinates.lat, Gps->cordinates.lan);
}
int main()
{
    SensorPacket sensors[] = {
        {TEMP_SENSOR, .data.temperature = 32.6, process_temp},
        {ACCEL_SENSOR, .data.axis = {2, 4, 5}, process_accel},
        {GPS_SENSOR, .data.cordinates = {2.344, 12.44}, process_gps}

    };

    for (int i = 0; i < 3; i++)
    {
        sensors[i].process(&sensors[i].data);
    }
}
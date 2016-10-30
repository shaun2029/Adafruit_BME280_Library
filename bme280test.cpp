#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdint.h>
#include "Adafruit_BME280.h"

#define SEALEVELPRESSURE_HPA (1013.25)
 
int main()
{
    Adafruit_BME280 bme;
    
    
    if (bme.begin(BME280_ADDRESS, "/dev/i2c-1")) {
        printf("Temperature = %.2f *C\n", bme.readTemperature());
        printf("Pressure = %.2f hPa\n", bme.readPressure() / 100.0F);
        printf("Approx. Altitude = %.2f m", bme.readAltitude(SEALEVELPRESSURE_HPA));
        printf("Humidity = %.2f %\n", bme.readHumidity());
        
        sleep(1);
    }
    
    
    
    return 0;
}


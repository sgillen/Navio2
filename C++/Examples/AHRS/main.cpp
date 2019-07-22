#include "AHRS.hpp"
#include <Common/MPU9250.h>
#include <Navio2/LSM9DS1.h>
#include <Common/Util.h>
//=============================================================================

int main(int argc, char *argv[])
{
    if (check_apm()) {
        return 1;
    }

    auto sensor_name = get_sensor_name(argc, argv);

    if (sensor_name.empty())
        return EXIT_FAILURE;

    auto imu = get_inertial_sensor(sensor_name);

    if (!imu) {
        printf("Wrong sensor name. Select: mpu or lsm\n");
        return EXIT_FAILURE;
    }

    if (!imu->probe()) {
        printf("Sensor not enable\n");
        return EXIT_FAILURE;
    }

        
    auto ahrs = std::unique_ptr <AHRS>{new AHRS(move(imu)) };

    //-------------------- Setup gyroscope offset -----------------------------

    ahrs->setGyroOffset();
    while(1)
        imuLoop(ahrs.get());
}

/*
Mahony AHRS algorithm implemented by Madgwick
See: http://x-io.co.uk/open-source-imu-and-ahrs-algorithms/

Adapted by Igor Vereninov (igor.vereninov@emlid.com)
Provided to you by Emlid Ltd (c) 2014.
twitter.com/emlidtech || www.emlid.com || info@emlid.com
*/

#ifndef AHRS_HPP
#define AHRS_HPP

#include <cmath>
#include <stdio.h>
#include <memory>
#include <Common/InertialSensor.h>

class AHRS{
private:
	float q0, q1, q2, q3;
	float gyroOffset[3];
	float twoKi;
	float twoKp;
	float integralFBx, integralFBy, integralFBz;
    std::unique_ptr <InertialSensor> sensor;
public:
    AHRS(std::unique_ptr <InertialSensor> imu);

    void update(float dt);
    void updateIMU(float dt);
    void setGyroOffset();
    void getEuler(float* roll, float* pitch, float* yaw);

    float invSqrt(float x);
    float getW();
    float getX();
    float getY();
    float getZ();
};


// extern "C"{
//    
// }

extern "C" {
    AHRS* AHRS_py();
    void updateIMU_py(AHRS* ahrs);
    //void getEuler_py(float* roll, float* pitch, float* yaw);
    std::unique_ptr <InertialSensor> get_inertial_sensor( std::string sensor_name);
    std::string get_sensor_name(int argc, char *argv[]);
    void print_help();
    void imuLoop(AHRS* ahrs);
}


#endif // AHRS_hpp

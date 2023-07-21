# Home Cooling Controller
  I implemented the device that interfaces to a TC72 Temperature sensor to provide the
Digital temperature data.[Home]
- I implemented the Polling client as Cooling Controller.[Home]
* I implemented a PID controller to generate a PWM signal based on the
deviation between the read temperature from the sensor and the set temperature point.
The Cooling controller is working based on the following parameters.
1- Temperature sampling period: 500ms.
2- PWM duty cycle range: 0 to 0.73
3- Set temperature is 30.
4- Values of the PID controller arguments are Kp = 0.1, Ki = 0.01 and Kd = 0
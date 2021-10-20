# metro-train-controller
In this report will be analysed the behaviour of a hardware machine operated by  a microprocessor. The purpose of this project is to simulate a controller of a  subway train.

Requirements of the controller:
• Increase and decrease speed as directed by the driver;
• Activate or deactivate normal braking commands as directed by the driver;
• Implementing an emergency button to stop the train running;
• Managing the stop signals;
• Managing communications between traffic managers and drivers showing 
messages;
• Implement system using µVision 4.60 and Stm32f10x microprocessor
The controller must also be able to handle particular and unpredictable situations 
such as the breaking of the train control lever, which could signal two positions 
or none, or a state of maximum acceleration too long. 
In case the lever signals two positions the controller will keep the previous state.
If the lever does not mark any position for more than 3 seconds a state shall be 
activated an emergency procedure that will cause the train to stop.
If the maximum acceleration state persists for more than 4 seconds, the 
controller will automatically bring it to average power without signalling it to the 
driver.

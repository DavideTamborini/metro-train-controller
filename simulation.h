/*----------------------------------------------------------------------------
  Simulate classic train activity
 *----------------------------------------------------------------------------*/

Simulator simulation1[10] = { {idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{maxAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{minAcceleration, 1, 100},
															{idleMode, 1, 100},
															{minBraking, 1, 100},
															{medBraking, 1, 100},
															{maxBraking, 1, 100}
														};
														
/*----------------------------------------------------------------------------
  Simulate stop activity
 *----------------------------------------------------------------------------*/
															
Simulator simulation2[10] = { {idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{maxAcceleration, 1, 100},
															{stop, 3, 100},
															{minBraking, 1, 100},
															{minAcceleration, 1, 100},
															{idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 100}
														};
														
/*----------------------------------------------------------------------------
  Simulate emergency activity
 *----------------------------------------------------------------------------*/														
														
Simulator simulation3[10] = { {idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{maxAcceleration, 1, 100},
															{emergency, 2, 100},
															{minAcceleration, 1, 100},
															{idleMode, 1, 100},
															{minBraking, 1, 100},
															{medBraking, 1, 100},
															{maxBraking, 1, 100}
														};
														
/*----------------------------------------------------------------------------
  Simulate the broken lever of the train | case 1
 *----------------------------------------------------------------------------*/																	
														
Simulator simulation4[10] = { {idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 550},
															{maxAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{minAcceleration, 1, 100},
															{idleMode, 1, 100},
															{minBraking, 1, 100},
															{medBraking, 1, 100},
															{maxBraking, 1, 100}
														};	

/*----------------------------------------------------------------------------
  Simulates the maximum speed for more than 5 seconds
 *----------------------------------------------------------------------------*/																	
														
Simulator simulation5[10] = { {idleMode, 1, 100},
															{minAcceleration, 1, 100},
															{medAcceleration, 1, 100},
															{maxAcceleration, 1, 500},
															{medAcceleration, 1, 100},
															{minAcceleration, 1, 100},
															{idleMode, 1, 100},
															{minBraking, 1, 100},
															{medBraking, 1, 100},
															{maxBraking, 1, 100}
														};				

/*----------------------------------------------------------------------------
  Simulates messages
 *----------------------------------------------------------------------------*/																	
														
Simulator simulation6[10] = { {minAcceleration, 1, 100},
															{'M', 4, 50},
															{'E', 4, 50},
															{'S', 4, 50},
															{'S', 4, 50},
															{minBraking, 1, 100},
															{'A', 4, 50},
															{'G', 4, 50},
															{'E', 4, 50},
															{idleMode, 1, 100}
														};															

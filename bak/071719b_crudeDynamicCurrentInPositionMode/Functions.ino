int CalcMotion(){	//Not used in PWM control mode.
	vel1 = (v_x*gain1*.001)+(v_th*.01);		//Convert v_x and v_th to motor motion. The angular rate (V_th) is added for this motor... 
	vel2 = (v_x*gain2*.001)-(v_th*.01);		//...and subtracted from this one.
}

void CheckConfig(){
	//Read Iset1
	lhlf = EEPROM.read(addr_Iset1l);  //read left half
	rhlf = EEPROM.read(addr_Iset1r);  //read right half 
	Iset1 = lhlf*100 + rhlf;    //Put the two halves back together
	if (Iset1 > 5000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to a default value.
		Iset1 = 200;
	}
	//Read maxIset2
	lhlf = EEPROM.read(addr_maxIset2l);  
	rhlf = EEPROM.read(addr_maxIset2r);  
	maxIset2 = lhlf*100 + rhlf;    //Put the two halves back together
	if (maxIset2 > 3000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to a default value.
		maxIset2 = 500;
	}
	//Read minIset1
	lhlf = EEPROM.read(addr_minIset1l);  //read left half
	rhlf = EEPROM.read(addr_minIset1r);  //read right half 
	minIset1 = lhlf*100 + rhlf;    //Put the two halves back together
	if (minIset1 > 3000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to default value.
		minIset1 = Iset1;
	}
	//Read minIset2
	lhlf = EEPROM.read(addr_minIset2l);  
	rhlf = EEPROM.read(addr_minIset2r);  
	minIset2 = lhlf*100 + rhlf;    //Put the two halves back together
	if (minIset2 > 5000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to default value.
		minIset2 = 100;	
	}
	//Read gain1
	lhlf = EEPROM.read(addr_gain1l);  
	rhlf = EEPROM.read(addr_gain1r);
	gain1 = lhlf*100+rhlf;
	if (gain1 > 10000){	//If the number is bigger than our maximum, assume that the initial gain configuration was never done and reset gain to a default value.
		gain1 = 200;
	}
	//Read gain2
	lhlf = EEPROM.read(addr_gain2l);  
	rhlf = EEPROM.read(addr_gain2r);
	gain2 = lhlf*100+rhlf;
	if (gain2 > 10000){	//If the number is bigger than our maximum, assume that the initial gain configuration was never done and reset gain to a default value.
		gain2 = 600;
	}
	//Read torqueprofile1
	torqueprofile1 = EEPROM.read(addr_torqueprofile1);
	if (torqueprofile1 == 255){
		torqueprofile1 = 0;		//0 = OFF/sine, 1 = ON
	}
	//Read torqueprofile2
	torqueprofile2 = EEPROM.read(addr_torqueprofile2);
	if (torqueprofile2 == 255){
		torqueprofile2 = 0;		//0 = OFF/sine, 1 = ON
	}
	//Read tscoeff2
	tscoeff2 = EEPROM.read(addr_tscoeff2);
	if (tscoeff2 == 255){
		tscoeff2 = 20;
	}
	//Read tsphase2
	lhlf = EEPROM.read(addr_tsphase2l);  //read left half
	rhlf = EEPROM.read(addr_tsphase2r);  //read right half 
	tsphase2 = lhlf*100 + rhlf;    //Put the two halves back together
	if (tsphase2 > 5000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to a default value.
		tsphase2 = 0;
	}
	//Read currentmode1
	currentmode1 = EEPROM.read(addr_currentmode1);
	if (currentmode1 == 255){
		currentmode1 = 0;		//0 = FIXED, 1 = DYNAMIC
	}
	//Read currentmode2
	currentmode2 = EEPROM.read(addr_currentmode2);
	if (currentmode2 == 255){
		currentmode2 = 1;		//0 = FIXED, 1 = DYNAMIC
	}
	//Read commandmode1
	commandmode1 = EEPROM.read(addr_commandmode1);
	if (commandmode1 == 255){
		commandmode1 = 0;		//0 = VELOCITY control, 1 = POSITION control
	}
	//Read commandmode2
	commandmode2 = EEPROM.read(addr_commandmode2);
	if (commandmode2 == 255){
		commandmode2 = 1;		//0 = VELOCITY control, 1 = POSITION control
	}
	//Read sensortype1
	sensortype1 = EEPROM.read(addr_sensortype1);
	if (sensortype1 == 255){
		sensortype1 = 0;		//0 = NONE, 1 = ENCODER, 2 = HALL
	}
	//Read sensortype2
	sensortype2 = EEPROM.read(addr_sensortype2);
	if (sensortype2 == 255){
		sensortype2 = 2;		//0 = NONE, 1 = ENCODER, 2 = HALL
	}
	//Read dir1
	dir1 = EEPROM.read(addr_dir1);
	if (dir1 == 255){
		dir1 = 0;		//0 = NORMAL, 1 = REVERSE
	}
	//Read dir2
	dir2 = EEPROM.read(addr_dir2);
	if (dir2 == 255){
		dir2 = 0;		//0 = NORMAL, 1 = REVERSE
	}
	//Read accel1
	lhlf = EEPROM.read(addr_accel1l);  //read left half
	rhlf = EEPROM.read(addr_accel1r);  //read right half 
	accel1 = lhlf*100 + rhlf;    //Put the two halves back together
	if (accel1 > 10000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to a default value.
		accel1 = 3000;
	}
	//Read accel2
	lhlf = EEPROM.read(addr_accel2l);  //read left half
	rhlf = EEPROM.read(addr_accel2r);  //read right half 
	accel2 = lhlf*100 + rhlf;    //Put the two halves back together
	if (accel2 > 10000){	//If the number is bigger than our maximum, assume that the initial current configuration was never done and reset Iset to a default value.
		accel2 = 3000;
	}
}

void DisplaySettings2(){
	CheckConfig();		//Read EEPROM
	Serial.println(F("Channel 2 Settings:"));
	if (sensortype2 == 0){
		Serial.println(F("   Sensor type: NONE"));
	}
	else if (sensortype2 == 1){
		Serial.println(F("   Sensor type: ENCODER"));
	}
	else if (sensortype2 == 2){
		Serial.println(F("   Sensor type: HALL"));
	}	

	fholder = maxIset2/1000;		//Convert mA to A	
	if (currentmode2 == 0){
		Serial.print(F("   Current is FIXED at "));	
		Serial.print(fholder);
		Serial.println(F("A."));
	}
	else if (currentmode2 == 1){
		Serial.print(F("   Current is DYNAMIC with max set to "));
		Serial.print(fholder);
		Serial.println(F("A."));
	}

	fholder = minIset2/1000;		//Convert mA to A	
	Serial.print(F("   Rest/minimum current: "));			
	Serial.print(fholder);
	Serial.println(F("A."));

	if (commandmode2 == 0){
		Serial.println(F("   Command type: VELOCITY"));
	}
	else if (commandmode2 == 1){
		Serial.println(F("   Command type: POSITION"));
	}

	if (dir2 == 0){
		Serial.println(F("   Directionality: NORMAL"));
	}
	else if (dir2 == 1){
		Serial.println(F("   Directionality: REVERSE"));
	}

	Serial.print(F("   Command gain: "));
	Serial.println(gain2);

	Serial.print(F("   Acceleration: "));
	Serial.println(accel2);
	
	if (torqueprofile2 == 0){
		Serial.println(F("   Torque smoothing: OFF"));
	}
	else if (torqueprofile2 == 1){
		Serial.println(F("   Torque smoothing: ON"));
		Serial.print(F("   Torque smoothing aggressiveness: "));
		Serial.println(tscoeff2);
		Serial.print(F("   Torque smoothing phase: "));
		fholder = tsphase2/1000;		//Convert to decimal form
		Serial.println(fholder);
	}
	Serial.println(F("\n\n\n\n"));
}

void TorqueCal1(){ //Drive the motor a certain amount 
	float dummyphaseindex = 0;	
	do {
		vel1 = .003;
		vel2 = 0;
		dummyphaseindex = dummyphaseindex + vel1;
		if(dummyphaseindex >= 14*pi){   //Disable the drive after some number of half commutation cycles. If this number equals the number of magnets, the motor will make one full rotation.
			digitalWrite(U1_En, LOW);    
			digitalWrite(V1_En, LOW);
			digitalWrite(W1_En, LOW);
			break;
		}

		Roll_vel1();
	}
	while(dummyphaseindex < 15*pi);
}   

void TorqueCal2(){ //Drive the motor a certain amount 
	float dummyphaseindex = 0;	
	do {
		vel1 = 0;
		vel2 = .003;
		dummyphaseindex = dummyphaseindex + vel2;
		if(dummyphaseindex >= 14*pi){   //Disable the drive after some number of half commutation cycles. If this number equals the number of magnets, the motor will make one full rotation.
			digitalWrite(U2_En, LOW);    
			digitalWrite(V2_En, LOW);
			digitalWrite(W2_En, LOW);
			break;
		}

		Roll_vel2();
	}
	while(dummyphaseindex < 15*pi);
}   

void adu2amps(){		//Convert current sense value from ADUs to AMPERES.
	I_A = ((-1*I_adu_av+109)/-70)+.05;    //Convert raw current to Amps. Empirically derived. 
}

int PubI(){
	int i = 1;    //A counter and divisor for calculating a running average for current-sensing the PubI() function.
	I_adu_sum = I_adu_sum + analogRead(Isense);
	I_adu_av = (I_adu_av + I_adu_sum)/i;
	I_A = (-1*I_adu_av+109)/-81.92;    //Convert raw current to Amps. Offset derrived empirically.   
	i++;  //Increment counter.
	if (i == 100){     //When the averaging cycle has been completed (as set by value of i here), publish the idraw message and reset the index.
		idraw_msg.data = I_A;
		pub_I.publish(&idraw_msg);
		I_adu_sum = 0;
		I_adu_av = 0;
		i = 1;
	}
}

int SetPower(){
	int i = 0;    //A counter for determining rate of current rise 

	//Check quiescent current draw:
	delay(500);   //Wait for inrush current to settle.
	I_adu_sum = 0;
	I_adu_av = 0;
	for (int i = 1; i <= 200; i++) {    //Check current draw. Sum and average number i times.
		I_adu_sum = I_adu_sum + analogRead(Isense);
		I_adu_av = (I_adu_av + I_adu_sum)/i;  
	}
	adu2amps();
	I_qui = I_A;	
	Serial.print(F("\nDetected quiescent current (A): "));
	Serial.println(I_qui);
	Serial.print(F("\n"));
	delay(2000);
	digitalWrite(U1_En, HIGH);    //Enable each phase
	digitalWrite(V1_En, HIGH);
	digitalWrite(W1_En, HIGH);
	digitalWrite(U2_En, HIGH);
	digitalWrite(V2_En, HIGH);
	digitalWrite(W2_En, HIGH);
  
	//Ramp up power on motor 1 until desired current is detected.
	power1_low = 0;
	do{
		power1 = power1 + 1;    //Ramp up the power with each iteration of this do-while loop.

		//WRITE OUTPUTS
		dutyU1 = (255/2)+(power1*(sin(phaseindex1)));	   
		analogWrite(U1_High,dutyU1);	//Write to the PWM pins.
		dutyV1 = (255/2)+(power1*(sin(phaseindex1+(2*pi/3))));
		analogWrite(V1_High,dutyV1);
		dutyW1 = (255/2)+(power1*(sin(phaseindex1+(4*pi/3))));
		analogWrite(W1_High,dutyW1);

		delay(5);   //Some settling time is needed for accuracy.
		I_adu_sum = 0;
		I_adu_av = 0;
		for (int i = 1; i <= 200; i++) {    //Check current draw. Sum and average number i times.
			I_adu_sum = I_adu_sum + analogRead(Isense);
			if (i == 200){			
				I_adu_av = I_adu_sum/i;
			}  
		} 
		adu2amps();		
		//Serial.print("\nIteration: ");
		//Serial.print(i);
		//Serial.print("\nAmperes: ");
		//Serial.print(I_A);
		if ((i == 50) && (I_A < (I_qui+.02))){   //After several iterations, see if the current is still near the quiescent draw.
			power1 = 0;
			digitalWrite(U1_En, LOW);    //Disable each phase
			digitalWrite(V1_En, LOW);
			digitalWrite(W1_En, LOW);
			break;
		}
		if (I_A < (((minIset1)/1000)+I_qui)){	//Every iteration that the current is less than minIset, save the power to powerx_low. When the routine is completed, this assures that power1_low will contain the proper value.
			power1_low = power1;
		}
		i++;             
	} while (I_A < (((Iset1)/1000)+I_qui)-.04); //As soon as I_A exceeds the user-determined current in amps, exit the loop, thereby maintaining the last power setting.
	if (power1 == 0){
		Serial.println(F("Motor 1 not connected."));
	}
	else {
		Serial.print(F("\nMotor 1 current was set to "));
		Serial.print(I_A);	
		Serial.println(F("A (as measured)"));
	}
	//delay(3000);		//Uncomment for diagnostic reaons (gives time to check displayed value against a meter)
	power1_high = power1;      //Store the discovered power setting so we can set power1 to zero to test the other motor, and so we can reduce power and come back to it in the future.
	power1 = 0;    //Set power to zero so we can test the other motor.

	//Ramp up power on motor 2 until desired current is detected.
	i = 0;
	power2_low = 0;
	do{
		power2 = power2 + 1;    //Ramp up the power with each iteration of this do-while loop.

		//WRITE OUTPUTS
		dutyU2 = (255/2)+(power2*(sin(phaseindex2)));	   //The duty cycle varies with the sine function, which has output between -1 and 1. That is scaled by an amplitude variable, which effectively sets the motor power.This is all offset by half the maximum duty cycle so that the lowest instantaeous duty cycle is always positive.
		analogWrite(U2_High,dutyU2);	//Write to the PWM pins.
		dutyV2 = (255/2)+(power2*(sin(phaseindex2+(2*pi/3))));
		analogWrite(V2_High,dutyV2);
		dutyW2 = (255/2)+(power2*(sin(phaseindex2+(4*pi/3))));
		analogWrite(W2_High,dutyW2);

		delay(5);   //Some settling time is needed for accuracy.
		I_adu_sum = 0;
		I_adu_av = 0;
		for (int i = 1; i <= 200; i++) {    //Check current draw. Sum and average number i times.
			I_adu_sum = I_adu_sum + analogRead(Isense);
			I_adu_av = (I_adu_av + I_adu_sum)/i;  
		}  
		adu2amps();		
		//Serial.print("\nIteration: ");
		//Serial.print(i);
		//Serial.print("\nAmperes: ");
		//Serial.print(I_A);        
		//Serial.println(power2);
		if ((i == 50) && (I_A < (I_qui+.02))){   //After several iterations, see if the current is still near the quiescent draw.
			power2 = 0;
			digitalWrite(U2_En, LOW);    //Disable each phase
			digitalWrite(V2_En, LOW); 
			digitalWrite(W2_En, LOW);
			break;
		}
		if (I_A < (((minIset2)/1000)+I_qui)){	//Every iteration that the current is less than minIset, save the power to powerx_low. When the routine is completed, this assures that power1_low will contain the proper value.
			power2_low = power2;
		}
		i++;  
	} while (I_A < (((maxIset2)/1000)+I_qui)-.04); //As soon as I_A exceeds the user-determined current in amps, exit the loop, thereby maintaining the last power setting.
	if (power2 == 0){
		Serial.println(F("Motor 2 not connected."));
	}
	else {
		Serial.print(F("\nMotor 2 max/fixed current was set to "));
		Serial.print(I_A);	
		Serial.println(F("A (as measured)\n"));
		//Serial.print(F("\nDiagnostic output: power2_high = "));
		//Serial.print(power2);
	}	
	//delay(3000);		//Uncomment for diagnostic reaons (gives time to check displayed value against a meter)
	power2_high = power2;
	power1 = power1_high;    //Re-energize motor 1. Motor 2 is already powered at this point.
	digitalWrite(13,LOW);   //Put the pin 13 LED low to indicate the board is ready to go.
}

void ReadEncoders(){
	if (digitalRead(enc1_pin4) == LOW){
		digitalWrite(13,HIGH);
		delay(500);
		digitalWrite(13,LOW);
	}

	if (digitalRead(enc2_pin4) == LOW){
		digitalWrite(13,HIGH);
		delay(500);
		digitalWrite(13,LOW);
	}
}

void ReadHall2(){
		if (digitalRead(enc2_pin5) == HIGH && enc2_pin5_flag == 0){
				enc2_pin5_flag = 1;
				if (actualvel2 >= 0){ //If velocity is positive
					phaselag2U = phaseindex2 - ((pi+sensphaseoffset2)-sensphasehalfwidth2);  		//-2.2
					if (phaselag2U < 0) {phaselag2U = 0;}
				}
				else { //If velocity is negative
					phaselag2U = fabs(phaseindex2 - ((pi+sensphaseoffset2)+sensphasehalfwidth2));		//-5.3
				}
				Serial.print("phaselag2U = ");
				Serial.println(phaselag2U);
		}
		else if (digitalRead(enc2_pin5) == LOW && enc2_pin5_flag == 1){
			enc2_pin5_flag = 0;
		}
		if (digitalRead(enc2_pin4) == HIGH && enc2_pin4_flag == 0){
				enc2_pin4_flag = 1;
				if (actualvel2 >= 0) { //If velocity is positive
					phaselag2V = phaseindex2 - (((2*pi)/3+sensphaseoffset2)+sensphasehalfwidth2);		//-4.6	 
					if (phaselag2V < 0) {phaselag2V = 0;}
				}
				else { //If velocity is negative
					phaselag2V = fabs(phaseindex2 - (((2*pi)/3+sensphaseoffset2)-sensphasehalfwidth2)); 		//-1.0
				}
				Serial.print("phaselag2V = ");
				Serial.println(phaselag2V);
		}
		else if (digitalRead(enc2_pin4) == LOW && enc2_pin4_flag == 1){
			enc2_pin4_flag = 0;
		}
		if (digitalRead(enc2_pin3) == HIGH && enc2_pin3_flag == 0){
				enc2_pin3_flag = 1;
				if (actualvel2 >= 0) { //If velocity is positive
					phaselag2W = phaseindex2 - ((pi/3+sensphaseoffset2)-sensphasehalfwidth2);		//-0.3
					if (phaselag2W < 0) {phaselag2W = 0;}
				}
				else { //If velocity is negative
					phaselag2W = fabs(phaseindex2 - ((pi/3+sensphaseoffset2)+sensphasehalfwidth2)); 	//-3.2
				}
				Serial.print("phaselag2W = ");
				Serial.println(phaselag2W);
		}
		else if (digitalRead(enc2_pin3) == LOW && enc2_pin3_flag == 1){
			enc2_pin3_flag = 0;
		}
}

void CheckMode(){
	//********USB**********
	if(digitalRead(mode_usb) == LOW){     //If in USB mode, get velocity data from the ROS node.
		//Serial.end();
		nh.spinOnce();    //Spin the node once (check for and process messages), hence retrieving values for v_x and v_th from the ROS. We use nh.spinOnce() instead of nh.spin() because this is already in a main loop and we want this thing to happen once every time through the loop.
		CalcMotion();   //Take the raw velocity obtained according to the current mode setting (ROS or I2C) and convert to forward rate (v_x) and angular rate (a_z), and then calculate the rates needed for each motor.
		PubI();
		pwmflag = false;
	}

    //********I2C**********
	if(digitalRead(mode_i2c) == LOW){     //Check for I2C stuff  
		//mode
		//CalcMotion();	
		pwmflag = false;
	}

    //********Config**********
	while(digitalRead(mode_config) == LOW){     //Check for configuration mode
		digitalWrite(U1_En, LOW);    //Enable each phase
		digitalWrite(V1_En, LOW);
		digitalWrite(W1_En, LOW);
		digitalWrite(U2_En, LOW);
		digitalWrite(V2_En, LOW);
		digitalWrite(W2_En, LOW);
		SerialPrompt();   
		pwmflag = false; 
	}

	//********PWM**********
	if((digitalRead(mode_usb) == HIGH) && (digitalRead(mode_i2c) == HIGH) && (digitalRead(mode_config) == HIGH))  {     //If none of the mode pins are LOW, read the PWM inputs to control each motor's velocity independently.
		if(pwmflag == false) {    //if we weren't already in this mode before we need to check which PWM ports have signals coming in.
			if(pwm1_t > 0){    //Is the pwm active?
				pwm1active = true;    //If so, we'll keep this channel on
			}
			else{
				pwm1active = false;   //If not, keep it off so the main loop doesn't get slowed down by an inactive PWM
				digitalWrite(U1_En, LOW);    //Disable this channel
				digitalWrite(V1_En, LOW);
				digitalWrite(W1_En, LOW);
			}
			if(pwm2_t > 0){
				pwm2active = true;
			}
			else{
				pwm2active = false;
				digitalWrite(U2_En, LOW);    //Disable this channel
				digitalWrite(V2_En, LOW);
				digitalWrite(W2_En, LOW);
			}
		}

		if(pwm1active == true){     //Only get velocity data from this PWM channel if it was found to be connected above    
			if (commandmode1 == 0){	//if in velocity mode
				vel1 = (pwm1_t-1500)*.0000006*gain1;	//Normal PWM servo pulsewidth goes from 800 to 2200ms. We subtract 1500ms, corresponding to the middle of that range, so that pulses in the range 800-1499 will have negative velocity, and 1501-2200 will be positive. 
			}
			else if (commandmode1 == 1){
				pos1 = (pwm1_t-1500)*.00005*gain1;
			}
		}

		if(pwm2active == true){    //Only get velocity data from this PWM channel if it was found to be connected above
			if (commandmode2 == 0){
				vel2 = (pwm2_t-1500)*.0000006*gain2;
			}
			else if (commandmode2 == 1){
				pos2 = (pwm2_t-1500)*.00005*gain2;
			}
		}
		pwmflag = true;
	}
}

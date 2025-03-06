# Wall-Following Car with Arduino

Check out my two YouTube channels for more content:  
1. [Mrzaizai2k - AI](https://www.youtube.com/channel/UCFGCVG0P2eLS5jkDaE0vSfA) (NEW)  
2. [Mrzaizai2k](https://www.youtube.com/channel/UCCq3lQ1W437euT9eq2_26HQ) (Old)  

## Maze Solving with Wall Follower Algorithm

The video below explains the project in detail:  

[<img src="https://img.youtube.com/vi/ztjC2I54o4M/maxresdefault.jpg" width="100%">](https://youtu.be/ztjC2I54o4M)



- **My Arduino Code:** [GitHub Repository](https://github.com/mrzaizai2k/Wall-following-car-with-Arduino)  
- **References:**  
  1. [Using the HC-SR04 Distance Sensor](http://arduino.vn/bai-viet/233-su-dung-cam-bien-khoang-cach-hc-sr04)  
  2. [Using LCD 16x2 with I2C Interface](https://arduinokit.vn/giao-tiep-i2c-lcd-arduino)  
  3. [Using L293D Motor Driver Shield](http://arduino.vn/bai-viet/429-lam-du-xe-voi-module-dieu-khien-dong-co-l293d)  
  4. [Full Tutorial Video](https://www.youtube.com/watch?v=zLAac7GA5HE)  

---

## Table of Contents
1. [Overview](#overview)  
2. [Functions](#functions)  
   2.1 [Stop (`dung()`)](#stop-dung)  
   2.2 [Move Forward (`tien()`)](#move-forward-tien)  
   2.3 [Move Backward (`lui()`)](#move-backward-lui)  
   2.4 [Turn Left (`retrai()`)](#turn-left-retrai)  
   2.5 [Turn Right (`rephai()`)](#turn-right-rephai)  
3. [Distance Measurement](#distance-measurement)  

---

## Overview <a name="overview"></a>

This Arduino project controls a robot built with an Arduino Uno, an ultrasonic sensor (HC-SR04), and four DC motors (controlled via the AFMotor library). The robot navigates by measuring distances in front and on its sides, enabling it to stop, move forward, move backward, or turn left and right based on its surroundings.

## Functions <a name="functions"></a>

### 2.1 Stop (`dung()`) <a name="stop-dung"></a>
Stops all motors and displays "DUNG" (Vietnamese for "STOP") on an LCD screen.

### 2.2 Move Forward (`tien()`) <a name="move-forward-tien"></a>
Moves the robot forward with customizable speed settings.

### 2.3 Move Backward (`lui()`) <a name="move-backward-lui"></a>
Moves the robot backward with adjustable speed.

### 2.4 Turn Left (`retrai()`) <a name="turn-left-retrai"></a>
Turns the robot to the left.

### 2.5 Turn Right (`rephai()`) <a name="turn-right-rephai"></a>
Turns the robot to the right.

## Distance Measurement <a name="distance-measurement"></a>

1. **Front Distance (`distancefront()`):** Uses the HC-SR04 sensor to measure the distance ahead of the robot.  
2. **Side Distance (`distanceside()`):** Measures the distance to the side using the HC-SR04 sensor.  

The main program loop continuously measures distances, updates the LCD with the robot's status, and adjusts its movements based on button inputs. The code is flexible, allowing users to tweak motor speeds and distance thresholds to meet specific project needs.

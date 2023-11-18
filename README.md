# Wall-following-car-with-Arduino
Check out my 2 YOUTUBE channels for more:
1. [Mrzaizai2k - AI](https://www.youtube.com/channel/UCFGCVG0P2eLS5jkDaE0vSfA) (NEW)
2. [Mrzaizai2k](https://www.youtube.com/channel/UCCq3lQ1W437euT9eq2_26HQ) (old)

Maze solving with wall follower algorithm 

The video pretty much explains it all:

[**YOUTUBE LINK: Wall following car with Arduino_Mrzaizai2k**](https://www.youtube.com/watch?v=ztjC2I54o4M&list=PLwPBf6q2CQ-btTIgsZXhBJY6vKkSxBtxv)

My Arduino Code: https://drive.google.com/open?id=1q8XpYHIeALv2iSNh2W_P4Ljrv5eGn_sh

Reference: 

1. Sử dụng cảm biến khoảng cách HC-SR04: http://arduino.vn/bai-viet/233-su-dung-cam-bien-khoang-cach-hc-sr04
2. Sử dụng LCD 16x2 với giao tiếp I2C: https://arduinokit.vn/giao-tiep-i2c-lcd-arduino
3. Sử dụng motor driver shield L293D: http://arduino.vn/bai-viet/429-lam-du-xe-voi-module-dieu-khien-dong-co-l293d
4. Clip full tutorial: https://www.youtube.com/watch?v=zLAac7GA5HE 

</br>

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

This Arduino code controls a robot equipped with an Arduino Uno, an ultrasonic sensor (HC-SR04), and four DC motors (AFMotor library). The robot's movements are determined based on measured distances in the front and on the sides. The main functionalities include stopping the robot, moving it forward and backward, and turning it left or right.

## Functions <a name="functions"></a>

### 2.1 Stop (`dung()`) <a name="stop-dung"></a>
Stops all motors, displaying "DUNG" on an LCD.

### 2.2 Move Forward (`tien()`) <a name="move-forward-tien"></a>
Moves the robot forward with adjustable speed.

### 2.3 Move Backward (`lui()`) <a name="move-backward-lui"></a>
Moves the robot backward with adjustable speed.

### 2.4 Turn Left (`retrai()`) <a name="turn-left-retrai"></a>
Turns the robot to the left.

### 2.5 Turn Right (`rephai()`) <a name="turn-right-rephai"></a>
Turns the robot to the right.

## Distance Measurement <a name="distance-measurement"></a>

1. **Front Distance (`distancefront()`):** Measures the distance in front using the HC-SR04 sensor.

2. **Side Distance (`distanceside()`):** Measures the distance on the side using the HC-SR04 sensor.

The main loop continuously measures distances, displays the status on an LCD, and controls the robot's movements based on button input. The code provides flexibility for customizing motor speeds and distance thresholds to suit specific project requirements.

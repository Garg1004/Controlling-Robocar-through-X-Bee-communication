# Buggy Car Control using Arduino and XBee

This project involves a line-following robotic buggy that is controlled wirelessly using XBee modules and programmed with Arduino. The buggy can detect obstacles, follow lines using IR sensors, and stop at predefined checkpoints (gantries) based on sensor inputs. It was developed as a part of a hardware implementation challenge.

## Components Used

- Arduino UNO
- XBee modules (for wireless communication)
- IR sensors (for line following)
- Ultrasonic sensor (for obstacle detection)
- Motor driver (L298N)
- DC motors and chassis
- Jumper wires, breadboard, wheels, and battery pack

## Project Overview

Once powered on and the signal `'M'` is received via XBee, the buggy starts moving and follows a black line using two IR sensors. It identifies different gantries based on input pulse values and reacts accordingly. The ultrasonic sensor is used to detect any obstacle in front of the buggy and stop it if the distance is below 30 cm.

### Movement Logic

- **Forward:** Both sensors detect the line
- **Left:** Left sensor off the line
- **Right:** Right sensor off the line
- **Stop:** Both sensors off line (used at turns or checkpoints)

### Gantry Detection

The buggy reads analog input and interprets it based on predefined pulse ranges:
- Gantry 1: 1500–2000
- Gantry 2: 2500–3000
- Gantry 3: 500–1000

It counts each event (turn, forward, stop) and acts based on the value of a `count` variable using `millis()` for time tracking.

## How It Works

1. Upload the code to Arduino using the Arduino IDE.
2. Power the buggy and XBee modules.
3. Send the letter `'M'` via the XBee serial terminal to start.
4. The buggy begins line-following and takes turns or stops based on sensor inputs and gantry detections.

## Notes

- Make sure both XBee modules are paired with the same PAN ID and baud rate (9600).
- Adjust delay and sensor threshold values as per the lighting conditions and surface.
- Test the buggy on a black line track with turns and checkpoints.


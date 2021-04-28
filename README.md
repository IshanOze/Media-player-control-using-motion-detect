# Media-player-control-using-motion-detect
Media player is controlled by using python and arduino. Play/Pause and Volume Up/Down is controlled although more features can be added.
A ultrasonic sensor(HC SR04) is connected to digital pins of Arduino Uno.(The Trigger pin and Echo pin can be connected to any of the digital pins)
Ultrasonic sensor detects if any obstruction is introduced between it's predefined range and executes respective commands.
The respective commands are sent to Python code through COM port and it simulates the key press with the help of pyautogui.


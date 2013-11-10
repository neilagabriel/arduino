BYFR Demo Sketch for Arduino

Choose the sketch based on the version of the Arduino integrated development
environment (IDE) you are using.

If you have Arduino 1.0 IDE, download the file labeled popmech_robot_10.zip. If you have 
for pre-release Arduino IDE (0022 or later), download popmech_robot.zip.

You need to unpack this archive into your Arduino sketch directory. This directory is 
where the Arduino stores the sketches you create and edit. The exact location depends 
on your operating system. On Windows XP, for example, it's located at My Documents\Arduino.

Then:

1. Close the Arduino IDE software, if it's running.
2. Open the popmech_robot folder that you just downloaded and unpacked.
3. Inside the popmech_robot folder is another folder named IRremote. Move it to the sketch 
libraries folder (it's a directory within the Arduino sketch folder -- for example, My 
Documents\Arduino\libraries). If there isn't already a folder called libraries, create one.
4. Restart the Arduino IDE.
5. Verify that the IRremote library has been successfully installed by choosing Sketch-
>Import Library. You should see a reference to IRremote in the pull-down list.
6. Open the popmech_robot demo sketch.
*  For Arduino 1.0 IDE, open popmch_robot_10.ino.
*  For Arduino pre-release, open popmech_robot.pde.


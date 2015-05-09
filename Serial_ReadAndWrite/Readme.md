# Serial port - Read & Write

This is a simple test using the USB connection with the computer as a
serial port to exchange data. You can use minicom to read data and use
ECHO (or minicom) to send data.

How to use it
---

I'll assume you have minicom installed and arduino is using ACM0.

1. Upload this code to your arduino.
2. Run minicom -b 9600 -o -D /dev/ttyACM0 
3. You should see "Hello world" and an (increasing) integer.
4. Type a character while in minicom. After the integer you should see the caracter you typed.
5. Run echo "Write this." >> /dev/ttyACM0
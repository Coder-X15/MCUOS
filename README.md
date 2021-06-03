# MCUOS
Operating system(OS) simulator for Arduino devices
--------

I had to create and delete and then create again and delete another repository of the same name, and this is the final one I got after days of working 😅. The previous ones weren't working well and didn't have the file system as this one. \
Also, I haven't gone into the depths of CS (computer science) to build this and this one has not much complexity, so beginners may enjoy using this while CS students/ graduates may say "What is this, boy? You seem to have made a mess!"(Needn't be so always; I have been able to successfully implement multithreading. I'll only have to find a way to implement multitasking).

## What's new?
I have added a Python-based (version 3 or above) based configuration script that will let users configure the library for their device. This has to be run right after you install the library, and please don't forget to have the following data in your hand:
* The LCD shield/device pinout
* The `analogRead()` values of the buttons on the button interface of the LCD or that of your custom-made buttonset. 
* The board you have (currently supports `{uno/nano/mega}` - input either of the three).

## What is this ?
----
A small OS simulator I made for those who wish to make DIY smartwatches and stuff. Current device support goes to an LCD shield with pin configuration {rs, en, d4, d5, d6, d7} = {8,9,4,5,6,7} and analogue values for the buttons in the button interface as in the `constants.h ` file (the pin configuration is also there; you can fork my repo and edit the files to make a version for yourself).To run it, compile and upload the `RunOS.ino` sketch from File>Examples>MCUOS in the File menu onto the boad. I am planning to include a setup script later so that you may set your version of the OS up with the pin configs and button values of your devices.

## What is this capable of?
Currently, you can:
* Do multithreading, but due to a bit of less-planned programming, not all threads would be running as long as the respective subroutine handlers(the components of the apps that have to be run either in th foreground or in the background are stored in the order of their priority number (from 0 to 9) in here and run sequentially) aren't called.
* Create small apps that you'd love to have on your device, but there are limitations to the number of apps you can make in this version : a total of 10 apps can be added in the app tray where the first one is the launcher. Out of the remaining nine, the first one is the sample app which you can replace with another app of your preference.
* Create a custom launcher. Mine is an ad hoc version which shows no app name and requires you to check the serial monitor to see if you're gonna choose the right app :sweat_smile: 

## How can you contribute?
----
* Perhaps a star?
* Fork and make your own version of this (one with device modifications would be most suitable; I didn't have the stuff to make a smartwatch, so maybe you can edit the `Display.h` file in the `hardware` folder and the occurences of the functions in that files to make a version fit for  TFT shield or OLED display - when doing so please ensure that you make the necessary changes to the `constants.h` file). 
* Make a new release of this.

Here's a screenshot of the setup script for the OS (in RunOS.ino) : ![pic1](https://github.com/Coder-X15/MCUOS/blob/main/screenshots/pic1.jpg)

And yes, please don't forget to contribute or give this a star! 😉

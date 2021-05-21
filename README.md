# MCUOS
Operating system(OS) simulator for Arduino devices
--------

I had to create and delete and then create again and delete another repository of the same name, and this is the final one I got after days of working 😅. The previous ones weren't working well and didn't have the file system as this one. \
Also, I haven't gone into the depths of CS (computer science) to build this and this one has not much complexity, so beginners may enjoy using this while CS students/ graduates may say "What is this, boy? You seem to have made a mess!"(Needn't be so always; I have been able to successfully implement multithreading. I'll only have to find a way to implement multitasking).

## What is this ?
----
A small OS simulator I made for those who wish to make DIY smartwatches and stuff. Current device support goes to an LCD shield with pin configuration {rs, en, d4, d5, d6, d7} = {8,9,4,5,6,7} and analogue values for the buttons in the button interface as in the `constants.h ` file (the pin configuration is also there; you can fork my repo and edit the files to make a version for yourself). I am planning to include a setup script later so that you may set your version of the OS up with the pin configs and button values of your devices.

## What is this capable of?
Currently, you can:
* Do multithreading, but due to a bit of less-planned programming, not all threads would be running as long as the respective subroutine handlers(the components of the apps that have to be run either in th foreground or in the background are stored in the order of their priority number (from 0 to 9) in here and run sequentially) aren't called.
* Create small apps that you'd love to have on your device, but there are limitations to the number of apps you can make in this version : a total of 10 apps can be added in the app tray where the first one is the launcher. Out of the remaining nine, the first one is the sample app which you can replace with another app of your preference.
* Create a custom launcher. Mine is an ad hoc version which shows no app name and requires you to check the serial monitor to see if you're gonna choose the right app :sweat_smile: 

## How can you contribute ?
----
* Perhaps a star?
* Fork and make your own version of this (one with device modifications would be most suitable; I didn't have the stuff to make a smartwatch, so maybe you can edit the `Display.h` file in the `hardware` folder and the occurences of the functions in that files to make a version fit for  TFT shield or OLED display - when doing so please ensure that you make the necessary changes to the `constants.h` file). 
* Make a new release of this.

Now, simply saying that it's an OS simulator gives rise to a few questions:
> 1. How should I make apps for my device?
> 2. How can I register the apps in the system?
> 3. How should I use the devices connected to my Arduino unit?

Let's look into those.

1.  How should I make apps for my device? \
    Well, you can check out the script for a sample app (in the `Sample_App` file) in the `apps` directory. There, you'll find how you to make your first app. You may also check     the code for the launcher in `Launcher.h` \
    Also, I have added a new app : the flashlight app (at index 2) using which you can toggle an LED connected to pin 3 on or of using the UP and DOWN buttons. To quit the app,     press the SELECT button.
2.  How can I register the apps in the system? \
    That just requires a few `#include` directives to include the headers for your own apps and a few `app_tray.add_app(app_name, app_name.priority)` lines replacing `app_name`     with the name of the object that refers to you app in the `load` function of the launcher.
3.  How should I use the devices connected to my Arduino unit? \
    * That can be done using the pins that are free from use, but that too requires you to set the status of usage of the pins (using the `digital_pinset.set_state(pin_number,    is_in_use)`) to `true` (if in use) or `false` (if not) to avoid meddling with those pins in use).

More info will be added after completion. 

Here's a screenshot of the code I used to set up my test run of the OS: ![pic1](https://github.com/Coder-X15/MCUOS/blob/main/screenshots/pic1.jpg)

And yes, please don't forget to contribute or give this a star! 😉

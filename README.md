# MCUOS
Operating system(OS) simulator for Arduino devices
--------

I had to create and delete and then create again and delete another repository of the same name, and this is the final one I got after days of working 😅. The previous ones weren't working well and didn't have the file system as this one. \
Also, I haven't gone into the depths of CS (computer science) to build this and this one has not much complexity, so beginners may enjoy using this while CS students/ graduates may say "What is this, boy? You seem to have made a mess!".

## What is this ?
----
A small OS simulator I made for those who wish to make DIY smartwatches and stuff. Current device support goes to an LCD shield with pin configuration {rs, en, d4, d5, d6, d7} = {8,9,4,5,6,7} and analogue values for the buttons in the button interface as in the `constants.h ` file (the pin configuration is also there; you can fork my repo and edit the files to make a version for yourself).

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
    For elaborating how that can be done, let me explain as much as I can about it to you. \
    * You have to place your apps in headers (As the `Sample_App.h` file)
    * As you programme your app, you have to first make single-run app-specific subroutines (as `run_duties` in `Sample_App.h`). Then, as you define the class for your app, you       have to code the `load` function to load the subroutines into the `app_scheduler` subroutine handler(i.e., include the line `app_scheduler.add_chunk(subroutine_name,             subroutine_name.priority);` in `load` for all the subroutines you have to add).
    * In the `run` function, you have to add `app_scheduler.run_list();` to run the tasks in the subroutine handler.This ensures that other subroutines added in the list of app-       specific subroutines run even if the resources aren't allowed for them.
    * Also, don't forget to add the priority numbers (0 to 9) to your apps and subroutines. Also, take care to avod giving the same priority number to a group of apps/subroutines \
     However, there are many more things to be taken care about which I'll mention in this `README` file after all's complete and maintained.
2.  How can I register the apps in the system? \
    That just requires a few `#include` directives to include the headers for your own apps and a few `app_tray.add_app(app_name, app_name.priority)` lines replacing `app_name`     with the name of the object that refers to you app in the `load` function of the launcher.
3.  How should I use the devices connected to my Arduino unit? \
    * That can be done using the pins that are free from use, but that too requires you to set the status of usage of the pins (using the `digital_pinset.set_state(pin_number,    is_in_use)`) to `true` (if in use) or `false` (if not) to avoid meddling with those pins in use).

More info will be added after completion. 

Here's a screenshot of the code I used to set up my test run of the OS: ![pic1](https://github.com/Coder-X15/MCUOS/blob/main/screenshots/pic1.jpg)


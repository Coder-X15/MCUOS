## Welcome to MCUOS !!!

I made this with the prime intention of learning a bit more of Arduino and making of Arduino libraries, but it turned out to be a lot more interesting than I thought and hence decided to make this a wonderful tool for DIY device makers.

### What is it?

Speaking from the simplest definitions, this is an OS simulator for Arduino devices (although I called it an OS on Arduino Project Hub :sweat_smile: . This was first intended for personal use, but as I kept building, I ended up with something I thought I'd have never made had I not thought of it. This basically comprises of a launcher, a platform to make apps (not an app itself; it's just a set of libraries) and two kinds of subroutine schedulers (in the sense that you can change the order of the subroutines placed in them). More development is going on (except that being a school student, it will take me some to find a perfect holiday/ spare time for coding nowadays). \
More info on the project is here: [MCUOS- Arduino Project Hub page](https://create.arduino.cc/projecthub/SamRuben123/mcuos-an-os-for-arduino-boards-eacf3b?ref=user&ref_id=1104970&offset=0)

### How should I make it work?

Once the library is added to the list fo libraries on Arduino run the `setup_script.py` and set your board up(for V 2.0 only; else just skip to the next part), you'll only need to upload the `RunOS.ino` skecth from File>Exampls>MCUOS.

### Pics/Videos

![OS-setup](https://github.com/Coder-X15/MCUOS/blob/main/screenshots/pic1.jpg)

### Boards supported:
#### *v 1.0*
* Uno

#### *v 2.0*
* Uno
* Mega
* Nano

### Inspriation:
1. [Arduios by JohsProject](https://github.com/JohnsProject/Arduios)
2. [FreeRTOS by feilipu](https://github.com/feilipu/Arduino_FreeRTOS_Library)

### Credits
1. [per1234](https://github.com/per1234)
2. Whoever contributes hereafter.

### Bugs
* No memory management utility in `src/kernel`

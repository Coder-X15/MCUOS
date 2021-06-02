''' Setup script (Python-based); works best with Python 3 or above'''
''' The below dictionary contains the items to set up.
    Once the corresponding values are given,
    each line is printed into the constants.h file '''
#my logo; I badly needed one
logo_matrix = [
                "mmmmmmmm         mmmmmmmm     cccccccccccc     uuuuu           uuuuu     oooooooooooo      sssssssssssss ",
                "mmmm mmmm       mmmm mmmm    cccccccccccccc    uuuuu           uuuuu    oooooooooooooo    sssssssssssssss",
                "mmmm  mmmm     mmmm  mmmm   cccccccccccccccc   uuuuu           uuuuu   oooooooooooooooo  ssss        ",
                "mmmm   mmmm   mmmm   mmmm  cccccc              uuuuu           uuuuu  oooooo     oooooo  ssss        ",
                "mmmm    mmmm mmmm    mmmm  ccccc               uuuuu           uuuuu  ooooo       ooooo   ssss", 
                "mmmm     mmmmmmm     mmmm  cccc                uuuuu           uuuuu  oooo         oooo    ssssssssssssss ",  
                "mmmm      mmmmm      mmmm  ccccc               uuuuu          uuuuu   ooooo       ooooo      sssssssssssss",
                "mmmm       mmm       mmmm  cccccc              uuuuuu        uuuuuu   oooooo     oooooo                ssss",
                "mmmm                 mmmm   ccccccccccccc       uuuuuuuuuuuuuuuuuu     ooooooooooooooo                ssss",
                "mmmm                 mmmm    cccccccccccccc      uuuuuuuuuuuuuuuu       ooooooooooooo      ssssssssssssss",
                "mmmm                 mmmm     ccccccccccccccc     uuuuuuuuuuuuuu         ooooooooooo        ssssssssssss",
                "MCUOS - OS simulator for Arduino-based devices",
                "**********************************************"]

#library definition directives
define_directives = [
        "#ifndef constants_h \n",
        "#define constants_h \n"
] 

#button ID's to write
button_setup = [
        "#define BT_UP 0 \n",
        "#define BT_DOWN 1 \n",
        "#define BT_LEFT 2 \n",
        "#define BT_RIGHT 3 \n",
        "#define BT_SELECT 4 \n",
        "#define BT_TEMP 5 \n"
] 
#LCD pinout setup
setup_items = {
	"LCD rs pin":"#define RS {0}",
	"LCD en pin":"#define EN {0}",
	"LCD data pin 4":"#define D4 {0}",
	"LCD data pin 5":"#define D5 {0}",
	"LCD data pin 6":"#define D6 {0}",
	"LCD data pin 7":"#define D7 {0}"
} 
#button interface setup 
analog_values = {
        "UP button analogue output" : "#define UP {0}",
        "DOWN button analogue output" : "#define DOWN {0}",
        "LEFT button analogue output" : "#define LEFT {0}",
        "RIGHT button analogue output" : "#define RIGHT {0}",
        "SELECT button analogue output" : "#define SELECT {0}"
}
#board names
boards = {
	"uno":["#define ANALOG 6 \n", "#define DIGITAL 14 \n"],
	"nano":["#define ANALOG 8 \n", "#define DIGITAL 14 \m"],
	"mega":["#define ANALOG 16 \n", "#define DIGITAL 54 \n"]
}


def prompt():
    '''Keypress prompt'''
    input("Press ENTER to continue")
	
def mainloop():
    ''' main loop'''
    for line in logo_matrix:
        print(line)
    print("Welcome to the MCUOS setup!")
    print("Please provide the required data asked for")
    prompt()
    with open("src/constants.h",'w') as config_file:
        for line in define_directives:
            config_file.write(line)
        for buttonID in button_setup:
            config_file.write(buttonID)
        print("___________________________________")
        print("LCD Pinout setup")
        for item in setup_items.keys():
            value = int(input(item + ":"))
            config_file.write(setup_items[item].format(value) + "\n")
        print("___________________________________")
        print("Button interface analogue values setup")
        for item in analog_values.keys():
            value = int(input(item + ":"))
            config_file.write(analog_values[item].format(value) + "\n"
	print("___________________________________")
	print("Board setup")
	print("** Note: You should edit the baud rate in RunOS.ino according to the baud rate supported by your board")
	board = input("board : (out of {uno / nano / mega})")
	for stmt in boards[board.lower()]:
		config_file.write(stmt)
	config_file.write("#endif")
        print("Thanks! We've set up the configuration file for your device.")
        print("Now you'll only need to upload the RunOS.ino sketch from File>Examples>MCUOS to upload MCUOS!")
        config_file.close()
        prompt()

if __name__ == '__main__':
    mainloop()

# Christmas Light Tutorial
This is tutorial on how I made my Christmas light display in 2019, video here: https://www.youtube.com/watch?v=S6fs69brKvg.

## Requirements
### Software required
- Vixen: http://www.vixenlights.com/downloads/vixen-3-downloads/
- Arduino IDE: https://www.arduino.cc/en/software

### Recommended computer spec
- At least 8gb RAM
- At least 2 cpu cores

NOTE: When using vixen and when running your show, I would suggest stopping all unneccesary background and foreground applications to help out vixen, especially if you've got an older laptop.

### Hardware required
- Arduino Mega + appropriate USB cable
- 8 mechanical relays (for arduino)
- 8 mosfets (P40NF10L)
- Resistors... 
- Breadboards (1x small, 1x large)
- Plain old solar powered 'string' christmas lights (I have 8)
- Plain old 'string' christmas lights that aren't solar powered (I have 4)
- 2x WS2812B 5 metre pixel strips (30 per metre I think...)
- Jumper wires (for arduino)
- An old computer ATX PSU (something that can supply a lot of 5v and 3v)
- A colossal amount of twin core speaker cable (the cheap stuff)
- A thin metal rod to poke cables through the wall

### Tools required
- Screw drivers
- Ladder
- Most likely a soldering iron + solder + pliers + side cutters etc etc
- Multimeter

### Knowledge required
- Basic electronics
- Basic computer knowledge
- Maybe basic soldering

## Initial steps
### Setting up the arduino
1. Open up the attached arduino file in the arduino IDE
2. Connect the Arduino Mega with a usb cable
3. Go to Tools > Board > Select 'Arduino Mega or Mega 2560'
4. Go to Tools > Port > Select which ever one seems to make sense, or just guess until it works
5. Click the Upload button
6. If it worked, yay! If it didn't, start googling.

### Setting up Vixen
*NOTE: I have uploaded my config file here. If that's all you need you can just download and load that, if you want to know how I made it, follow the steps below.*
1. Start Vixen
2. Click "Setup Display"
*On the left-hand side:*
3. Add "Single Item" and try and name it appropriately
4. Click 'No' if it asks about a dimming curve
5. Select "They are a single color..."
6. Rinse and repeat step 3-5 for as many non-pixel lights as you have (12 for me)
7. Add a "Pixel grid", with dimensions Height=1, Width=300 and orientation horizontal
8. Select "No" dimming curve
9. Select "They can be any color.."
*On the right hand side:*
10. Add a "generic serial" controller
11. Set # of outputs to 912
12. Click on the name of the controller and click the cog down the bottom
13. Click "setup/change serial port", set it to whatever port the arduino is on (go to device manager on windows to find out), set a baud rate of 1048576, parity none
14. Click OK, then select "Send a text header", and in the text box type ">>300<<" (without the ""). Click OK.
15. On the left hand side, select the group of pixels. On the right hand side, using shift, select output 1-900. Click "Patch Elements".
16. On the left hadn side, using shift, select the non-pixel elements (12 in my case), and on the right hand side select output 901-912. Click "Patch Elements".
17. Click "OK". That should be all you have to do to set up vixen, however every time you reconnect the arduino you'll probably have to come back here, click on the controller name, click the cog and change the serial port.


### Setting up the pixel strip
1. Connect both of the pixel strips together
2. Connect the data pin (the middle one) to the arduino (pin 11 in the script). *NOTE: Try to keep data lines, especially 1wire-type data lines, SHORT. If they get too long, they can have issues.*
3. Connect the positive pins from the pixel strip to the 5v supply (red wires) on the PSU
4. Connect the negative pins to the black wires on the PSU
*NOTE: You need to run a length of wire from the center of the pixel strip (meaning the point where the two sets join together) back to the PSU and connect it to the same + and - terminals as you did for the + and - pins at the start of the strip. The wires inside of the pixel strip are very small and if you don't add a "power boost" in the middle of the strip, the pixels at the end furtherest from the PSU end up a bit dim.*
5. Connect a wire from the negative terminal on the PSU to the ground on the arduino.

### Setting up other lights
*There's no straight forward way of setting up the non-pixel lights because they're all a bit different. I'll put a general guide here, and also a troubleshooting guide below with things to try if you get weird/bad results.*
1. Plug all mosfets into the breadboard.
*MOSFET Pins - Hold the mosfet so you're looking at the text. (Mosfets are what make the lights fade in and out, they are controlled by the arduino).  
__LEFT LEG__: The control pin (aka the gate)  
__MIDDLE LEG__: The output pin (aka the drain)  
__RIGHT LEG__: The input pin (aka the source)  *

**__NOTE__: The mosfet source must be fed from the negative wire coming from the power supply, and the drain must feed the negative wire going to the lights. THE POSITIVE WIRE HAS NOTHING TO DO WITH THE MOSFET AND DOESN'T HAVE ANYTHING TO DO WITH IT.  **

2. All of the input pins also need to be joined together and connected to the ground on the arduino. This is easiest to do with a second small breadboard.
3. All of the lights go through a mosfet except for the multicoloured lights (which go on the bush), and the two sets of rope lights.
4. The warm white lights have their own power supply which plugs into the wall. The rest come out of the 3.3v supply from the PSU (I think it's the orange wire). 

**If things aren't working or they're acting weird, you can try adding a 10Kohm resister between the gate and the drain or the gate and the source. Just find something that works, it might be different for each lights. Another thing to note: some of the mosfets work better than others for some unknown reason, so if the lights are very dim when they should be off, try changing the mosfet, or adding a 10kohm resistor somewhere, and make sure the source is connected to a common ground with the other sources on the arduino.**

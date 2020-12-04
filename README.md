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
1. Start Vixen
2. Click "Setup Display"

### Setting up the pixel strip
1. Connect both of the pixel strips together
2. Connect the data pin (the middle one) to the arduino (pin 11 in the script). *NOTE: Try to keep data lines, especially 1wire-type data lines, SHORT. If they get too long, they can have issues.*
3. Connect the positive pins from the pixel strip to the 5v supply (red wires) on the PSU
4. Connect the negative pins to the black wires on the PSU
*NOTE: You need to run a length of wire from the center of the pixel strip (meaning the point where the two sets join together) back to the PSU and connect it to the same + and - terminals as you did for the + and - pins at the start of the strip. The wires inside of the pixel strip are very small and if you don't add a "power boost" in the middle of the strip, the pixels at the end furtherest from the PSU end up a bit dim.*


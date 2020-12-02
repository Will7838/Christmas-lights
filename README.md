# Christmas-lights
This is tutorial on how I made my Christmas light display in 2019, video here: https://www.youtube.com/watch?v=S6fs69brKvg.

### Software required
- Vixen: http://www.vixenlights.com/downloads/vixen-3-downloads/
- Arduino IDE: https://www.arduino.cc/en/software

### Recommended computer spec
- At least 8gb RAM
- At least 2 cpu cores

NOTE: When using vixen and when running your show, I would suggest stopping all unneccesary background and foreground applications to help out vixen, especially if you've got an older laptop.

### Hardware required
- Arduino Mega + USB cable for it
- 8 mechanical relays
- 8 mosfets (P40NF10L)
- Resistors
- Breadboards (1x small, 1x large)
- Plain old solar powered 'string' christmas lights
- Plain old 'string' christmas lights that aren't solar powered
- Jumper wires
- An old computer PSU
- A colossal amount of twin core speaker cable (the cheap stuff)
- A thin metal rod to poke cable through the wall

### Tools required
- Screw drivers
- Ladder
- Maybe a soldering iron
- Multimeter

### Initial steps
##### Planning
- Plan your display, figure out how many 'dumb' and 'smart' lights you're going to use.
##### Setting up the arduino
1. Open up the attached arduino file in the arduino IDE
2. Connect the Arduino Mega with a usb cable
3. Go to Tools > Board > Select 'Arduino Mega or Mega 2560'
4. Go to Tools > Port > Select which ever one seems to make sense, or just guess until it works
5. Click the Upload button
6. If it worked, yay! If it didn't, start googling.

##### Setting up Vixen
1. Start Vixen
2. Click "Setup Display"

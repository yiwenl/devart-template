# Sound Technology


## Pure Data

[Pure Data]('http://puredata.info', 'Pure Data') (or pd for short) is a visual programming language with a node-based syntax, that is widely used for procedural audio (and to a lesser extent, visual) coding. 

It was chosen for this project (over alternatives such as fmod and SuperCollider) partly because of the rich variety of code examples and modules available from the community, but also because its layout is great for experimentation and just trying things out!



In order to communicate with Node.js, we chose OSC as the communication protocol, having had good success with it in the past on the Star Canvas project.

##Ableton Live

Live is one of the leading pieces of music production and performance software, and like Pure Data, is great for both experimentation and production.

In recent versions, the developers have opened up the program more and more to external control, including features like Max for Live, which allows Max/MSP (a close relation to Pure Data) code to run within the software, as well as an external Python API, for which people have written excellent wrappers such as [pyLive]('https://github.com/ideoforms/pylive', 'PyLive').


The intention is to transmit position and camera data from Node.js via OSC to Pure Data, which in addition to producing sounds itself, sends commands to Ableton.

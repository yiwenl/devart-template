#Sound progress - Wind


We started out by taking Andy Farnell’s wind Pure Data patch ([link](http://aspress.co.uk/sd/practical18.php, 'Wind Patch'), which gives us a number of components that total a pretty realistic effect. 

These are buildings (low-end, wideband noise), doorways (smaller band, less stable, more ‘whiney’), branches/wires (high-frequency, unstable), and tree leaves (high volume, more wideband noise). 

We want to reduce the number of parameters for the wind effect down to a more manageable number - as a quick glance at the raw patch shows how many parameters there are currently!

![Wind-Patch-diagram](project_images/wind-patch-image.png?raw=true "Wind Patch Image")

The components are taken out independently and fed into a mixer, where we can change their relative volume. 

In the end, we settled on two main controls for the wind - *Intensity* and *Openness*.

- *Intensity* simple increased the overall volume of the components, crossfading at low values with a gentle white noise generator.

- *Openness* affected the volume of the doorways, branches and tree leaves relative to the ‘buildings’ component - a low value keeps these components low in the mix, giving a more ‘open’ sound - like we’re high in the clouds, whereas a high value (yep it’s the wrong way around!) adds in the whining sounds of objects close by, making for a more ‘closed in’ feel.

The amount of reverb is also controlled by these values, to control the ‘width’ and ‘space’ of the sound.

So what are we going to use to change these values? The camera distance seems like the most obvious choice to affect these values, combined with the weather (from the API mentioned elsewhere) and local height of the mountains.

Audio demo:
(imagine the camera starting far away in the clouds & moving slowly closer to the Giant, with mountains nearby coming into focus)

https://dl.dropboxusercontent.com/u/1597031/The%20Giant/giant-wind-demo.mp3

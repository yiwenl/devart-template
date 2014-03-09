# KUAFU / 夸父
#### Journey of a Giant



## Authors

- YiWen Lin / https://github.com/yiwenl
- Bertrand Carrara / https://github.com/bertrandcarrara



## An interactive story of Kuafu’s myth

Read the full myth: http://en.wikipedia.org/wiki/Kua_Fu </br>

Our project started from a discussion about myths and their values. We found Kuafu’s myth and both loved it. A powerful story of  a giant that decides to catch the sun to put an end to a drought. A first style frame done for fun quickly turned into a full interactive story. 

![Example Image](project_images/scamps/Styleframe_2.jpg?raw=true "Example Image")

Our aim is to create this interactive journey through Google Maps, using its topographic data to render in real time the landscape and to use the Google Map itself as a way to navigate. It's not a game but an explorable story.

Our biggest challenge is the visual aspect of the experience. We really want to create an immersive and compelling world.

One of our reference is the game Journey: [link](‘http://www.youtube.com/watch?v=J-W-WvskODM', ‘Journey Music’)



## Set Up

The experience will be projected on long panoramic format. In front of it a tablet is set up on a stall that allow user to interact with story.

![Example Image](project_images/scamps/scamp_3.jpg?raw=true "Example Image")

The tablet will display Google map in which user can track Kuafu’s progression. Through simple interactions user can control the giant route.

• Tap to change is route
![Example Image](project_images/scamps/scamp_1.jpg?raw=true "Example Image")

• Pinch to zoom in zoom out
![Example Image](project_images/scamps/scamp_4.jpg?raw=true "Example Image")

• Rotate to control the camera.
![Example Image](project_images/scamps/scamp_5.jpg?raw=true "Example Image")


The story  will be break into 3 chapters:

#### Chapter 1 The Raise 
This is the introduction to the journey. Kuafu wakes up, the sun raises and the mountains erect around him.

####Chapter 2 The Chase 
Once the introduction done the Giant starts to chase the sun from east to west. This is where user can start exploring the map. Guiding the Giant toward the sun. 
The landscape surrounding him will be created using the topographic data of Google Map. For example when Kuafu crosses the alp all the mountains will be rendered. Aswell as the mountain will keep other landscape features such as the sea and ocean which Kuafu will swim across.

####Chapter 3 The Fall
The end of the story,after a certain time Kuafu will fall of exhaustion and became a mountain - Your mountain. After naming your mountain your session will be finished.

#### [ Storyboard coming soon ]



## Styleframes

Some initial styleframes - more to come soon!

![Example Image](project_images/Styleframes/Styleframe_1.jpg?raw=true "Example Image")
![Example Image](project_images/Styleframes/Styleframe_3.jpg?raw=true "Example Image")
![Example Image](project_images/Styleframes/Styleframe_4.jpg?raw=true "Example Image")

##Technology Summary
####Node.js

We choose to use Node.js as our core server and build other parts around it. All the terrain  and weather data are stored in here and it will pass these data to frontend and sound module via OSC and websocket.

To get the elevation of the mountains we use an earth elevation map : 

![Example Image](project_images/summary/earth_height.jpg?raw=true "Example Image")

We convert the lat/lng information into x and y coordinates and read the pixel value from this map, the brighter the pixel is, the higher the mountain is going to be. Here is a quick test of 3D map using the values getting from this elevation map.

(Taiwan)

![Example Image](project_images/summary/height_Taiwan.jpg?raw=true "Example Image")

(Japan)

![Example Image](project_images/summary/height_Japan.jpg?raw=true "Example Image")

####Cinder - Frontend

We build the frontend with Cinder, which is a library build on top of c++. It’s a very useful library for creative coding and allow us to quickly create our prototypes and testings. The frontend update the visuals based on the geolocation and weather data. These data are send from the Node.js server using OSC.

####HTML5/Javascript - The controller
The controller is built with HTML5 and javascript. Based on a google map javascript api, we get the geolocation data from where user select and send it back to Node.js server using WebSocket. We also put another canvas overlay on top of the google map showing the position of the giant and also the camera.

####The structure diagram :

![Example Image](project_images/summary/Structure.jpg?raw=true "Example Image")

####The technologies used for each part in this project :

![Example Image](project_images/summary/Technologies.jpg?raw=true "Example Image")
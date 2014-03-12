#Communication - Camera movement


In order to send the data from the controller to the frontend, we need to use couple of different technologies. The controller is build the HTML/Javascript. To communicate with Node.js we chose to use WebSocket. It’s really easy to setup the connection with [socket.io](http://socket.io/).

Once the data got to Node.js server, it gets converted to OSC and then dispatched right away to frontend. 

In the frontend our camera sits on a circular track, always facing center. So we can use this angle to calculate the new position of our camera.

Here is a short video recording :

http://www.youtube.com/watch?v=IEgLbxkxV6I


Prototype [Link](http://www.bongiovi.tw/kuafu/prototypes/03/) - Click to chose 2 places and reveal the terrain in this region.

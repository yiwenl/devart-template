# Motion Capture

As the project progresses, we're looking more and more beyond the technology into the artistry and feel of the piece - how can we make this experience beautiful? And also how can we make it 'human'?

Again taking references from games such as Journey, we began thinking about the movement of the Giant, and the practicalities of how we would control the model for both the interactive and motion sequences.

## Ni Mate

A friend of ours pointed out this piece of software and plugin for Cinema 4D called [NI Mate]("www.ni-mate.com/use/cinema4d/", "NI Mate"), which takes data from the Kinect camera and transmits it via OSC to Cinema 4D to control a character. 

We thought this could be a great technique to try out, seeing if we could somehow record the data from a live actor, convert it into a motion path for the character's various actions (walk, swim, drink etc), and use it in the experience.

First off - we needed a model! So we enlisted the help of Liam Viney to procude the basic mesh from Bert's drawings, then imported it into Cinema 4D to experiment with 'rigging' it - basically giving the model a virtual sketeton where the interactions of the muscles, joints etc are modelled realistically.

Because Cinema 4D has a really good plugin architecture (based on Python), we bet on us being able to use it as a tool to view, record and edit the movement data before exporting it in a format that can be used to drive the model in Cinder.

This video shows the model rigged and ready to go in Cinema 4D (after much watching of tutorial videos!)

https://www.youtube.com/watch?v=SxgplYYbB7M

## Bring in the actors

With the model rigged, we then organised a session with two physical actors, [Alex Luttley]("https://www.facebook.com/alexander.luttley.9", "Alex Luttley") and [Nanna Gunnars]("https://www.facebook.com/nannagunnars", "Nanna Gunnars") to come and perform in front of a Kinect camera for us and see what we could record.

The results are here:

https://www.youtube.com/watch?v=U7Ls42kD2Iw&feature=youtu.be

We ended up focussing mainly on recording the raw footage from the Kinect, whilst viewing how the movement was translated into the wireframe model in Cinema 4D (we unfortunately didn't get the Kuafu model connected up in time).

This workflow worked out pretty well, as we were able to simply hit 'record', and then focus on the actual performance, rather than the technology and transference to the model.

We experiemented with different poses and walking styles for the Giant, eventually settling on the slightly hunched, slow but determined one shown by Alex in this video.

The next stage is to integrate the captured data into the rigged model, and build all the animation cycles we need for the installation.
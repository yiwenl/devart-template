#Sound Effect Approach

As so much of this project is incorporating generative, ‘code-driven’ art and graphics,  we felt that it would be good to try to take a procedural approach to the audio too.

Procedural audio involves (mainly) creating physical models of the systems or objects that make a particular sound in code, as opposed to sample-based audio which takes pre-recorded sound files and plays them back, with some optional manipulation.

![Karplus-Strong-diagram](project_images/karplus-strong.png?raw=true "Karplus-Strong diagram")

*Karplus-strong model for a plucked string instrument*

The advantage to procedural audio is that it can be extremely expressive, as potentially every parameter in the system is open to manipulation. 

For example a model of footsteps can include fine control over the roughness, wetness or force of each step individually, giving a variety of sound that would be prohibitive to achieve with samples (you’d need to have a sample for each type of surface).

The main drawback is that some sounds can be extremely difficult to synthesise satisfactorily, to fool the listener into thinking that it is ‘real’. 

Luckily, in this case we are not trying to be ‘realistic’ - we need only be believable, which is an important distinction.



Inspiration and reassurance for the effectiveness of this approach came from two sources; the first is Andy Farnell’s excellent [book]('http://www.amazon.co.uk/Designing-Sound-Andy-Farnell/dp/0262014416', 'Designing Sound') and accompanying [website]('http://aspress.co.uk/sd/', 'Designing Sound'), ‘Designing Sound’, the second was a talk by Christian Heinrichs from [Queen Mary University]('http://www.eecs.qmul.ac.uk/~andrewm/people.html', 'Queen Mary University') on his ‘squeaky door’ algorithm at a London Procedural Audio meetup.

![Footstep-patch](project_images/footstep-patch.png?raw=true "Footstep-patch")

*Pure Data patch for a simple footstep, showing the different ‘heel’ and ‘ball’ components of the foot impact, taken from Andy Farnell’s [site]('http://obiwannabe.co.uk/tutorials/html/tutorial_footsteps.html', 'Designing Sound')*


This resulted in a lengthy discussion over the use of procedural audio in the film and games industries (including the interesting remark that apparently the wind in Quentin Tarantino’s Inglorious Basterds was done entirely procedurally: [link]('http://designingsound.org/2010/02/the-sound-of-inglourious-basterds/', 'Sound of Inglorious Basterds')

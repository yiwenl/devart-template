
var io       	= require('socket.io'),
	express  	= require('express');
var osc 	= require("osc-min");
var dgram 	= require("dgram");
var udp 	= dgram.createSocket("udp4");


var MountainModel = require('./model.js');
var model = MountainModel.create();
console.log( model.getMountains(0, 1) );

/* SERVER VARIABLES */
var port = 8158;
var connected = false;
var sockets = {};


/* SETUP SERVER */
var app = express(),
	server = require('http').createServer(app),
	io = io.listen(server);

server.listen(port);
var outport = 8159;
var count = 0;


/* GLOBAL VARIABLES */
var mountains = [{"x":38.714733542319756,"y":-27.89968652037618,"size":24,"scale":1},{"x":19.27899686520376,"y":-4.702194357366771,"size":24.5,"scale":1},{"x":1.7241379310344769,"y":2.1943573667711576,"size":24.5,"scale":1},{"x":15.203761755485893,"y":-5.01567398119122,"size":45,"scale":1},{"x":12.38244514106583,"y":4.702194357366771,"size":44.5,"scale":1},{"x":7.993730407523508,"y":7.210031347962385,"size":23,"scale":1},{"x":35.893416927899686,"y":-28.52664576802508,"size":26.5,"scale":1},{"x":25.862068965517246,"y":-16.300940438871475,"size":26.5,"scale":1},{"x":13.009404388714735,"y":2.8213166144200628,"size":52.5,"scale":1},{"x":-38.08777429467085,"y":18.18181818181818,"size":23.5,"scale":1},{"x":17.0846394984326,"y":-5.01567398119122,"size":30.5,"scale":1},{"x":-2.6645768025078382,"y":10.658307210031346,"size":24.5,"scale":1},{"x":14.263322884012531,"y":5.956112852664575,"size":27.5,"scale":1},{"x":9.874608150470216,"y":-6.269592476489027,"size":34.5,"scale":1},{"x":5.172413793103445,"y":1.2539184952978033,"size":29,"scale":1},{"x":-37.1473354231975,"y":19.74921630094044,"size":25,"scale":1},{"x":14.263322884012531,"y":-15.673981191222573,"size":24.5,"scale":1},{"x":-39.65517241379311,"y":26.01880877742947,"size":23.5,"scale":1},{"x":12.38244514106583,"y":-6.58307210031348,"size":39,"scale":1},{"x":-22.41379310344828,"y":16.927899686520377,"size":26,"scale":1},{"x":14.263322884012531,"y":-3.761755485893417,"size":41.5,"scale":1},{"x":-24.29467084639499,"y":6.269592476489031,"size":27,"scale":1},{"x":-18.965517241379313,"y":15.047021943573668,"size":28,"scale":1},{"x":38.40125391849529,"y":-24.13793103448276,"size":22.5,"scale":1},{"x":-44.67084639498433,"y":19.122257053291534,"size":23,"scale":1},{"x":22.413793103448278,"y":-12.85266457680251,"size":27.5,"scale":1},{"x":27.11598746081504,"y":-11.285266457680251,"size":30.5,"scale":1},{"x":2.351097178683382,"y":-1.2539184952978033,"size":39,"scale":1},{"x":18.65203761755486,"y":5.6426332288401255,"size":28.5,"scale":1},{"x":-25.548589341692796,"y":16.614420062695928,"size":26.5,"scale":1},{"x":-8.307210031347964,"y":8.463949843260188,"size":23,"scale":1},{"x":17.7115987460815,"y":-6.269592476489027,"size":31,"scale":1},{"x":-17.084639498432608,"y":16.30094043887147,"size":27.5,"scale":1},{"x":20.53291536050157,"y":-11.285266457680251,"size":27.5,"scale":1},{"x":-2.03761755485894,"y":8.15047021943574,"size":23,"scale":1},{"x":6.739811912225704,"y":-0.31347962382444905,"size":33,"scale":1},{"x":-27.115987460815052,"y":17.241379310344826,"size":24,"scale":1},{"x":-29.623824451410663,"y":11.285266457680251,"size":25,"scale":1},{"x":27.742946708463954,"y":-7.523510971786834,"size":24.5,"scale":1},{"x":16.771159874608152,"y":1.2539184952978033,"size":36.5,"scale":1},{"x":30.87774294670846,"y":-25.705329153605017,"size":28.5,"scale":1},{"x":36.520376175548584,"y":-30.40752351097179,"size":22.5,"scale":1},{"x":35.26645768025079,"y":-22.257053291536053,"size":25,"scale":1},{"x":11.755485893416925,"y":1.2539184952978033,"size":29,"scale":1},{"x":10.188087774294665,"y":1.2539184952978033,"size":47.5,"scale":1},{"x":23.667711598746074,"y":-6.896551724137932,"size":30.5,"scale":1},{"x":23.981191222570537,"y":-15.987460815047022,"size":24,"scale":1},{"x":-3.6050156739811925,"y":16.30094043887147,"size":25,"scale":1},{"x":15.517241379310342,"y":-7.836990595611287,"size":22.5,"scale":1},{"x":7.053291536050153,"y":-2.1943573667711576,"size":29,"scale":1},{"x":28.056426332288403,"y":-31.347962382445143,"size":25,"scale":1},{"x":-35.89341692789969,"y":19.122257053291534,"size":27.5,"scale":1},{"x":25.235109717868333,"y":-13.479623824451412,"size":25.5,"scale":1},{"x":9.247648902821311,"y":5.956112852664575,"size":27,"scale":1},{"x":8.934169278996862,"y":3.448275862068968,"size":33,"scale":1},{"x":31.50470219435737,"y":-7.836990595611287,"size":22.5,"scale":1},{"x":29.623824451410663,"y":-21.630094043887148,"size":25,"scale":1},{"x":-0.4702194357366807,"y":6.269592476489031,"size":24.5,"scale":1},{"x":-36.52037617554859,"y":21.943573667711597,"size":24,"scale":1},{"x":-23.667711598746088,"y":19.74921630094044,"size":23,"scale":1},{"x":23.981191222570537,"y":-9.717868338557995,"size":30.5,"scale":1},{"x":-39.028213166144205,"y":24.13793103448276,"size":28,"scale":1},{"x":-20.532915360501573,"y":14.733542319749219,"size":25,"scale":1},{"x":9.247648902821311,"y":-1.2539184952978033,"size":35,"scale":1},{"x":-13.63636363636364,"y":5.6426332288401255,"size":28.5,"scale":1},{"x":-28.36990595611286,"y":9.404388714733543,"size":24.5,"scale":1},{"x":-5.485893416927901,"y":4.388714733542322,"size":23,"scale":1},{"x":33.07210031347963,"y":-34.48275862068966,"size":23,"scale":1},{"x":-39.96865203761756,"y":31.661442006269596,"size":24,"scale":1},{"x":18.02507836990595,"y":-1.2539184952978033,"size":26,"scale":1},{"x":13.94984326018809,"y":0,"size":49.5,"scale":1},{"x":-48.746081504702204,"y":-36.36363636363637,"size":28.5,"scale":1},{"x":-32.445141065830725,"y":12.225705329153605,"size":27.5,"scale":1},{"x":-38.4012539184953,"y":26.959247648902817,"size":28,"scale":1},{"x":23.040752351097176,"y":-14.420062695924766,"size":23,"scale":1},{"x":27.742946708463954,"y":-12.85266457680251,"size":26.5,"scale":1},{"x":16.457680250783703,"y":-0.6269592476489052,"size":28.5,"scale":1},{"x":28.99686520376175,"y":-20.376175548589345,"size":28,"scale":1},{"x":-47.49216300940439,"y":19.74921630094044,"size":23,"scale":1},{"x":-14.263322884012545,"y":3.761755485893417,"size":24,"scale":1},{"x":-14.576802507836994,"y":15.047021943573668,"size":30.5,"scale":1},{"x":-0.15673981191223163,"y":7.836990595611283,"size":23,"scale":1},{"x":38.087774294670844,"y":-26.33228840125392,"size":25,"scale":1},{"x":31.50470219435737,"y":-20.376175548589345,"size":23,"scale":1},{"x":17.39811912225705,"y":3.761755485893417,"size":33,"scale":1},{"x":3.6050156739811854,"y":0.9404388714733543,"size":25,"scale":1},{"x":-41.53605015673982,"y":16.30094043887147,"size":24,"scale":1},{"x":25.548589341692782,"y":-7.523510971786834,"size":26,"scale":1},{"x":18.33855799373041,"y":0.31347962382444905,"size":26,"scale":1},{"x":18.33855799373041,"y":-9.717868338557995,"size":24.5,"scale":1},{"x":-37.7742946708464,"y":28.526645768025077,"size":23.5,"scale":1},{"x":21.159874608150467,"y":-6.896551724137932,"size":38.5,"scale":1},{"x":26.489028213166144,"y":-33.228840125391855,"size":24.5,"scale":1},{"x":-22.41379310344828,"y":9.404388714733543,"size":25.5,"scale":1},{"x":13.009404388714735,"y":-1.8808777429467085,"size":30,"scale":1},{"x":-37.7742946708464,"y":21.003134796238243,"size":26.5,"scale":1},{"x":35.893416927899686,"y":-24.45141065830721,"size":26.5,"scale":1},{"x":27.11598746081504,"y":-22.257053291536053,"size":22.5,"scale":1},{"x":-2.351097178683389,"y":13.479623824451409,"size":28.5,"scale":1},{"x":31.81818181818182,"y":-31.974921630094045,"size":24.5,"scale":1},{"x":-18.965517241379313,"y":8.15047021943574,"size":23,"scale":1},{"x":25.548589341692782,"y":-9.090909090909093,"size":27.5,"scale":1},{"x":22.413793103448278,"y":-9.090909090909093,"size":27,"scale":1},{"x":-31.191222570532922,"y":9.404388714733543,"size":23,"scale":1},{"x":10.81504702194357,"y":2.5078369905956137,"size":25,"scale":1},{"x":30.87774294670846,"y":-10.031347962382448,"size":27,"scale":1},{"x":0.7836990595611226,"y":3.448275862068968,"size":27,"scale":1},{"x":28.056426332288403,"y":-28.52664576802508,"size":22.5,"scale":1},{"x":-14.890282131661444,"y":5.01567398119122,"size":29.5,"scale":1},{"x":-39.34169278996866,"y":28.840125391849526,"size":35.5,"scale":1},{"x":8.307210031347957,"y":-4.075235109717866,"size":45,"scale":1},{"x":-4.858934169279003,"y":12.539184952978054,"size":25.5,"scale":1},{"x":-35.579937304075244,"y":26.959247648902817,"size":23,"scale":1},{"x":4.54545454545454,"y":-2.5078369905956137,"size":34.5,"scale":1},{"x":-26.175548589341698,"y":18.808777429467085,"size":23.5,"scale":1},{"x":14.890282131661444,"y":-2.1943573667711576,"size":28,"scale":1},{"x":30.25078369905956,"y":-5.956112852664578,"size":25.5,"scale":1},{"x":31.50470219435737,"y":-22.257053291536053,"size":29.5,"scale":1},{"x":29.623824451410663,"y":-31.974921630094045,"size":22.5,"scale":1},{"x":29.93730407523511,"y":-18.495297805642636,"size":24,"scale":1},{"x":-26.48902821316615,"y":5.6426332288401255,"size":22.5,"scale":1},{"x":-12.695924764890286,"y":3.448275862068968,"size":26,"scale":1},{"x":-20.532915360501573,"y":4.388714733542322,"size":29,"scale":1},{"x":-7.680250783699066,"y":14.420062695924763,"size":23,"scale":1},{"x":39.96865203761755,"y":-25.391849529780565,"size":24,"scale":1},{"x":15.83072100313479,"y":-3.448275862068968,"size":31.5,"scale":1},{"x":-20.532915360501573,"y":8.15047021943574,"size":23,"scale":1},{"x":32.75862068965517,"y":-29.153605015673982,"size":25,"scale":1},{"x":-7.0532915360501605,"y":5.01567398119122,"size":22.5,"scale":1},{"x":31.81818181818182,"y":-27.89968652037618,"size":35.5,"scale":1},{"x":35.26645768025079,"y":-26.64576802507837,"size":25,"scale":1},{"x":-34.012539184952985,"y":10.971786833855802,"size":25,"scale":1},{"x":27.11598746081504,"y":-9.717868338557995,"size":27,"scale":1},{"x":34.639498432601876,"y":-25.391849529780565,"size":22.5,"scale":1},{"x":-5.172413793103452,"y":6.269592476489031,"size":25,"scale":1},{"x":25.548589341692782,"y":-18.181818181818183,"size":31.5,"scale":1},{"x":15.83072100313479,"y":3.448275862068968,"size":32,"scale":1},{"x":-17.711598746081506,"y":5.01567398119122,"size":28.5,"scale":1},{"x":-38.714733542319756,"y":30.407523510971785,"size":22.5,"scale":1},{"x":30.87774294670846,"y":-12.225705329153605,"size":26,"scale":1},{"x":-5.799373040752357,"y":15.360501567398117,"size":22.5,"scale":1},{"x":19.905956112852657,"y":-0.31347962382444905,"size":24,"scale":1},{"x":2.664576802507831,"y":-2.8213166144200628,"size":32.5,"scale":1},{"x":17.39811912225705,"y":8.15047021943574,"size":23.5,"scale":1},{"x":-42.47648902821317,"y":27.89968652037618,"size":24,"scale":1},{"x":-27.742946708463954,"y":18.808777429467085,"size":22.5,"scale":1},{"x":-0.15673981191223163,"y":1.5673981191222595,"size":27,"scale":1},{"x":-11.755485893416932,"y":5.6426332288401255,"size":26,"scale":1},{"x":-0.4702194357366807,"y":10.344827586206897,"size":23.5,"scale":1},{"x":29.623824451410663,"y":-10.65830721003135,"size":23.5,"scale":1}];
var mountainsStream = [];


for(i=0; i<mountains.length; i++) {
	var m = mountains[i];
	mountainsStream.push(m.x, m.y, m.size);
}
var lat = 0;
var lng = 0;



sendHeartbeat = function() {
	// console.log( allMountains.length );

	return;
  var buf;
  buf = osc.toBuffer({
    address: "/heartbeat",
    args: [
      12, "sttttring", count++
    ]
  });
  return udp.send(buf, 0, buf.length, outport, "localhost");
};

setInterval(sendHeartbeat, 2000);


var serverOsc = dgram.createSocket("udp4");
var messageToSend = new Buffer("A message to send");

serverOsc.on("message", function (msg, rinfo) {
	var objMsg = osc.fromBuffer(msg).elements[0];

	switch(objMsg.address) {
		case "/cinder/osc/init" :
		console.log( "Frontend connected : ", objMsg.args );
		sendMountains();
		break;
	}
});


sendCameraAngle = function(angle) {
	var buf;
	buf = osc.toBuffer({
		address:"/onCameraAngle",
		args: [angle]
	});
	udp.send(buf, 0, buf.length, outport, "localhost");
}

sendMountains = function() {
	console.log( "SEND OUT MOUNTAINS DATA" );
	var buf;
	buf = osc.toBuffer({
		address:"/onMountains",
		args: mountainsStream
	});
	udp.send(buf, 0, buf.length, outport, "localhost");
}

serverOsc.on("listening", function () {
  var address = serverOsc.address();
  console.log("server listening " +
      address.address + ":" + address.port);
});

serverOsc.bind(8160);



io.sockets.on('connection', function(socket) {
	var timestamp = ''+new Date().getTime()+'';
	var uid = timestamp.slice(6, timestamp.length);

	if(sockets == null) sockets = {};

	sockets[uid] = socket;
	sockets[uid]['uid'] = socket.uid = uid;
	console.log( "SOCKET CREATED : ", uid );

	function error() {
		socket.emit('error');
	};

	// function hasSockets() {
	// 	if(!players) return false;
	// 	return true;
	// };
	function hasSocket(uid) {
		if(!sockets) return false;
		if(!socket.uid) return false;
		if(!sockets[uid]) return false;
		return true;
	};
	function isConnected(id) {
		return socket.manager.connected[id];
	}
	function isValidSocket() {
		if(!hasSocket(socket.uid))return false;
		if(!isConnected(socket.id))return false;
		return true;
	};

	socket.on('error', function(err) {
		console.log( "There is an error" );
		try {
			console.log( err.stack );
		} catch ( e ) {}
		
	});

	socket.on('close', function () {
		console.log( 'Close' );
		sockets.splice(sockets.indexOf(socket), 1);
    });


    socket.on('end', function () {
		console.log( "End" );
		sockets.splice(sockets.indexOf(socket), 1);
    });

    socket.on('exit', function(){
    	if(isValidSocket()){
			socket.disconnect();
			delete sockets[socket.uid];
		}
    });
	socket.on('disconnect', function () {

		if(isValidSocket()){
			error();
			return;
		}
		delete sockets[socket.uid];
		console.log( "DISCONNECTED : ", sockets[socket.uid] );
		socket.uid = null;
	});

	/*
	 *	say hello to a new client, so they know we're ready
	 */ 

	console.log( "Say hello to client" );
	socket.emit('hello', {id: uid});

	socket.on('helloBack', function(data) {	console.log("WE HAVE A NEW FRIEND", data); });


	socket.on('mousemove', function(data) {
		console.log("Mouse Move : ", data);

		var buf;
		buf = osc.toBuffer({
			address: "/mousemove",
			args: [
			  data.x, data.y
			]
		});
		return udp.send(buf, 0, buf.length, outport, "localhost");
	});



	socket.on("setLatLng", function(data) {
		console.log( "On Latlng : ", data );
	});
	socket.on("setCameraAngle", function(data) {
		console.log( "On Camera Angle : ", data.angle );
		sendCameraAngle(data.angle);
	});

});


/* disconnect socket.io clients cleanly */
process.on('SIGINT', function() {
    global.log.error("app: gracefully shutting down from SIGINT (Ctrl+C)");

	var clients = io.sockets.clients();

	for (i in clients) {
		clients[i].disconnect();			
	}

});

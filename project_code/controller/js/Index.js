(function() {
	KuafuController = function() {
		this.mouse = {x:0, y:0};
		this.angle = 0;
		this.newAngle = 0;
		this.startAngle = 0;
	}

	var p = KuafuController.prototype;

	p.init = function() {
		this.canvas = document.body.querySelector("#overlayCanvas");
		this.canvas.width = window.innerWidth;
		this.canvas.height = window.innerHeight;
		this.ctx	= this.canvas.getContext("2d");


		scheduler.addEF(this, this.render, []);

		var that = this;

		if(typeof io != 'undefined') {
			this._socket = io.connect('http://192.168.1.70:8158');

			this._socket.on('hello', function(data) {
				console.log("hello from the Controller :: data.id : ", data.id);
				that._isConnected = true;
				that.addEvents();
				that._socket.emit("helloBack", {ID:data.id});
				// this.emit('hello', {id : 1});
			});
		}


		document.body.addEventListener("mousedown", function(e) {
			that.mouse.x = e.clientX;
			that.mouse.y = e.clientY;
		});


		// document.body.addEventListener("touchend", function(e) {
		// 	e.preventDefault();
		// 	debug("2 finger touch end");
		// }


		document.body.addEventListener("touchstart", function(e) {
			e.preventDefault();
			if(e.touches.length > 1) {
				var f0 = {x:e.touches[0].pageX, y:e.touches[0].pageY};
				var f1 = {x:e.touches[1].pageX, y:e.touches[1].pageY};
				that.angle = that.newAngle;
				that.startAngle = Math.atan2(f1.y-f0.y, f1.x-f0.x);
			}
		});


		document.body.addEventListener("touchmove", function(e) {
			e.preventDefault();
			if(e.touches.length > 1) {
				var f0 = {x:e.touches[0].pageX, y:e.touches[0].pageY};
				var f1 = {x:e.touches[1].pageX, y:e.touches[1].pageY};

				// debug(f0.pageX + "/" + f0.pageY);
				drawCircle(that.ctx, f0, "#FAA", 30);
				drawCircle(that.ctx, f1, "#AAF", 30);

				var angle = Math.atan2(f1.y-f0.y, f1.x-f0.x);
				that.newAngle = that.angle + (angle - that.startAngle);
				debug(that.newAngle * 180 / Math.PI);
				that._socket.emit("setCameraAngle", {angle:that.newAngle});
			}
		});

	};



	p.addEvents = function() {
		
	};


	p.setLatLng = function(lat, lng) {
		this._socket.emit("setLatLng", {lat:lat, lng:lng});
	};



	p.render = function() {
		this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
		// drawCircle(this.ctx, this.mouse, "#f60", 10);
		this.drawCamera();
	};

	p.drawCamera = function() {
		
	};


	var debug = function(toLog) {
		document.body.querySelector("#debugField").innerHTML = toLog;
	}

	var drawCircle = function(ctx, pos, color, size) {
		ctx.fillStyle = color;
		ctx.beginPath();
		ctx.arc(pos.x, pos.y, size, 0, Math.PI*2, true); 
		ctx.closePath();
		ctx.fill();
	}
})();
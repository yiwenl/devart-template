(function() {
	KuafuController = function() {
		this.mouse = {x:0, y:0};
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
			this._socket = io.connect('http://localhost:8158');

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


		document.body.addEventListener("touchstart", function(e) {
			if(e.touches.length > 1) {
				console.log( "2 finger touch" );
			}
		});


		document.body.addEventListener("touchmove", function(e) {
			if(e.touches.length > 1) {
				console.log( "2 finger touch" );
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
		var ctx = this.ctx;
		ctx.fillStyle = "#f60";
		ctx.beginPath();
		ctx.arc(this.mouse.x, this.mouse.y, 10, 0, Math.PI*2, true); 
		ctx.closePath();
		ctx.fill();

		this.drawCamera();
	};



	p.drawCamera = function() {
		
	};
})();
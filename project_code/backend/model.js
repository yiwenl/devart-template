var MountainsData 	= require('./mountains.js');
var EventEmitter 	= require( "events" ).EventEmitter;
var sampleRange 	= 20;

var MountainModel = function Model() {
	this.data = MountainsData.data;
	console.log( "DATA : " );
	console.log( this.data.length );
}

var p = MountainModel.prototype = new EventEmitter();


p.getMountains = function(lat, lng) {
	return [0, 1, 5, 8];
};


exports.create = function() {
	return new MountainModel();
};

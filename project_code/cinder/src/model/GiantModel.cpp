//
//  GiantModel.cpp
//  Kuafu
//
//  Created by Yiwen on 25/02/2014.
//
//

#include "GiantModel.h"
#include "cinder/System.h"

#define PORT_LISTEN     8159
#define PORT_SEND       8160

void GiantModel::init(SceneKuafu* scene) {
    string host = System::getIpAddress();
	if( host.rfind( '.' ) != string::npos )
		host.replace( host.rfind( '.' ) + 1, 3, "255" );
    cout << "Setup Sender at" << host << ", " << PORT_SEND << endl;
    cout << "Setup Listener at port : " << PORT_SEND << endl;
	_sender.setup( host, PORT_SEND, true );
    
    _listener.setup( PORT_LISTEN );
    
    
    osc::Message message;
    message.addStringArg("Hello : ");
	message.setAddress("/cinder/osc/init");
	message.setRemoteEndpoint(host, PORT_SEND);
	_sender.sendMessage(message);
    
    _scene = scene;
}


void GiantModel::update() {
    while( _listener.hasWaitingMessages() ) {
		osc::Message message;
		_listener.getNextMessage( &message );
		
		console() << "New message received" << std::endl;
		console() << "Address: " << message.getAddress() << std::endl;
		console() << "Num Arg: " << message.getNumArgs() << std::endl;
        
        string address = message.getAddress();
        if(address == "/onMountains") {
            _onGetMountains(message);
        }
    }
}


void GiantModel::_onGetMountains(osc::Message message) {
    for (int i = 0; i < message.getNumArgs(); i+=3) {
        Mountain* m = new Mountain(message.getArgAsFloat(i), message.getArgAsFloat(i+1), message.getArgAsFloat(i+2) );
        _mountains.push_back(m);
    }
    
    _scene->generateMountains();
}


vector<Mountain*> GiantModel::getMountains() { return _mountains;    }

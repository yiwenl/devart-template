//
//  GiantModel.h
//  Kuafu
//
//  Created by Yiwen on 25/02/2014.
//
//

#ifndef __Kuafu__GiantModel__
#define __Kuafu__GiantModel__

#include <iostream>
#include "OscListener.h"
#include "OscSender.h"
#include "Mountain.h"
#include "SceneKuafu.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GiantModel {
    public :
    static GiantModel& getInstance() {
        static GiantModel settings;
        return settings;
    };
    
    
    void                        init(SceneKuafu*);
    void                        update();
    vector<Mountain*>           getMountains();
    
    private :
    GiantModel() {};

    osc::Sender                 _sender;
    osc::Listener               _listener;
    
    void                        _onGetMountains(osc::Message message);
    vector<Mountain*>           _mountains;
    SceneKuafu*                 _scene;
};

#endif /* defined(__Kuafu__GiantModel__) */

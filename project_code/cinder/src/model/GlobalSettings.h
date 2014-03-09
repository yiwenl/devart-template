//
//  GlobalSettings.h
//  Kuafu
//
//  Created by Yiwen on 08/03/2014.
//
//

#ifndef __Kuafu__GlobalSettings__
#define __Kuafu__GlobalSettings__

#include <iostream>

class GlobalSettings {
    public :
    static GlobalSettings& getInstance() {
        static GlobalSettings settings;
        return settings;
    };
    
    
    float       contrast =                  .85f;
    float       brightness =                1.27f;
    float       saturation =                .1f;
    
  
    private :
    GlobalSettings() {};
};

#endif /* defined(__Kuafu__GlobalSettings__) */

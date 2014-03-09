//
//  Mountain.h
//  Kuafu
//
//  Created by Yiwen on 25/02/2014.
//
//

#ifndef __Kuafu__Mountain__
#define __Kuafu__Mountain__

#include <iostream>
using namespace std;

class Mountain {
    public :
    Mountain() {};
    Mountain(float, float, float);
    
    
    float           x;
    float           y;
    float           height;
};


std::ostream& operator<<(std::ostream &strm, const Mountain &m) {
    return strm << "Mountain(" << m.x << ", " << m.y << " : " << m.height << ")";
}
    
#endif /* defined(__Kuafu__Mountain__) */

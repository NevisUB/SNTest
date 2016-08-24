#ifndef ALIGN_H
#define ALIGN_H

#include <iostream>
#include "DataFormat/storage_manager.h"

namespace larlite {

  class Align{

  public:
    
    Align(){}

    ~Align(){}

    bool align_events(storage_manager* sm1, storage_manager* sm2, storage_manager* sm3);
    
  };
}
#endif


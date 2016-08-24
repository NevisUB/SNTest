#ifndef LARLITE_ROLODEX_CXX
#define LARLITE_ROLODEX_CXX

#include "Rolodex.h"

namespace larlite {

  bool Rolodex::initialize() {
    return true;
  }
  
  bool Rolodex::analyze(storage_manager* storage) {
    _event_ctr++;
    
    //make a copy out of the file, when storage comes back around the pointer will change
    event_tpcfifo* event_fifo = storage->get_data<event_tpcfifo>("tpcfifo");
    _fifoevents.emplace_front(*event_fifo);
    
    //get the output
    event_tpcdetwaveform* event_tpcdet = storage->get_data<event_tpcdetwaveform>(_producer);
    
    //first event is just setup, we always lag 1 event behind

    if (_event_ctr == 0) return true;

    *(event_tpcdet) = *(_stitcher->stitch(_fifoevents[0],_fifoevents[1]));

    _fifoevents.pop_back();

    return true;
  }

  bool Rolodex::finalize() {
    return true;
  }

}
#endif

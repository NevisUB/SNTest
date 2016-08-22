#ifndef STITCHALGO_CXX
#define STITCHALGO_CXX

#include "StitchAlgo.h"

namespace larlite {

  event_tpcdetwaveform* StitchAlgo::stitch(const event_tpcfifo& ev_tpcfifo_before,
					   const event_tpcfifo& ev_tpcfifo) {
    _reset_event();

    const tpcfifo* before = nullptr;

    for (const auto& fifo : ev_tpcfifo) {

      before=nullptr;
      
      for (auto& fifo_before : ev_tpcfifo_before) {
	if ( fifo.channel_number() != fifo_before.channel_number() ) continue;
	before = &fifo_before;
	std::cout << "\t>> Match found!\n";
	break;
      }

      if (!before) std::cout << "No match found!\n";
      
    }

    return &_event_waveforms;
  }
  

  void StitchAlgo::_reset_event() {
    _event_waveforms.clear();
    _event_waveforms.reserve(64); // give me atleast 64 waveforms...
    
  }
  
}


#endif

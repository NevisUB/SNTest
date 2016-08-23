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
	break;
      }

      if (!before) void;

      tpcdetwaveform tpcwf;
      
      if( _convert_fifo(fifo,*before,tpcwf) )
	 _event_waveforms.emplace_back(std::move(tpcwf));
    }

    _event_waveforms.SetEvent(ev_tpcfifo.event_number());
    _event_waveforms.SetFrame(ev_tpcfifo.event_frame_number());

    return &_event_waveforms;
  }
  
  bool StitchAlgo::_convert_fifo(const tpcfifo& fifo,
				 const tpcfifo& before,
				 tpcdetwaveform& tpcwf) {

    if (!fifo.size()) false;
    
    tpcwf.resize(fifo.size());

    std::memcpy(tpcwf.data(),fifo.data(),sizeof(unsigned short)*fifo.size());

    tpcwf.SetChannelNumber(fifo.channel_number());
    tpcwf.SetTimeStamp(fifo.readout_sample_number_RAW());
      
    return true;
  }
  
  

  void StitchAlgo::_reset_event() {
    _event_waveforms.clear();
    _event_waveforms.reserve(64); // give me atleast 64 waveforms...
  }
  
}


#endif

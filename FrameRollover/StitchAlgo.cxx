#ifndef STITCHALGO_CXX
#define STITCHALGO_CXX

#include "StitchAlgo.h"

namespace larlite {

  event_tpcdetwaveform* StitchAlgo::stitch(const event_tpcfifo& ev_tpcfifo_before,
					   const event_tpcfifo& ev_tpcfifo) {
    _reset_event();

    const tpcfifo* before = nullptr;

    short prev_ch = -1;
    
    for (const auto& fifo : ev_tpcfifo) {

      if ( fifo.channel_number() != prev_ch )
	{ _offset = -1; _prev_t = -1; }

      prev_ch = fifo.channel_number();
	
      before=nullptr;
      
      for (auto& fifo_before : ev_tpcfifo_before) {

	//we want the last fifo from the previous __event__
	if ( fifo.channel_number() != fifo_before.channel_number() ) 
	  before = &fifo_before;
      }

      //no fifo from before? what should I do?
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

    if (!fifo.size()) return false;
    
    tpcwf.resize(fifo.size());

    std::memcpy(tpcwf.data(),fifo.data(),sizeof(unsigned short)*fifo.size());

    tpcwf.SetChannelNumber(fifo.channel_number());


    // Timestamp will be offset by the number of presamples. Also, when the trigger data
    // comes in, 4 frames get squashed into 1 for snova. But, each fifo only gets ID'ed by the first
    // frame number. So it happens that samples are going to overlap how to tell the apart? oh boy


    auto t = fifo.readout_sample_number_RAW();

    if ( t < _prev_t ) _offset++;

    tpcwf.SetTimeStamp(t + _offset * _t_offset - _presamples);
    tpcwf.SetFrame(fifo.readout_frame_number());

    _prev_t = t;
    return true;
  }
  
  

  void StitchAlgo::_reset_event() {
    _event_waveforms.clear();
    _event_waveforms.reserve(64); // give me atleast 64 waveforms...
  }
  
}


#endif

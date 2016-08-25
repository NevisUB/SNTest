#ifndef STITCHALGO_H
#define STITCHALGO_H

#include <iostream>

#include "DataFormat/tpcfifo.h"
#include "DataFormat/tpcdetwaveform.h"

namespace larlite {

  class StitchAlgo{

  public:

    /// Default constructor
    StitchAlgo() : _presamples(0), _t_offset(0xfff), _offset(0), _prev_t(-1) {}

    /// Default destructor
    ~StitchAlgo(){}

    event_tpcdetwaveform* stitch(const event_tpcfifo& tpcfifo_before,
				 const event_tpcfifo& tpcfifo);

    void SetPreSamples(short p) { _presamples = p; }
    
  private:
    
    event_tpcdetwaveform _event_waveforms;

    bool _convert_fifo(const tpcfifo& fifo,
		       const tpcfifo& before,
		       tpcdetwaveform& tpcwf);

    void _reset_event();

    short _presamples;

    unsigned short _t_offset;
    short _offset;
    short _prev_t;
  };
}

#endif
/** @} */ // end of doxygen group 


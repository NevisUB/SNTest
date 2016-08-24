#ifndef STITCHALGO_H
#define STITCHALGO_H

#include <iostream>

#include "DataFormat/tpcfifo.h"
#include "DataFormat/tpcdetwaveform.h"

namespace larlite {

  class StitchAlgo{

  public:

    /// Default constructor
    StitchAlgo() : _presamples(0) {}

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
    
  };
}

#endif
/** @} */ // end of doxygen group 


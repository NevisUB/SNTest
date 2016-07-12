#ifndef LARLITE_DUMP_CXX
#define LARLITE_DUMP_CXX

#include "Dump.h"
#include "DataFormat/tpcfifo.h"

namespace larlite {

  bool Dump::initialize() {

    _ofile.open("loser_decoded.txt");
    
    return true;
  }
  
  bool Dump::analyze(storage_manager* storage) {

    auto event_wf = (event_tpcfifo*) storage->get_data<event_tpcfifo>("tpcfifo");
    
    std::cout << "size of event_wf is " << event_wf->size() << "\n";
    std::cout << "\nevent is " << event_wf->event_number() << " ";
    std::cout << "\nevent frame is " << event_wf->event_frame_number() << " ";

    _ofile << event_wf->event_number() << ",";
    
    for ( const auto& f : *event_wf ) {
      _ofile << f.channel_number() << ",";
      std::cout << "\nchannel is " << f.channel_number();
      _ofile << f.readout_sample_number_RAW() << ",";
      std::cout << "\ntime is " << f.readout_sample_number_RAW();
      _ofile << f.readout_frame_number() << ",";
      std::cout << "\nframe is " << f.readout_frame_number();
      std::cout << "\nADCs... \n\n";
      for(const auto& adc : f )	{
	_ofile << adc << ",";
	std::cout << adc << " ";
      }
      _ofile << "0\n";
    }

    _ofile << "=\n";
    std::cout << "\n";
    return true;
  }

  bool Dump::finalize() {
    _ofile.close();
    return true;
  }

}
#endif

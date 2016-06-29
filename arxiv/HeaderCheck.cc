#ifndef HEADERCHECK_CC
#define HEADERCHECK_CC

#include "HeaderCheck.hh"


#include <fstream>

namespace larlight {

  bool HeaderCheck::initialize() {

    _frame_numbers.reserve(1000); // there is usually like 1k events right?
      
    return true;
  }
  
  bool HeaderCheck::analyze(larlight::storage_manager* storage) {

    larlight::event_tpcfifo *event_wf = (event_tpcfifo*)(storage->get_data(DATA::TPCFIFO)); 

    _frame_numbers.emplace_back(event_wf->event_frame_number());

    ofstream ofile;
    ofile.open("loser_decoded.txt");
    
    
    std::cout << "size of event_wf is " << event_wf->size() << "\n";
    std::cout << "\nevent is " << event_wf->event_number();

    ofile << event_wf->event_number() << ",";
    
    for ( const auto& f : *event_wf ) {
      ofile << f.channel_number() << ",";
      std::cout << "\nchannel is " << f.channel_number();
      ofile << f.readout_sample_number_RAW() << ",";
      std::cout << "\ntime is " << f.readout_sample_number_RAW();
      ofile << f.readout_frame_number() << ",";
      std::cout << "\nframe is " << f.readout_frame_number();
      std::cout << "\nADCs... \n\n";
      for(const auto& adc : f )	{
	ofile << adc << ",";
	std::cout << adc << " ";
      }
      ofile << "0\n";
    }

    ofile.close();
      
    return true;
    
  }
    
  bool HeaderCheck::finalize() {

    int prev_frame = -1;
    std::cout << "Checking...\n";
    std::for_each(std::begin(_frame_numbers),
		  std::end(_frame_numbers)-1, //ignore the last one since it's truncated 
		  [&prev_frame](size_t& cf){

		    if ( cf -  prev_frame != 1)
		      { std::cout << "\n pf : " << prev_frame << " cf: " << cf << " diff: " << cf - prev_frame << "\n"; } 

		    std::cout << cf << " ";
		    
		    prev_frame = cf;
		    
		  });
    std::cout << "Checked!\n";
    return true;
  }
  
}

#endif

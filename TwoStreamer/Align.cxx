#ifndef ALIGN_CXX
#define ALIGN_CXX

#include "Align.h"

#include "DataFormat/tpcdetwaveform.h"

namespace larlite {

  bool Align::align_events(storage_manager* sm1, storage_manager* sm2, storage_manager* sm3) {
    
    for(unsigned i=0;i<sm1->get_entries(); ++i){
      
      auto ev_sn_digits = sm1->get_data<event_tpcdetwaveform>("snova");
      auto ev_tr_digits = sm2->get_data<event_tpcdetwaveform>("trig");

      auto fsnova=ev_sn_digits->Frame();
      auto ftrig=ev_tr_digits->Frame();

      int ctr=0;
      
      //same frame requirement
      if ( fsnova == ftrig ) {
	std::cout << "Found alignment on frame : " << fsnova << "\n";
	
	auto ev_sn_digits_out = sm3->get_data<event_tpcdetwaveform>("snova_align");
	auto ev_tr_digits_out = sm3->get_data<event_tpcdetwaveform>("trig_align");
	
	*(ev_sn_digits_out) = *(ev_sn_digits);
	*(ev_tr_digits_out) = *(ev_tr_digits);

	sm3->set_id(1,1,ctr);
	sm3->next_event(true);
	
	ctr++;
	sm2->next_event(false);
      }
      sm1->next_event(false);
    }

    
    
    return true;
  }

  
}
#endif

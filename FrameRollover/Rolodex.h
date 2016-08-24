/**
 * \file Rolodex.h
 *
 * \ingroup FrameRollover
 * 
 * \brief Class def header for a class Rolodex
 *
 * @author vgenty
 */

/** \addtogroup FrameRollover

    @{*/

#ifndef LARLITE_ROLODEX_H
#define LARLITE_ROLODEX_H

#include <deque>
#include "Analysis/ana_base.h"
#include "StitchAlgo.h"

namespace larlite {
  /**
     \class Rolodex
     User custom analysis class made by SHELL_USER_NAME
   */
  class Rolodex : public ana_base {
  
  public:
    
    Rolodex() :
      _event_ctr(-1)
      ,_producer("tpcdigit")
    { _name="Rolodex"; _fout=nullptr;}
    
    virtual ~Rolodex(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

    void SetStitcher(StitchAlgo* sa) { _stitcher = sa; }

    void SetProducer(std::string p)  { _producer = p; }
    
    
  protected:

  private:

    std::deque<event_tpcfifo> _fifoevents;
    
    int _event_ctr;
    
    StitchAlgo* _stitcher;

    std::string _producer;
  };
}
#endif

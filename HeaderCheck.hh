#ifndef HEADERCHECK_HH
#define HEADERCHECK_HH

#include "ana_base.hh"

namespace larlight {

  class HeaderCheck : public larlight::ana_base{
    
  public:
    
    /// Default constructor
    HeaderCheck() { _name="HeaderCheck"; _fout=0;};
    
    /// Default destructor
    virtual ~HeaderCheck(){};
    
    virtual bool initialize();

    virtual bool analyze(larlight::storage_manager* storage);

    virtual bool finalize();

  protected:
  private:
    std::vector<size_t> _frame_numbers;

  };
}

#endif

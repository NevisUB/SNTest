import sys
from ROOT import gSystem
gSystem.Load("libSNTest_tpcdetwaveform")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing tpcdetwaveform..."

sys.exit(0)


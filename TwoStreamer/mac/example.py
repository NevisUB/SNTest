import sys
from ROOT import gSystem
gSystem.Load("libsntest_TwoStreamer")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing TwoStreamer..."

sys.exit(0)


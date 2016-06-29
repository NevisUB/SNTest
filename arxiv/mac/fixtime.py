import sys

if len(sys.argv) < 2:
    msg  = '\n'
    msg += "Usage 1: %s $INPUT_ROOT_FILE\n" % sys.argv[0]
    msg += '\n'
    sys.stderr.write(msg)
    sys.exit(1)


from ROOT import larlight as fmwk
import ROOT

#shit has to be loaded like this
ROOT.gSystem.Load("libBase")
ROOT.gSystem.Load("libDataFormat")
ROOT.gSystem.Load("libSNTest")

# Create ana_processor instance
my_proc = fmwk.ana_processor()
my_proc.set_verbosity(fmwk.MSG.NORMAL)

# Set input root files... need MCShower and shower reco in 1 or many files
for x in xrange(len(sys.argv)):
    if x < 1: continue
    my_proc.add_input_file(sys.argv[x])

# Specify IO mode
my_proc.set_io_mode(fmwk.storage_manager.READ)
#my_proc.set_output_file("aho.root")

# Attach a template process
my_ana= fmwk.SNTimeFix()
my_proc.add_process(my_ana)

my_proc.run()

sys.exit(0)


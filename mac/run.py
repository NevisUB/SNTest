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

# Specify output root file name
my_proc.set_ana_output_file("ahoaho.root");

# Attach a template process
my_ana= fmwk.HeaderCheck()
my_proc.add_process(my_ana)

print
print  "Finished configuring ana_processor. Start event loop!"
print

# Let's run it.
my_proc.run()

# done!
print
print "Finished running ana_processor event loop!"
print

sys.exit(0)

